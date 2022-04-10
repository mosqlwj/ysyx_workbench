import chisel3._
import chisel3.util._
/**
  * decode the inst and get the control
  */
class Contr extends Module {
  val io = IO(new Bundle {
    val Inst= Input(UInt(32.W))
    val RegWrite=Output(Bool())
    val MemWrite=Output(Bool())
    val AluOp=Output(UInt(5.W))
    val PcSrc=Output(UInt(5.W))
    val MemToReg=Output(Bool())
    val MemMask=Output(UInt(8.W))
  })

  val ebreak_in=Wire(UInt(1.W));
  var ebreak=Module(new Ebreak);
  ebreak_in := MuxLookup(io.Inst,0.U,Array("h00100073".U -> 1.U));
  ebreak.io.ebreak_in := ebreak_in;

  val opcode = io.Inst(6,0);
  io.RegWrite := MuxLookup(opcode,false.B,Array(
  	"h13".U -> true.B, //addi
  	"h17".U -> true.B, //auipc
  	"h6f".U -> true.B, //jal
  	"h67".U -> true.B, //jalr
  	"h23".U -> true.B  //sd
  	));
  io.AluOp := MuxLookup(opcode,0x0.U(5.W),Array(
  	"h13".U -> 0x1.U, //addi
  	"h17".U -> 0x2.U, //auipc
  	"h6f".U -> 0x3.U, //jal
  	"h67".U -> 0x3.U, //jalr
  	"h23".U -> 0x4.U  //sd
  	));
  io.MemWrite := MuxLookup(opcode,false.B,Array(
    "h23".U -> true.B //sd
    ));
  io.MemToReg := MuxLookup(opcode,false.B,Array(
    "h23".U -> true.B //sd
    ));
  io.MemMask := MuxLookup(opcode,0.U,Array(
    "h23".U -> 0xff.U //sd
    ));
  io.PcSrc := MuxLookup(opcode,0x0.U,Array(
    "h6f".U -> 0x1.U, //jal
    "h67".U -> 0x2.U  //jalr
    ));
}
