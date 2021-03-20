//#include "test.h"
#include <Python.h>
#include "field.h"

// Создание структуры
static PyObject * Field_new(PyTypeObject *type, PyObject *args, PyObject *kwds) 
{
    Field *self;

    self = (Field *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->width = 0;
        self->height = 0;
        self->size = 0;
        memset(&self->cells, 0, sizeof(self->cells));
    }

    return (PyObject *)self;
}


// Освобождение структуры
static void Field_dealloc(Field * self) 
{
    Py_TYPE(self)->tp_free((PyObject*)self);
}


// Инициализация структуры, заполняем её переданными значениями
static int Field_init(Field *self, PyObject *args, PyObject *kwds) {
    //static char *kwlist[] = {"val1", "val2", "val3", NULL};
    static char *kwlist[] = {"id", NULL};
    
    int width, height;

    if (! PyArg_ParseTupleAndKeywords(args, kwds, "ii", kwlist, &width, &height))
        return -1;
        
    self->width = width;
    self->height = height;
    self->size = width*height;

    return 0;
}


// Описываем аттрибуты из которых состоит структура
static PyMemberDef Field_members[] = 
{
    {"width", T_INT, offsetof(Field, width), 0, "int"},
    {"height", T_INT, offsetof(Field, height), 0, "int"},
    {"size", T_INT, offsetof(Field, size), 0, "int"},
    {NULL}
};


// Описание методов стрктуры, но у классической структуры не может быть методов!
static PyMethodDef Field_methods[] = 
{
    {NULL}  /* Sentinel */
};


// Структура описывающая нашу структуру. Какие атрибуты, методы, конструкторы, деструкторы и т.д. и т.п.
PyTypeObject Field_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "testmod.Field",                  /* tp_name */
    sizeof(Field),                    /* tp_basicsize */
    0,                                  /* tp_itemsize */
    (destructor) Field_dealloc,       /* tp_dealloc */
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
    "Field objects",         /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    Field_methods,           /* tp_methods */
    Field_members,           /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) Field_init,   /* tp_init */
    0,                         /* tp_alloc */
    Field_new,               /* tp_new */
};
