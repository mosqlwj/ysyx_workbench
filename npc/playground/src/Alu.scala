import chisel3._
import chisel3.util._

/**
  * alu
  */
class Alu extends Module {
  val io = IO(new Bundle {
    val DataR1=Input(UInt(64.W))
    val DataR2=Input(UInt(64.W))
    val DataImm=Input(UInt(64.W))
    val AluOp=Input(UInt(5.W))
    val AluSrc=Input(Bool())
    //val Zero=Output(Bool())
    val AluOut=Output(UInt(64.W))
  })
  
  val DataIn = MuxLookup(io.AluSrc, 0.U, Array(true.B -> io.DataR2, false.B -> io.DataImm));
  io.AluOut := MuxLookup(io.AluOp,0.U, Array(0x1.U -> (io.DataR1.asSInt() + DataIn.asSInt()).asUInt()));
}
