#ifndef stateMachine_included
#define stateMachine_included



typedef enum {
  SIREN = 1,
  DIMTOBRIGHT = 2,
  BRIGHTTODIM = 3,

} State;

void set_state(State state);
void advance_state();

#endif
