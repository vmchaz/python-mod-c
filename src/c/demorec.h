#ifndef _DEMOREC_H_
#define _DEMOREC_H_

#include <Python.h>
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <structmember.h>

#ifdef  __cplusplus
extern "C" {
#endif

extern PyTypeObject DemoRec_Type;

#ifdef  __cplusplus
}
#endif


typedef struct DemoRec_s DemoRec;

struct DemoRec_s {
    PyObject_HEAD // Макрос объявления нового типа, объекта фиксированного размера
    int id;
    int val1;
    double val2;
    char val3;
    int data[1000];
};

#endif
