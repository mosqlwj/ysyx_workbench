#include <am.h>
#include <nemu.h>
#include <stdio.h>
#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  printf("%lx\n",inl(KBD_ADDR));
  kbd->keydown = 0;
  kbd->keycode = AM_KEY_NONE;
}
