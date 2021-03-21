#ifndef _CPU_H_
#define _CPU_H_

int vcpu_step(VCPU * vcpu, InstructionSequence * sequence, Field * field, UnitVarStruct * u, int maxsteps);
extern void * InstructionMap[256];

#endif
