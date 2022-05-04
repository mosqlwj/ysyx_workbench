#include <am.h>
#include <nemu.h>
#include <stdio.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)
int width, height;
void __am_gpu_init() {
  int i;
  uint32_t vga_ctl = inl(VGACTL_ADDR);
  width= (vga_ctl>>16);  // TODO: get the correct width
  height = (vga_ctl)&((1<<16)-1);  // TODO: get the correct height
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  for (i = 0; i < width * height; i ++) fb[i] = i;
  outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = width, .height = height,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  if (ctl->sync) {
    uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
    printf("xy %d %d\n",ctl->x,ctl->y);
    printf("wh %d %d\n",ctl->w,ctl->h);
    int cnt=0;
    for (int i = 0; i < ctl->w; i ++){
      for(int j = 0; j < ctl->h ; j ++){
        int p = ctl->x + i;
        int q = ctl->y + j;
        fb[p * width + q] = ((uint32_t*)ctl->pixels)[++cnt];
      }
    }
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
