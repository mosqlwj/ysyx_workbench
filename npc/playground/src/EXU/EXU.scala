package riscv.EXU
import chisel3._
import chisel3.util._
/**
  * EXU
  */
class EXU extends Module {
  val io = IO(new Bundle {
    val Rdest=Input(UInt(5.W))
    val R1=Input(UInt(5.W))
    val R2=Input(UInt(5.W))
    val Imm=Input(UInt(64.W))
    val RegWrite=Input(UInt(1.W))
    val MemWrite=Input(UInt(1.W))
    val AluOp=Input(UInt(5.W))
    val PcSrc=Input(UInt(5.W))
    val MemToReg=Input(UInt(1.W))
    val MemMask=Input(UInt(8.W))

    val PcVal=Output(UInt(64.W))
  })
  var AluOut = Wire(UInt(64.W));
  val MemOut = Wire(UInt(64.W));
  var DataR1 = Wire(UInt(64.W));
  var DataR2 = Wire(UInt(64.W));
  var registers = Module(new Registers);
  DataR1 := registers.io.DataR1;
  DataR2 := registers.io.DataR2;
  registers.io.R1 := io.R1;
  registers.io.R2 := io.R2;
  registers.io.Rdest := io.Rdest;
  registers.io.RegWrite := io.RegWrite;
  registers.io.DataIn := MuxLookup(io.MemToReg,0.U,Array(
    0.U -> AluOut,
    1.U -> MemOut
  ))

  var mem = Module(new Mem);
  MemOut := mem.io.Rdata;
  mem.io.Raddr := AluOut;
  mem.io.Waddr := AluOut;
  mem.io.Wdata := DataR2;
  mem.io.Wmask := io.MemMask;
  mem.io.MemWrite := io.MemWrite;

  val pc=RegInit("h80000000".U(64.W));
  pc := MuxLookup(io.PcSrc, pc+"h4".U, Array(
    0x0.U -> (pc+"h4".U),
    0x1.U -> (pc.asSInt() + io.Imm(20,0).asSInt()).asUInt(), //jal
    0x2.U -> ((DataR1 + io.Imm) & (~(1.U(64.W)))) //jalr
  ))

  AluOut := MuxLookup(io.AluOp,0.U, Array(
    0x1.U -> (DataR1.asSInt() + io.Imm(11,0).asSInt()).asUInt(), //addi
    0x2.U -> (DataR1.asSInt() + DataR2.asSInt()).asUInt(), //add
    0x3.U -> (pc + io.Imm), //auipc
    0x4.U -> (pc + "h4".U(64.W)), //jal,jalr
    0x5.U -> (DataR1 + io.Imm) //sd
  ))

  io.PcVal := pc;
}
