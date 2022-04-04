import chisel3._

/**
  * Compute add using subtraction method.
  * Subtracts the smaller from the larger until register y is zero.
  * value in register x is then the GCD
  */
class add extends Module {
  val io = IO(new Bundle {
    val value1        = Input(UInt(64.W))
    val value2        = Input(UInt(64.W))
    val output     = Output(UInt(64.W))
  })

  io.output := io.value1 + io.value2;
}
