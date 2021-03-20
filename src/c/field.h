#ifndef _FIELD_STRUCT_H_
#define _FIELD_STRUCT_H_

#include <Python.h>
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <structmember.h>


#ifdef	__cplusplus
extern "C" {
#endif

extern PyTypeObject Field_Type;

#ifdef	__cplusplus
}
#endif

#define MaxFieldWidth 10
#define MaxFieldHeight 10

typedef struct FieldCell_s FieldCell;

struct FieldCell_s {
    int type;
    void * obj;
};

typedef struct Field_s Field;

struct Field_s {
    PyObject_HEAD // Макрос объявления нового типа, объекта фиксированного размера
    int width;
    int height;
    int size;
    FieldCell cells[100];
};

#endif
