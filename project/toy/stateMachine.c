#include <msp430.h>
#include "stateMachine.h"
#include "sirenStateMachine.h"


static State current_state;



void set_state(State state)

{

  switch (state) {

  case SIREN:

    if (current_state != SIREN) {


    }

    break;

  }



  current_state = state;

}

void advance_state()
{
  switch (current_state) {
  case SIREN:
    advance_siren();
  }
}
