#include "npc.h"

CPU_state cpu_npc;
vluint64_t sim_time = 0;
VMain *top = nullptr;
VerilatedContext *contextp = nullptr;
long img_size = 0;
char *img_file = nullptr;
#ifdef CONFIG_VCD
VerilatedVcdC *m_trace = nullptr;
#endif

int check_regs_npc(CPU_state ref_cpu);
void init_so(char *ref_so_file, long img_size);
long ld(char *img_file);

void exit_npc(int flag)
{
#ifdef CONFIG_VCD
  m_trace->close();
#endif
  delete top;
  delete contextp;
  exit(flag);
}

void cpu_sim_once()
{
  top->clock = 0, top->eval();
  top->clock = 1, top->eval();
}

void init_npc()
{
  top->reset = 1;
  for (int i = 1; i <= 10; i++)
    cpu_sim_once();
  top->reset = 0;
}

void exec_once()
{
  cpu_sim_once();
#ifdef CONFIG_VCD
  m_trace->dump(sim_time++);
#endif
#ifdef CONFIG_DIFFTEST
  assert(ref_difftest_exec);
  ref_difftest_exec(1);
  CPU_state ref_cpu;
  ref_difftest_regcpy(&ref_cpu, DIFFTEST_TO_DUT);
  printf("check at nemu_pc=%lx, npc_pc=%lx\n", cpu_npc.pc, ref_cpu.pc);
  if (!check_regs_npc(ref_cpu))
    exit_npc(-1);
#endif
}
static int parse_args(int argc, char *argv[])
{
  if (argc == 2)
  {
    if (strlen(argv[1]) != 0)
    {
      img_file = argv[1];
      img_size = ld(img_file);
    }
  }
  return 0;
}
int main(int argc, char **argv, char **env)
{
  parse_args(argc, argv);

#ifdef CONFIG_VCD
  Verilated::traceEverOn(true);
  m_trace = new VerilatedVcdC;
  top->trace(m_trace, 5);
  m_trace->open("waveform.vcd");
#endif
  contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  top = new VMain{contextp};
  init_npc();

#ifdef CONFIG_DIFFTEST
  init_so("/home/wcx/Desktop/ysyx-workbench/nemu/build/riscv64-nemu-interpreter-so", img_size);
#endif
  while (1)
  {
    exec_once();
  }

  exit_npc(0);
  return 0;
}
