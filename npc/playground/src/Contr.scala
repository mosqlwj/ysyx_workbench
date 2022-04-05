import chisel3._
import chisel3.util._
/**
  * decode the inst and get the control
  */
class Contr extends Module {
  val io = IO(new Bundle {
    val Inst= Input(UInt(32.W))
    val RegWrite=Output(Bool())
    //val MemRead=Output(Bool())
    //val MemWrite=Output(Bool())
    val AluOp=Output(UInt(4.W))
    val AluSrc=Output(Bool())
    //val Branch=Output(Bool())
  })

  val opcode = io.Inst(6,0);
  io.RegWrite := MuxLookup(opcode,false.B,Array("h13".U -> true.B));
  io.AluOp := MuxLookup(opcode,0x0.U(5.W),Array("h13".U -> 0x1.U(4.W)));
  io.AluSrc := MuxLookup(opcode,false.B,Array("h13".U -> true.B));
}
