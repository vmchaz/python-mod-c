#ifndef _INSTRUCTIONSEQUENCE_H_
#define _INSTRUCTIONSEQUENCE_H_

#include <Python.h>
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <structmember.h>


#ifdef	__cplusplus
extern "C" {
#endif

extern PyTypeObject InstructionSequence_Type;

#ifdef	__cplusplus
}
#endif

typedef struct Instruction_s Instruction;

struct Instruction_s {
    int cmd;
    int reg_src;
    int reg_dest;
    int imm;
    int flags_allow;
    int flags_deny;    
    int flags_target;
};

typedef struct InstructionSequence_s InstructionSequence;

struct InstructionSequence_s {
    PyObject_HEAD // Макрос объявления нового типа, объекта фиксированного размера
    int count;
    Instruction instructions[256];
};

#endif
