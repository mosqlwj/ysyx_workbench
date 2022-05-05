#include <isa.h>
#include <memory/host.h>
#include <memory/vaddr.h>
#include <device/map.h>

#define IO_SPACE_MAX (2 * 1024 * 1024)

static uint8_t *io_space = NULL;
static uint8_t *p_space = NULL;
#ifdef CONFIG_DTRACE_COND
char dtrace_buf[16][100]={0};
int dtrace_count=0;
#endif

#ifdef CONFIG_DTRACE_COND
void print_dtrace()
{
  printf("dtrace:\n");
  for(int i=0;i<16;i++)
  {
    if(strlen(dtrace_buf[i])==0)
      break;
    if((i+1)%16==dtrace_count)
      printf("-->");
    else
      printf("   ");
    printf("%s\n",dtrace_buf[i]);
  }
}
#endif

uint8_t* new_space(int size) {
  uint8_t *p = p_space;
  // page aligned;
  size = (size + (PAGE_SIZE - 1)) & ~PAGE_MASK;
  p_space += size;
  assert(p_space - io_space < IO_SPACE_MAX);
  return p;
}

static void check_bound(IOMap *map, paddr_t addr) {
  if (map == NULL) {
    Assert(map != NULL, "address (" FMT_PADDR ") is out of bound at pc = " FMT_WORD, addr, cpu.pc);
  } else {
    Assert(addr <= map->high && addr >= map->low,
        "address (" FMT_PADDR ") is out of bound {%s} [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
        addr, map->name, map->low, map->high, cpu.pc);
  }
}

static void invoke_callback(io_callback_t c, paddr_t offset, int len, bool is_write) {
  if (c != NULL) { c(offset, len, is_write); }
}

void init_map() {
  io_space = malloc(IO_SPACE_MAX);
  assert(io_space);
  p_space = io_space;
}

word_t map_read(paddr_t addr, int len, IOMap *map) {
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  invoke_callback(map->callback, offset, len, false); // prepare data to read
  word_t ret = host_read(map->space + offset, len);
#ifdef CONFIG_DTRACE_COND
  sprintf(dtrace_buf[dtrace_count],"read: addr:%016x len:%02d name=%s content:%016lx",addr,len,map->name,ret);
  dtrace_count=(dtrace_count+1)%16;
#endif
  return ret;
}

void map_write(paddr_t addr, int len, word_t data, IOMap *map) {
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  host_write(map->space + offset, len, data);
#ifdef CONFIG_DTRACE_COND
  sprintf(dtrace_buf[dtrace_count],"write:addr:%016x len:%02d name=%s content:%016lx",addr,len,map->name,data);
  dtrace_count=(dtrace_count+1)%16;
#endif
  invoke_callback(map->callback, offset, len, true);
}
