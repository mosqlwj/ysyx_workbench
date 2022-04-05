import chisel3._
import chisel3.util._
/**
  * ebreak
  */
class EbreakBox extends HasBlackBoxInline {
  val io = IO(new Bundle {
    var ebreak_in=Input(UInt(1.W))
  } ) 
    setInline("EbreakBox.v",
    s"""
    | import \"DPI-C\" function void ebreak();
    | module EbreakBox (ebreak_in);
    | input ebreak_in;
    | always @(*)
    | begin
    | if(ebreak_in==1'b1)
    |   ebreak();
    | end
    | endmodule
    """.stripMargin)
}
