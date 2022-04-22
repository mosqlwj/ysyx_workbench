package riscv.IFU
import chisel3._
import chisel3.util._
import riscv.EXU.Mem
/**
  * IFU
  */
class IFU extends Module {
  val io = IO(new Bundle {
    val Pc=Input(UInt(64.W))
    val Inst=Output(UInt(32.W))
  })

  var mem=Module(new Mem);
  mem.io.Raddr := io.Pc;
  io.Inst := mem.io.Rdata(31,0);
  mem.io.Waddr := "h0".U(64.W);
  mem.io.MemWrite := "h0".U(64.W);
  mem.io.Wdata := "h0".U(64.W);
  mem.io.Wmask := "h0".U(64.W);
}
