//#include "test.h"
#include <Python.h>
#include "unitvarstruct.h"
#include "actions.h"

// Создание структуры
static PyObject * Animal_new(PyTypeObject *type, PyObject *args, PyObject *kwds) 
{
    Animal *self;

    self = (Animal *)type->tp_alloc(type, 0);
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
static void Animal_dealloc(Animal * self) 
{
    Py_TYPE(self)->tp_free((PyObject*)self);
}


// Инициализация структуры, заполняем её переданными значениями
static int Animal_init(Animal *self, PyObject *args, PyObject *kwds) {
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
static PyMemberDef Animal_members[] = 
{
    {"id", T_INT, offsetof(Animal, id), 0, "int"},
    {"energy", T_INT, offsetof(Animal, energy), 0, "int"},
    {"action", T_INT, offsetof(Animal, action), 0, "int"},
    {"action_p", T_INT, offsetof(Animal, action_p), 0, "int"},
    {"use_action_p", T_INT, offsetof(Animal, use_action_p), 0, "int"},
    {"x", T_INT, offsetof(Animal, x), 0, "int"},
    {"y", T_INT, offsetof(Animal, y), 0, "int"},
    {"direction", T_INT, offsetof(Animal, direction), 0, "int"},
    {NULL}
};


// Описание методов стрктуры, но у классической структуры не может быть методов!
static PyMethodDef Animal_methods[] = 
{
    {NULL}  /* Sentinel */
};


// Структура описывающая нашу структуру. Какие атрибуты, методы, конструкторы, деструкторы и т.д. и т.п.
PyTypeObject Animal_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "testmod.Animal",                  /* tp_name */
    sizeof(Animal),                    /* tp_basicsize */
    0,                                  /* tp_itemsize */
    (destructor) Animal_dealloc,       /* tp_dealloc */
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
    "Animal objects",         /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    Animal_methods,           /* tp_methods */
    Animal_members,           /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) Animal_init,   /* tp_init */
    0,                         /* tp_alloc */
    Animal_new,               /* tp_new */
};
