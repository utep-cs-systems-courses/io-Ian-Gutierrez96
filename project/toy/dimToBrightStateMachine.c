#include "led.h"
#include "buzzer.h"
#include <msp430.h>

void advance_dim_to_bright_state_machine() {
 static int blinkLimit = 0;
 static int blinkCount = 0;
 static int secondCount = 0;
 static int blinkLimit2 = 8;
 static int blinkCount2 = 0;

  blinkCount++;
  blinkCount2++;

  if (blinkCount >= blinkLimit) {
    blinkCount = 0;
    toggle_green(1);
  } else {
    toggle_green(0);
  }

  if (blinkCount2 >= blinkLimit2) {
    blinkCount2 = 0;
    toggle_red(1);
  } else {
    toggle_red(0);
  }

  secondCount++;
  if (secondCount >= 250) {
    secondCount = 0;
    blinkLimit++;
    blinkLimit2--;

    if (blinkLimit >= 8) {
      blinkLimit = 0;
    }

    if (blinkLimit2 <= 0) {
      blinkLimit2 = 8;
    }
  }
}

void stop_dim_to_bright_state_machine() {
  toggle_green(0);
  toggle_red(0);
  buzzer_set_period(0);
}
