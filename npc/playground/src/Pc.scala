import chisel3._

/**
  * add
  */
class Pc extends Module {
  val io = IO(new Bundle {
    //val PcIn= Input(UInt(64.W))
    //val Branch=Input(Bool())
    //val Zero=Input(Bool())
    val PcVal=Output(UInt(64.W))
  })
  val pc=RegInit("h80000000".U(64.W))
  pc := pc + "h4".U(64.W);
  io.PcVal := pc;
}
