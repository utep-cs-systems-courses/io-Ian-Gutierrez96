#include <msp430.h>
#include "stateMachine.h"
#include "sirenStateMachine.h"
#include "dimToBrightStateMachine.h"
#include "brightToDimStateMachine.h"


static State current_state;



void set_state(State state)

{

  switch (state) {

  case SIREN:
    stop_dim_to_bright_state_machine();
    stop_bright_to_dim_state_machine();
    break;

  case DIMTOBRIGHT:
    stop_siren();
    stop_bright_to_dim_state_machine();
    break;

  case BRIGHTTODIM:
    stop_siren();
    stop_dim_to_bright_state_machine();

  }



  current_state = state;

}

void advance_state()
{
  switch (current_state) {
  case SIREN:
    advance_siren();
    break;

  case DIMTOBRIGHT:
    advance_dim_to_bright_state_machine();
    break;

  case BRIGHTTODIM:
    advance_bright_to_dim_state_machine();
    break;
  }
}
