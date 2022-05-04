#include <am.h>
#include <nemu.h>
#include <stdio.h>
#define KEYDOWN_MASK 0x8000
#define KEY_QUEUE_LEN 1024

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd)
{
  uint32_t key = inl(KBD_ADDR);
  int keycode = key % KEY_QUEUE_LEN;
  int keydown = key & KEYDOWN_MASK;
  if (keycode == AM_KEY_NONE)
  {
    kbd->keydown = false;
    kbd->keycode = AM_KEY_NONE;
  }
  else
  {
    if (keydown != 0)
      kbd->keydown = true;
    else
      kbd->keydown = false;
    kbd->keycode = keycode;
  }
}
