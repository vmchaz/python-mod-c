#ifndef _VCPU_REPR_H_
#define _VCPU_REPR_H_

#include <Python.h>
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <structmember.h>
#include "vcpu.h"


#ifdef	__cplusplus
extern "C" {
#endif

extern PyTypeObject VCPU_Repr_Type;

#ifdef	__cplusplus
}
#endif

typedef struct {
    PyObject_HEAD // Макрос объявления нового типа, объекта фиксированного размера
    VCPU vcpu;  
} VCPU_Repr;

//int VCPU_Repr_deinit_callback(VCPU * self);
//int VCPU_Repr_init_callback(VCPU * self, PyObject * f, PyObject * cb);

#endif
