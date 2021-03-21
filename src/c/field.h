#ifndef _FIELD_H_
#define _FIELD_H_

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

#define MaxFieldWidth 100
#define MaxFieldHeight 100

typedef struct FieldCell_s FieldCell;

struct FieldCell_s {
    int type;
    int subtype;
    void * obj;
};

typedef struct Field_s Field;

struct Field_s {
    PyObject_HEAD // Макрос объявления нового типа, объекта фиксированного размера
    int width;
    int height;
    int size;
    FieldCell cells[10000];
};

#endif
