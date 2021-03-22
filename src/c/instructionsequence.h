#ifndef _INSTRUCTIONSEQUENCE_H_
#define _INSTRUCTIONSEQUENCE_H_
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MaxInstructions 256

typedef struct {
    int cmd;
    int reg_src;
    int reg_dest;
    int imm;
    int flags_allow;
    int flags_deny;    
    int flags_target;
} Instruction;

typedef struct {
    int count;
    Instruction instructions[MaxInstructions];
} InstructionSequence;

#endif
