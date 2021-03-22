#ifndef _VCPU_STRUCT_H_
#define _VCPU_STRUCT_H_

#include <Python.h>
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <structmember.h>


#ifdef	__cplusplus
extern "C" {
#endif

extern PyTypeObject VCPU_Type;

#ifdef	__cplusplus
}
#endif

typedef struct {
    PyObject_HEAD // Макрос объявления нового типа, объекта фиксированного размера
    int id;
    int ip;
    int accumulator;
    int flags;
    int stop_flag;
    int error_flag;
    int ip_mod_flag;
    int registers[16];
    
    PyObject * field;
    PyObject * callback;
} VCPU;

int VCPU_deinit_callback(VCPU * self);
int VCPU_init_callback(VCPU * self, PyObject * f, PyObject * cb);

#endif
