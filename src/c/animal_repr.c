//#include "test.h"
#include <Python.h>
#include "animal_repr.h"
#include "actions.h"

// Создание структуры
static PyObject * Animal_Repr_new(PyTypeObject *type, PyObject *args, PyObject *kwds) 
{
    Animal_Repr *self;

    self = (Animal_Repr *)type->tp_alloc(type, 0);
    if (self != NULL) {
        //self->id = 0;                        
        //memset(&self->animal)
    }

    return (PyObject *)self;
}


// Освобождение структуры
static void Animal_Repr_dealloc(Animal_Repr * self) 
{
    Py_TYPE(self)->tp_free((PyObject*)self);
}


// Инициализация структуры, заполняем её переданными значениями
static int Animal_Repr_init(Animal_Repr *self, PyObject *args, PyObject *kwds) {
    //static char *kwlist[] = {"val1", "val2", "val3", NULL};
    static char *kwlist[] = {"id", "thread_count", "energy", "x", "y", "direction", NULL};
    
    int id;
    int energy;
    int x;
    int y;
    int direction;
    int thread_count;
    
    id = 0;
    energy = 1000;
    thread_count = 1;
    x = 0;
    y = 0;
    direction = 0;

    if (! PyArg_ParseTupleAndKeywords(args, kwds, "|iiiiii", kwlist, &id, &thread_count, &energy, &x, &y, &direction))
        return -1;
        
    if (thread_count < 0)
        thread_count = 0;
        
    if (thread_count > 16)
        thread_count = 16;
        
    self->animal.id = id;
    self->animal.thread_count = thread_count;
    self->animal.unitvarstruct.x = x;
    self->animal.unitvarstruct.y = y;
    self->animal.unitvarstruct.energy = energy;
    self->animal.unitvarstruct.direction = direction;
    
    self->animal.unitvarstruct.action = actSTAY;
    self->animal.unitvarstruct.action_p = 0;
    self->animal.unitvarstruct.use_action_p = 0;

    return 0;
}


// Описываем аттрибуты из которых состоит структура
static PyMemberDef Animal_Repr_members[] = 
{
    {"id", T_INT, offsetof(Animal_Repr, animal.id), 0, "int"},
    {"thread_count", T_INT, offsetof(Animal_Repr, animal.thread_count), 0, "int"},
    {"energy", T_INT, offsetof(Animal_Repr, animal.unitvarstruct.energy), 0, "int"},
    {"action", T_INT, offsetof(Animal_Repr, animal.unitvarstruct.action), 0, "int"},
    {"action_p", T_INT, offsetof(Animal_Repr, animal.unitvarstruct.action_p), 0, "int"},
    {"use_action_p", T_INT, offsetof(Animal_Repr, animal.unitvarstruct.use_action_p), 0, "int"},
    {"x", T_INT, offsetof(Animal_Repr, animal.unitvarstruct.x), 0, "int"},
    {"y", T_INT, offsetof(Animal_Repr, animal.unitvarstruct.x), 0, "int"},
    {"direction", T_INT, offsetof(Animal_Repr, animal.unitvarstruct.direction), 0, "int"},
    {NULL}
};


// Описание методов стрктуры, но у классической структуры не может быть методов!
static PyMethodDef Animal_Repr_methods[] = 
{
    {NULL}  /* Sentinel */
};


// Структура описывающая нашу структуру. Какие атрибуты, методы, конструкторы, деструкторы и т.д. и т.п.
PyTypeObject Animal_Repr_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "testmod.Animal_Repr",                  /* tp_name */
    sizeof(Animal_Repr),                    /* tp_basicsize */
    0,                                  /* tp_itemsize */
    (destructor) Animal_Repr_dealloc,       /* tp_dealloc */
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
    "Animal_Repr objects",         /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    Animal_Repr_methods,           /* tp_methods */
    Animal_Repr_members,           /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) Animal_Repr_init,   /* tp_init */
    0,                         /* tp_alloc */
    Animal_Repr_new,               /* tp_new */
};
