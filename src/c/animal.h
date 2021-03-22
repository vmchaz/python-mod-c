#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <Python.h>
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <structmember.h>

#include "vcpu.h"
#include "instructionsequence.h"
#include "unitvarstruct.h"


#ifdef	__cplusplus
extern "C" {
#endif

extern PyTypeObject Animal_Type;

#ifdef	__cplusplus
}
#endif

//typedef struct Animal_s Animal;

typedef struct {
    PyObject_HEAD // Макрос объявления нового типа, объекта фиксированного размера
    int thread_count;
    VCPU * vcpus[16];
    InstructionSequence * sequences[16];
    UnitVarStruct * v;
} Animal;

#endif
