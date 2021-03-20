#ifndef _DEMOREC_STRUCT_H_
#define _DEMOREC_STRUCT_H_

#include <Python.h>
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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
