import chisel3._

/**
  * decode the inst and get the control
  */
class Decode extends Module {
  val io = IO(new Bundle {
    val Inst= Input(UInt(32.W))
    val Rdest=Output(UInt(5.W))
    val R1=Output(UInt(5.W))
    val R2=Output(UInt(5.W))
    val ImmI=Output(UInt(64.W))
    //val ImmJ=Output(UInt(64.W))
    //val ImmU=Output(UInt(64.W))
    //val ImmS=Output(UInt(64.W))
    //val ImmB=Output(UInt(64.W))
  })
  io.Rdest := io.Inst(11,7)
  io.R1 := io.Inst(19,15)
  io.R2 := io.Inst(24,20)
  io.ImmI := io.Inst(31,20)
}
