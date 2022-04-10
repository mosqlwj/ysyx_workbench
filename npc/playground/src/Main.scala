import chisel3._

/**
  * Main
  */
class Main extends Module {
  val io = IO(new Bundle {
    val Inst=Output(UInt(32.W))
    val PcVal=Output(UInt(64.W))
    val RegWrite = Output(Bool())
    val AluOp = Output(UInt(5.W))
    val R1 = Output(UInt(5.W))
    val R2 = Output(UInt(5.W))
    val Rdest = Output(UInt(5.W))
    val AluOut = Output(UInt(64.W))
    val DataR1 = Output(UInt(64.W))
    val DataR2 = Output(UInt(64.W))
    val DataImmI = Output(UInt(64.W))
    val DataImmJ = Output(UInt(64.W))
    val DataImmU = Output(UInt(64.W))
    val DataImmS = Output(UInt(64.W))
    val PcSrc = Output(UInt(5.W))
    val MemWrite = Output(Bool())
    val MemToReg = Output(Bool())
    val MemOut = Output(UInt(64.W))
    val MemMask = Output(UInt(8.W))
    //val MemRead = Output(Bool())
    //val Branch = Output(Bool())
  })

  val pc=Module(new Pc());
  io.Inst := pc.io.Inst;
  io.PcVal := pc.io.PcVal; 
  pc.io.DataR1 := io.DataR1;
  pc.io.DataImmI := io.DataImmI;
  pc.io.DataImmJ := io.DataImmJ;
  pc.io.PcSrc := io.PcSrc;
  
  val contr=Module(new Contr())
  contr.io.Inst := io.Inst;
  io.RegWrite := contr.io.RegWrite;
  io.MemWrite := contr.io.MemWrite;
  io.AluOp := contr.io.AluOp;
  io.PcSrc := contr.io.PcSrc;
  io.MemToReg := contr.io.MemToReg;
  io.MemMask := contr.io.MemMask;

  val decode=Module(new Decode())
  decode.io.Inst := io.Inst;
  io.R1 := decode.io.R1;
  io.R2 := decode.io.R2;
  io.Rdest := decode.io.Rdest;
  io.DataImmI := decode.io.ImmI;
  io.DataImmU := decode.io.ImmU;
  io.DataImmS := decode.io.ImmS;
  io.DataImmJ := decode.io.ImmJ;

  val registers = Module(new Registers())
  registers.io.R1 := io.R1;
  registers.io.R2 := io.R2;
  registers.io.Rdest := io.Rdest;
  registers.io.RegWrite := io.RegWrite;
  registers.io.MemToReg := io.MemToReg;
  registers.io.AluOut := io.AluOut;
  registers.io.MemOut := io.MemOut;
  io.DataR1 := registers.io.DataR1;
  io.DataR2 := registers.io.DataR2;

  val alu = Module(new Alu())
  alu.io.DataR1 := io.DataR1;
  alu.io.DataR2 := io.DataR2;
  alu.io.AluOp := io.AluOp;
  alu.io.DataImmI := io.DataImmI;
  alu.io.DataImmS := io.DataImmS;
  alu.io.DataImmU := io.DataImmU;
  alu.io.PcVal := io.PcVal;
  io.AluOut := alu.io.AluOut;

  val mem = Module(new Mem())
  mem.io.Raddr := io.AluOut;
  io.MemOut := mem.io.Rdata;
  mem.io.Waddr := io.AluOut;
  mem.io.Wdata := io.DataR2;
  mem.io.MemWrite := io.MemWrite;
  mem.io.Wmask := io.MemMask;
}
