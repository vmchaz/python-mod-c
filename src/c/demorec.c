//#include "test.h"
#include <Python.h>
#include "demorec.h"

// Создание структуры
static PyObject * DemoRec_new(PyTypeObject *type, PyObject *args, PyObject *kwds) 
{
    DemoRec *self;

    self = (DemoRec *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->val1 = 0;
        self->val2 = 0.0;
        self->val3 = 0;
    }

    return (PyObject *)self;
}


// Освобождение структуры
static void DemoRec_dealloc(DemoRec* self) 
{
    Py_TYPE(self)->tp_free((PyObject*)self);
}


// Инициализация структуры, заполняем её переданными значениями
static int DemoRec_init(DemoRec *self, PyObject *args, PyObject *kwds) {
    //static char *kwlist[] = {"val1", "val2", "val3", NULL};
    static char *kwlist[] = {"id", NULL};
    
    int id;

    if (! PyArg_ParseTupleAndKeywords(args, kwds, "i", kwlist, &id))
        return -1;
        
    self->id = id;

    return 0;
}


// Описываем аттрибуты из которых состоит структура
static PyMemberDef DemoRec_members[] = 
{
    {"id", T_INT, offsetof(DemoRec, id), 0, "int"},
    {"val1", T_INT, offsetof(DemoRec, val1), 0, "int"},
    {"val2", T_DOUBLE, offsetof(DemoRec, val2), 0, "double"},
    {"val3", T_CHAR, offsetof(DemoRec, val3), 0, "char"},
    {NULL}
};


// Описание методов стрктуры, но у классической структуры не может быть методов!
static PyMethodDef DemoRec_methods[] = 
{
    {NULL}  /* Sentinel */
};


// Структура описывающая нашу структуру. Какие атрибуты, методы, конструкторы, деструкторы и т.д. и т.п.
PyTypeObject DemoRec_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "testmod.DemoRec",                  /* tp_name */
    sizeof(DemoRec),                    /* tp_basicsize */
    0,                                  /* tp_itemsize */
    (destructor) DemoRec_dealloc,       /* tp_dealloc */
    0,                                  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "DemoRec objects",         /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    DemoRec_methods,           /* tp_methods */
    DemoRec_members,           /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) DemoRec_init,   /* tp_init */
    0,                         /* tp_alloc */
    DemoRec_new,               /* tp_new */
};
