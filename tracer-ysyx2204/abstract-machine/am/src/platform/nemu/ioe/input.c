#include <am.h>
#include <nemu.h>
#include <stdio.h>
#define KEYDOWN_MASK 0x8000
#define KEY_QUEUE_LEN 1024
bool is_down[256] = {0};
void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd)
{
  int keycode = inl(KBD_ADDR) % KEY_QUEUE_LEN;
  if (keycode == AM_KEY_NONE)
  {
    kbd->keydown = false;
    kbd->keycode = AM_KEY_NONE;
  }
  else
  {
    if (is_down[keycode])
      kbd->keydown = false;
    else
      kbd->keydown = true;
    is_down[keycode] = !is_down[keycode];
    kbd->keycode = keycode;
  }
}
