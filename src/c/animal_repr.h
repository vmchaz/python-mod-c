#ifndef _ANIMAL_REPR_H_
#define _ANIMAL_REPR_H_
    
#include <Python.h>
#include <structmember.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "animal.h"
#include "instructionsequence.h"
#include "unitvarstruct.h"

extern PyTypeObject Animal_Repr_Type;

typedef struct {
    PyObject_HEAD
    Animal animal;
} Animal_Repr;

#endif
