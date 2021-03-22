#ifndef _VCPU_H_
#define _VCPU_H_
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "instructionsequence.h"
#include "unitvarstruct.h"

typedef struct {
    int id;
    int ip;
    int accumulator;
    int flags;
    int stop_flag;
    int error_flag;
    int ip_mod_flag;
    int set_action_flag;
    int registers[16];
} VCPU;

int vcpu_step(VCPU * vcpu, InstructionSequence * sequence, UnitVarStruct * u);
int vcpu_run(VCPU * vcpu, InstructionSequence * sequence, UnitVarStruct * u, bool stop_on_action, int maxsteps);
int vcpu_init(VCPU * vcpu, int id);
int vcpu_reset(VCPU * vcpu);

#endif
