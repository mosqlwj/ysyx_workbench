import chisel3._
import chisel3.util._

/**
  * pc
  */
class Pc extends Module {
  val io = IO(new Bundle {
    //val Branch=Input(Bool())
    //val Zero=Input(Bool())
    val PcSrc=Input(UInt(5.W))
    val DataImmI=Input(UInt(64.W))
    val DataImmJ=Input(UInt(64.W))
    val DataR1=Input(UInt(64.W))
    val PcVal=Output(UInt(64.W))
    val Inst=Output(UInt(32.W))
  })
  val pc=RegInit("h80000000".U(64.W))

  var mem=Module(new Mem);
  mem.io.Raddr := pc;
  io.Inst := mem.io.Rdata(31,0);
  mem.io.Waddr := "h0".U(64.W);
  mem.io.MemWrite := "h0".U(64.W);
  mem.io.Wdata := "h0".U(64.W);
  mem.io.Wmask := "h0".U(64.W);
  
  pc := MuxLookup(io.PcSrc, pc+"h4".U, Array(
    0x1.U -> (pc.asSInt() + io.DataImmJ(20,0).asSInt()).asUInt(), //jal
    0x2.U -> ((io.DataR1 + io.DataImmI) & (~(1.U(64.W)))) //jalr
  ))

  io.PcVal := pc;
}
