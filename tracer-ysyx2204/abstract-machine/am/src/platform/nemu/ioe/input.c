#include <am.h>
#include <nemu.h>
#include <stdio.h>
#define KEYDOWN_MASK 0x8000
int last_keycode = 0;
void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd)
{
  int keycode = inl(KBD_ADDR) % 256;
  if (keycode == AM_KEY_NONE)
  {
    kbd->keydown = false;
    kbd->keycode = last_keycode;
  }
  else
  {
    kbd->keydown = true;
    kbd->keycode = keycode;
  }
  last_keycode = keycode;
}
