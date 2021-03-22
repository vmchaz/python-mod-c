#ifndef _UNITVARSTRUCT_REPR_H_
#define _UNITVARSTRUCT_REPR_H_

#include <Python.h>
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <structmember.h>
#include "unitvarstruct.h"


#ifdef	__cplusplus
extern "C" {
#endif

extern PyTypeObject UnitVarStruct_Repr_Type;

#ifdef	__cplusplus
}
#endif

typedef struct {
    PyObject_HEAD // Макрос объявления нового типа, объекта фиксированного размера
    UnitVarStruct unitvarstruct;
    
} UnitVarStruct_Repr;

#endif
