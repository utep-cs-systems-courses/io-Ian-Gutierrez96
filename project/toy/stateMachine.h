#ifndef stateMachine_included
#define stateMachine_included



typedef enum {
  SIREN,

} State;

void set_state(State state);
void advance_state();

#endif
