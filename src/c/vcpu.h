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

typedef struct VCPU_s VCPU;

struct VCPU_s {
    PyObject_HEAD // Макрос объявления нового типа, объекта фиксированного размера
    int id;
    int ip;
    int flags;
    int stop_flag;
    int registers[16];
};

#endif
