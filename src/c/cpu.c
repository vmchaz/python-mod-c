#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "vcpu.h"
#include "instructionsequence.h"
#include "field.h"
#include "unitvarstruct.h"


int vcpu_step(VCPU * vcpu, InstructionSequence * sequence, Field * field, UnitVarStruct * u, int maxsteps)
{
    printf("VCPU:%p InstructionSequence:%p Field:%p UnitVarStruct:%p maxsteps:%d\n", vcpu, sequence, field, u, maxsteps);
}
