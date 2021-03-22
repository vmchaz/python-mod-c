//#include "test.h"
#include <stdio.h>
#include <Python.h>
#include "vcpu.h"

// Создание структуры
static PyObject * VCPU_new(PyTypeObject *type, PyObject *args, PyObject *kwds) 
{
    VCPU *self;

    self = (VCPU *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->id = 0;
        self->ip = 0;
        self->accumulator = 0;
        self->flags = 0;        
        self->stop_flag = 0;
        self->error_flag = 0;
        
        self->field = NULL;
        self->callback = NULL;
        memset(&self->ip_mod_flag, 0, sizeof(self->ip_mod_flag));
        
        for(int i=0; i<16; i++)
            self->registers[i] = 0;
    }

    return (PyObject *)self;
}


// Освобождение структуры
static void VCPU_dealloc(VCPU * self) 
{
    VCPU_deinit_callback(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

int VCPU_init_callback(VCPU * vcpu, PyObject * f, PyObject * cb)
{
    if (!PyCallable_Check(cb))
    {
        PyErr_SetString(PyExc_TypeError, "parameter must be callable");
        return -1;
    }
    
    if (vcpu->field != NULL)
    {
        Py_XDECREF(vcpu->field);
        vcpu->field = NULL;
    }
    
    if (vcpu->callback != NULL)
    {
        Py_XDECREF(vcpu->callback);
        vcpu->callback = NULL;
    }


    Py_XINCREF(f);
    Py_XINCREF(cb);
            
    vcpu->field = f;
    vcpu->callback = cb;
        
    return 0;
}

int vcpu_set_callback(PyObject * args)
{

}

int VCPU_deinit_callback(VCPU * self)
{
    if (self->field != NULL)
    {
        Py_XDECREF(self->field);
        self->field = NULL;
    }
    
    if (self->callback != NULL)
    {
        Py_XDECREF(self->callback);
        self->callback = NULL;
    }
}


// Инициализация структуры, заполняем её переданными значениями
static int VCPU_init(VCPU *self, PyObject *args, PyObject *kwds) {
    //static char *kwlist[] = {"val1", "val2", "val3", NULL};
    static char *kwlist[] = {"id", NULL};
    
    int id;

    if (! PyArg_ParseTupleAndKeywords(args, kwds, "i", kwlist, &id))
        return -1;
        
    self->id = id;

    return 0;
}


// Описываем аттрибуты из которых состоит структура
static PyMemberDef VCPU_members[] = 
{
    {"id", T_INT, offsetof(VCPU, id), 0, "int"},
    {"ip", T_INT, offsetof(VCPU, ip), 0, "int"},
    {"accumulator", T_INT, offsetof(VCPU, accumulator), 0, "int"},
    
    {"r0", T_INT, offsetof(VCPU, registers[0]), 0, "int"},
    {"r1", T_INT, offsetof(VCPU, registers[1]), 0, "int"},
    {"r2", T_INT, offsetof(VCPU, registers[2]), 0, "int"},
    {"r3", T_INT, offsetof(VCPU, registers[3]), 0, "int"},
    
    {"r4", T_INT, offsetof(VCPU, registers[4]), 0, "int"},
    {"r5", T_INT, offsetof(VCPU, registers[5]), 0, "int"},
    {"r6", T_INT, offsetof(VCPU, registers[6]), 0, "int"},
    {"r7", T_INT, offsetof(VCPU, registers[7]), 0, "int"},
     
    {"flags", T_INT, offsetof(VCPU, flags), 0, "int"},
    {"stop_flag", T_INT, offsetof(VCPU, stop_flag), 0, "int"},
    {"error_flag", T_INT, offsetof(VCPU, error_flag), 0, "int"},
    {NULL}
};


// Описание методов стрктуры, но у классической структуры не может быть методов!
static PyMethodDef VCPU_methods[] = 
{
    {NULL}  /* Sentinel */
};


// Структура описывающая нашу структуру. Какие атрибуты, методы, конструкторы, деструкторы и т.д. и т.п.
PyTypeObject VCPU_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "testmod.VCPU",                  /* tp_name */
    sizeof(VCPU),                    /* tp_basicsize */
    0,                                  /* tp_itemsize */
    (destructor) VCPU_dealloc,       /* tp_dealloc */
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
    "VCPU objects",         /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    VCPU_methods,           /* tp_methods */
    VCPU_members,           /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) VCPU_init,   /* tp_init */
    0,                         /* tp_alloc */
    VCPU_new,               /* tp_new */
};
