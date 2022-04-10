import chisel3._
import chisel3.util._

/**
  * Registers
  */
class Registers extends Module {
  val io = IO(new Bundle {
    val Rdest=Input(UInt(5.W))
    val R1=Input(UInt(5.W))
    val R2=Input(UInt(5.W))
    val RegWrite=Input(Bool())
    val MemToReg=Input(Bool())
    val AluOut=Input(UInt(64.W))
    val MemOut=Input(UInt(64.W))
    val DataR1=Output(UInt(64.W))
    val DataR2=Output(UInt(64.W))
  })

  val Regs = RegInit(VecInit(Seq.fill(32)(0.U(32.W))))

  io.DataR1 := Regs(io.R1)
  io.DataR2 := Regs(io.R2)
  
  when(io.RegWrite)
  {
    Regs(io.Rdest) := MuxLookup(io.MemToReg,io.AluOut,Array(true.B -> io.MemOut, false.B -> io.AluOut));
  }
  
}
