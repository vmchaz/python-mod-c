#ifndef _INSTRUCTIONSEQUENCE_REPR_H_
#define _INSTRUCTIONSEQUENCE_REPR_H_

#include <Python.h>
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <structmember.h>

#include "instructionsequence.h"


#ifdef	__cplusplus
extern "C" {
#endif

extern PyTypeObject InstructionSequence_Repr_Type;

#ifdef	__cplusplus
}
#endif

typedef struct {
    PyObject_HEAD // Макрос объявления нового типа, объекта фиксированного размера
    InstructionSequence sequence;
} InstructionSequence_Repr;

#endif
