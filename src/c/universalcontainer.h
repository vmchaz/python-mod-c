#ifndef _UNITVARSTRUCT_H_
#define _UNITVARSTRUCT_H_

#include <Python.h>
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <structmember.h>


#ifdef	__cplusplus
extern "C" {
#endif

extern PyTypeObject UnitVarStruct_Type;

#ifdef	__cplusplus
}
#endif

typedef struct UnitVarStruct_s UnitVarStruct;

struct UnitVarStruct_s {
    PyObject_HEAD // Макрос объявления нового типа, объекта фиксированного размера
    int id;
    int energy;
    int action;
    int action_p;
    int use_action_p;
    int x;
    int y;
    int direction;
};

#endif
