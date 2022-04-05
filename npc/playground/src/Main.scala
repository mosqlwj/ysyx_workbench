import chisel3._

/**
  * Main
  */
class Main extends Module {
  val io = IO(new Bundle {
    val Inst=Input(UInt(32.W))
    val PcVal=Output(UInt(64.W))
    val RegWrite = Output(Bool())
    val AluOp = Output(UInt(5.W))
    val AluSrc = Output(Bool())
    val R1 = Output(UInt(5.W))
    val R2 = Output(UInt(5.W))
    val Rdest = Output(UInt(5.W))
    val AluOut = Output(UInt(64.W))
    val DataR1 = Output(UInt(64.W))
    val DataR2 = Output(UInt(64.W))
    val DataImmI = Output(UInt(64.W))
    //val MemRead = Output(Bool())
    //val MemWrite = Output(Bool())
    //val Branch = Output(Bool())
  })



  val pc=Module(new Pc());
  io.PcVal := pc.io.PcVal; 

  val contr=Module(new Contr())
  contr.io.Inst := io.Inst;
  io.RegWrite := contr.io.RegWrite;
  io.AluOp := contr.io.AluOp;
  io.AluSrc := contr.io.AluSrc;

  val decode=Module(new Decode())
  decode.io.Inst := io.Inst;
  io.R1 := decode.io.R1;
  io.R2 := decode.io.R2;
  io.Rdest := decode.io.Rdest;
  io.DataImmI := decode.io.ImmI;

  val registers = Module(new Registers())
  registers.io.R1 := io.R1;
  registers.io.R2 := io.R2;
  registers.io.Rdest := io.Rdest;
  registers.io.RegWrite := io.RegWrite;
  registers.io.AluOut := io.AluOut;
  io.AluOut := registers.io.AluOut;
  io.DataR1 := registers.io.DataR1;
  io.DataR2 := registers.io.DataR2;

  val alu = Module(new Alu())
  alu.io.DataR1 := io.DataR1;
  alu.io.DataR2 := io.DataR2;
  alu.io.AluOp := io.AluOp;
  alu.io.DataImm := io.DataImmI;
  alu.io.AluSrc := io.AluSrc;
  io.AluOut := alu.io.AluOut;
}
