package riscv.IDU
import chisel3._
import chisel3.util._

/**
  * IDU
  */
class IDU extends Module {
  val io = IO(new Bundle {
    val Inst= Input(UInt(32.W))
    val RegWrite=Output(UInt(1.W))
    val MemWrite=Output(UInt(1.W))
    val AluOp=Output(UInt(5.W))
    val PcSrc=Output(UInt(5.W))
    val MemToReg=Output(UInt(1.W))
    val MemMask=Output(UInt(8.W))

    val Rdest=Output(UInt(5.W))
    val R1=Output(UInt(5.W))
    val R2=Output(UInt(5.W))
    val Imm=Output(UInt(64.W))
  })
  io.Rdest := io.Inst(11,7)
  io.R1 := io.Inst(19,15)
  io.R2 := io.Inst(24,20)

  val ImmI=Wire(UInt(64.W));
  var ImmS=Wire(UInt(64.W));
  var ImmJ=Wire(UInt(64.W));
  var ImmU=Wire(UInt(64.W));
  val ImmB=Wire(UInt(64.W));

  ImmI := io.Inst(31,20);
  ImmS := (io.Inst(31,25)<<5) | io.Inst(11,7);
  ImmB := (io.Inst(31,31)<<12) | (io.Inst(30,25)<<5) | (io.Inst(11,8)<<1) | (io.Inst(7,7)<<11);
  ImmU := (io.Inst(31,12)<<12);
  ImmJ := (io.Inst(31,31)<<20) | (io.Inst(30,21)<<1) | (io.Inst(20,20)<<11) | (io.Inst(19,12)<<12);

  val ebreak_in=Wire(UInt(1.W));
  var ebreak=Module(new Ebreak);
  ebreak_in := MuxLookup(io.Inst,0.U,Array("h00100073".U -> 1.U));
  ebreak.io.ebreak_in := ebreak_in;

  val opcode = io.Inst(6,0);
  var inst_type = Wire(UInt(3.W)); //0 -> R, 1 -> I, 2 -> S, 3 -> B, 4 -> U, 5 -> J
  var inst_flag = Wire(UInt(17.W));
  var contr_code = Wire(UInt(21.W));

  inst_type := MuxLookup(opcode,0.U,Array(
    "b00100_11".U -> 1.U, //addi
    "b01100_11".U -> 0.U, //add
    "b00101_11".U -> 4.U, //auipc
    "b11011_11".U -> 5.U, //jal
    "b11001_11".U -> 1.U //jalr
  ))

  io.Imm := MuxLookup(inst_type,0.U,Array(
    1.U -> ImmI,
    2.U -> ImmS,
    3.U -> ImmB,
    4.U -> ImmU,
    5.U -> ImmJ
  ))

  inst_flag := MuxLookup(inst_type,0.U,Array(
    0.U -> ((io.Inst(31,25)<<10) | (io.Inst(14,12)<<7) | (io.Inst(6,0))),
    1.U -> ((io.Inst(14,12)<<7) | (io.Inst(6,0))),
    2.U -> ((io.Inst(14,12)<<7) | (io.Inst(6,0))),
    3.U -> ((io.Inst(14,12)<<7) | (io.Inst(6,0))),
    4.U -> (io.Inst(6,0)),
    5.U -> (io.Inst(6,0))
  ))

  //RegWrite 1 MemWrite 1 AluOp 5 PcSrc 5 MemToReg 1 MemMask 8
  contr_code := MuxLookup(inst_flag,0.U,Array(
    "b0000000_000_00100_11".U -> "b1_0_00001_00000_0_00000000".U, //addi
    "b0000000_000_00100_11".U -> "b1_0_00010_00000_0_00000000".U, //add
    "b0000000_000_00101_11".U -> "b1_0_00011_00000_0_00000000".U, //auipc
    "b0000000_000_11011_11".U -> "b1_0_00100_00001_0_00000000".U, //jal
    "b0000000_000_11001_11".U -> "b1_0_00100_00010_0_00000000".U //jalr
  ))

  io.RegWrite := contr_code(20,20);
  io.MemWrite := contr_code(19,19);
  io.AluOp := contr_code(18,14);
  io.PcSrc := contr_code(13,9);
  io.MemToReg := contr_code(8,8);
  io.MemMask := contr_code(7,0);
}
