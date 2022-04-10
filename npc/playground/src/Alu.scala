import chisel3._
import chisel3.util._

/**
  * alu
  */
class Alu extends Module {
  val io = IO(new Bundle {
    val DataR1=Input(UInt(64.W))
    val DataR2=Input(UInt(64.W))
    val DataImmI=Input(UInt(64.W))
    val DataImmS=Input(UInt(64.W))
    val DataImmU=Input(UInt(64.W))
    val PcVal=Input(UInt(64.W))
    val AluOp=Input(UInt(5.W))
    val AluOut=Output(UInt(64.W))
  })
  
  io.AluOut := MuxLookup(io.AluOp,0.U, Array(
    0x1.U -> (io.DataR1.asSInt() + io.DataImmI.asSInt()).asUInt(), //addi
    0x2.U -> (io.PcVal + io.DataImmU), //auipc
    0x3.U -> (io.PcVal + "h4".U(64.W)), //jal,jalr
    0x4.U -> (io.DataR1 + io.DataImmS) //sd
  ));
}
