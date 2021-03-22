//#include "test.h"
#include <Python.h>
#include "unitvarstruct_repr.h"
#include "actions.h"

// Создание структуры
static PyObject * UnitVarStruct_Repr_new(PyTypeObject *type, PyObject *args, PyObject *kwds) 
{
    UnitVarStruct_Repr *self;

    self = (UnitVarStruct_Repr *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->unitvarstruct.id = 0;
        self->unitvarstruct.energy = 0;
        self->unitvarstruct.x = 0;
        self->unitvarstruct.y = 0;
        self->unitvarstruct.direction = 0;
        self->unitvarstruct.action = actSTAY;
        self->unitvarstruct.action_p = 0;
        self->unitvarstruct.use_action_p = 0;
    }

    return (PyObject *)self;
}


// Освобождение структуры
static void UnitVarStruct_Repr_dealloc(UnitVarStruct_Repr * self) 
{
    Py_TYPE(self)->tp_free((PyObject*)self);
}


// Инициализация структуры, заполняем её переданными значениями
static int UnitVarStruct_Repr_init(UnitVarStruct_Repr *self, PyObject *args, PyObject *kwds) {
    //static char *kwlist[] = {"val1", "val2", "val3", NULL};
    static char *kwlist[] = {"id", "energy", "x", "y", "direction", NULL};
    
    int id;
    int energy;
    int x;
    int y;
    int direction = 0;

    if (! PyArg_ParseTupleAndKeywords(args, kwds, "iiiii", kwlist, &id, &energy, &x, &y, &direction))
        return -1;
        
    self->unitvarstruct.id = id;
    self->unitvarstruct.x = x;
    self->unitvarstruct.y = y;
    self->unitvarstruct.energy = energy;
    self->unitvarstruct.direction = direction;
    self->unitvarstruct.action = actSTAY;
    self->unitvarstruct.action_p = 0;
    self->unitvarstruct.use_action_p = 0;

    return 0;
}


// Описываем аттрибуты из которых состоит структура
static PyMemberDef UnitVarStruct_Repr_members[] = 
{
    {"id", T_INT, offsetof(UnitVarStruct_Repr, unitvarstruct.id), 0, "int"},
    {"energy", T_INT, offsetof(UnitVarStruct_Repr, unitvarstruct.energy), 0, "int"},
    {"action", T_INT, offsetof(UnitVarStruct_Repr, unitvarstruct.action), 0, "int"},
    {"action_p", T_INT, offsetof(UnitVarStruct_Repr, unitvarstruct.action_p), 0, "int"},
    {"use_action_p", T_INT, offsetof(UnitVarStruct_Repr, unitvarstruct.use_action_p), 0, "int"},
    {"x", T_INT, offsetof(UnitVarStruct_Repr, unitvarstruct.x), 0, "int"},
    {"y", T_INT, offsetof(UnitVarStruct_Repr, unitvarstruct.y), 0, "int"},
    {"direction", T_INT, offsetof(UnitVarStruct_Repr, unitvarstruct.direction), 0, "int"},
    {NULL}
};


// Описание методов стрктуры, но у классической структуры не может быть методов!
static PyMethodDef UnitVarStruct_Repr_methods[] = 
{
    {NULL}  /* Sentinel */
};


// Структура описывающая нашу структуру. Какие атрибуты, методы, конструкторы, деструкторы и т.д. и т.п.
PyTypeObject UnitVarStruct_Repr_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "testmod.UnitVarStruct_Repr",                  /* tp_name */
    sizeof(UnitVarStruct_Repr),                    /* tp_basicsize */
    0,                                  /* tp_itemsize */
    (destructor) UnitVarStruct_Repr_dealloc,       /* tp_dealloc */
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
    "UnitVarStruct_Repr objects",         /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    UnitVarStruct_Repr_methods,           /* tp_methods */
    UnitVarStruct_Repr_members,           /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) UnitVarStruct_Repr_init,   /* tp_init */
    0,                         /* tp_alloc */
    UnitVarStruct_Repr_new,               /* tp_new */
};
