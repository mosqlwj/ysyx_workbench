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
    val RinCtl=Input(UInt(3.W))
    val MemMask=Input(UInt(8.W))

    val PcVal=Output(UInt(64.W))
  })
  var AluOut = Wire(UInt(64.W));
  var MemOut = Wire(UInt(64.W));
  var DataR1 = Wire(UInt(64.W));
  var DataR2 = Wire(UInt(64.W));
  var DataIn = Wire(UInt(64.W));
  var Regs = RegInit(VecInit(Seq.fill(32)(0.U(64.W)) :+ ("h80000000".U(64.W)))); // pc == Regs[32]
  var mem = Module(new Mem);
  var pc = Wire(UInt(64.W));

  pc := Regs(32);

  DataR1 := Regs(io.R1);
  DataR2 := Regs(io.R2);
  DataIn := MuxLookup(io.RinCtl,0.U,Array(
    0x0.U -> AluOut,
    0x1.U -> MemOut,
    0x2.U -> (MemOut(31,0).asSInt()).asUInt(),
    0x3.U -> (AluOut(31,0).asSInt()).asUInt()
  ));
  when(io.RegWrite.asBool)
  {
    Regs(io.Rdest) := DataIn;
  };
  
  MemOut := mem.io.Rdata;
  mem.io.Raddr := AluOut;
  mem.io.Waddr := AluOut;
  mem.io.Wdata := DataR2;
  mem.io.Wmask := io.MemMask;
  mem.io.MemWrite := io.MemWrite;

  Regs(32) := MuxLookup(io.PcSrc, pc+"h4".U, Array(
    0x0.U -> (pc+"h4".U),
    0x1.U -> (pc.asSInt() + io.Imm(20,0).asSInt()).asUInt(), //jal
    0x2.U -> ((DataR1 + io.Imm) & (~(1.U(64.W)))), //jalr
    0x3.U -> MuxLookup(AluOut, pc+"h4".U, Array(
      1.U -> (pc.asSInt() + io.Imm(12,0).asSInt()).asUInt()
      ))
  ));

  AluOut := MuxLookup(io.AluOp,0.U, Array(
    0x1.U -> (DataR1.asSInt() + io.Imm(11,0).asSInt()).asUInt(), //addi,ld,sd
    0x2.U -> (DataR1.asSInt() + DataR2.asSInt()).asUInt(), //add
    0x3.U -> (pc + io.Imm), //auipc
    0x4.U -> (pc + "h4".U(64.W)), //jal,jalr
    0x5.U -> ((DataR1 === DataR2).asUInt()) //beq
  ));

  io.PcVal := pc;
}
