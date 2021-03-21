//#include "test.h"
#include <Python.h>
#include "unitvarstruct.h"
#include "actions.h"

// Создание структуры
static PyObject * UnitVarStruct_new(PyTypeObject *type, PyObject *args, PyObject *kwds) 
{
    UnitVarStruct *self;

    self = (UnitVarStruct *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->id = 0;
        self->energy = 0;
        self->x = 0;
        self->y = 0;
        self->direction = 0;
    }

    return (PyObject *)self;
}


// Освобождение структуры
static void UnitVarStruct_dealloc(UnitVarStruct * self) 
{
    Py_TYPE(self)->tp_free((PyObject*)self);
}


// Инициализация структуры, заполняем её переданными значениями
static int UnitVarStruct_init(UnitVarStruct *self, PyObject *args, PyObject *kwds) {
    //static char *kwlist[] = {"val1", "val2", "val3", NULL};
    static char *kwlist[] = {"id", "energy", "x", "y", NULL};
    
    int id;
    int energy;
    int x;
    int y;
    int direction = 0;

    if (! PyArg_ParseTupleAndKeywords(args, kwds, "iiii", kwlist, &id, &energy, &x, &y))
        return -1;
        
    self->id = id;
    self->x = x;
    self->y = y;
    self->energy = energy;
    self->direction = direction;
    self->action = actSTAY;
    self->action_p = 0;
    self->use_action_p = 0;

    return 0;
}


// Описываем аттрибуты из которых состоит структура
static PyMemberDef UnitVarStruct_members[] = 
{
    {"id", T_INT, offsetof(UnitVarStruct, id), 0, "int"},
    {"energy", T_INT, offsetof(UnitVarStruct, energy), 0, "int"},
    {"action", T_INT, offsetof(UnitVarStruct, action), 0, "int"},
    {"action_p", T_INT, offsetof(UnitVarStruct, action_p), 0, "int"},
    {"use_action_p", T_INT, offsetof(UnitVarStruct, use_action_p), 0, "int"},
    {"x", T_INT, offsetof(UnitVarStruct, x), 0, "int"},
    {"y", T_INT, offsetof(UnitVarStruct, y), 0, "int"},
    {"direction", T_INT, offsetof(UnitVarStruct, direction), 0, "int"},
    {NULL}
};


// Описание методов стрктуры, но у классической структуры не может быть методов!
static PyMethodDef UnitVarStruct_methods[] = 
{
    {NULL}  /* Sentinel */
};


// Структура описывающая нашу структуру. Какие атрибуты, методы, конструкторы, деструкторы и т.д. и т.п.
PyTypeObject UnitVarStruct_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "testmod.UnitVarStruct",                  /* tp_name */
    sizeof(UnitVarStruct),                    /* tp_basicsize */
    0,                                  /* tp_itemsize */
    (destructor) UnitVarStruct_dealloc,       /* tp_dealloc */
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
    "UnitVarStruct objects",         /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    UnitVarStruct_methods,           /* tp_methods */
    UnitVarStruct_members,           /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) UnitVarStruct_init,   /* tp_init */
    0,                         /* tp_alloc */
    UnitVarStruct_new,               /* tp_new */
};
