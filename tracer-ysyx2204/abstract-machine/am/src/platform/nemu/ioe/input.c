#include <am.h>
#include <nemu.h>
#include <stdio.h>
#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd)
{
  uint32_t keycode = inl(KBD_ADDR);
  if (keycode == AM_KEY_NONE)
  {
    kbd->keydown = 0;
    kbd->keycode = AM_KEY_NONE;
  }
  else
  {
    kbd->keydown = 1;
    kbd->keycode = keycode;
  }
}
