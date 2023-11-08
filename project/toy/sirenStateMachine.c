#include "led.h"
#include "buzzer.h"
#include <msp430.h>



void advance_siren() {
  static unsigned char count = 0;

  if (count < 125) {
    toggle_green(1);
    toggle_red(0);
    buzzer_set_period(250);
  } else if (count < 250) {
    toggle_green(0);
    toggle_red(1);
    buzzer_set_period(1000);
  } else {
    count = 0;
  }
  count++;

}
