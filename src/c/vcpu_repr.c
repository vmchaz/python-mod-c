//#include "test.h"
#include <stdio.h>
#include <Python.h>
#include "vcpu_repr.h"

// Создание структуры
static PyObject * VCPU_Repr_new(PyTypeObject *type, PyObject *args, PyObject *kwds) 
{
    VCPU_Repr *self;

    self = (VCPU_Repr *)type->tp_alloc(type, 0);
    if (self != NULL) 
    {
        vcpu_init(&self->vcpu, 0);
    }

    return (PyObject *)self;
}


// Освобождение структуры
static void VCPU_Repr_dealloc(VCPU_Repr * self) 
{
    //VCPU_Repr_deinit_callback(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

/*int VCPU_Repr_init_callback(VCPU_Repr * vcpu, PyObject * f, PyObject * cb)
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

int VCPU_Repr_deinit_callback(VCPU_Repr * self)
{
    if (self->vcpu.field != NULL)
    {
        Py_XDECREF(self->vcpu.field);
        self->vcpu.field = NULL;
    }
    
    if (self->vcpu.callback != NULL)
    {
        Py_XDECREF(self->vcpu.callback);
        self->vcpu.callback = NULL;
    }
}*/


// Инициализация структуры, заполняем её переданными значениями
static int VCPU_Repr_init(VCPU_Repr *self, PyObject *args, PyObject *kwds) {
    //static char *kwlist[] = {"val1", "val2", "val3", NULL};
    static char *kwlist[] = {"id", NULL};
    
    int id;

    if (! PyArg_ParseTupleAndKeywords(args, kwds, "i", kwlist, &id))
        return -1;
        
    self->vcpu.id = id;

    return 0;
}


// Описываем аттрибуты из которых состоит структура
static PyMemberDef VCPU_Repr_members[] = 
{
    {"id", T_INT, offsetof(VCPU_Repr, vcpu.id), 0, "int"},
    {"ip", T_INT, offsetof(VCPU_Repr, vcpu.ip), 0, "int"},
    {"accumulator", T_INT, offsetof(VCPU_Repr, vcpu.accumulator), 0, "int"},
    
    {"r0", T_INT, offsetof(VCPU_Repr, vcpu.registers[0]), 0, "int"},
    {"r1", T_INT, offsetof(VCPU_Repr, vcpu.registers[1]), 0, "int"},
    {"r2", T_INT, offsetof(VCPU_Repr, vcpu.registers[2]), 0, "int"},
    {"r3", T_INT, offsetof(VCPU_Repr, vcpu.registers[3]), 0, "int"},
    
    {"r4", T_INT, offsetof(VCPU_Repr, vcpu.registers[4]), 0, "int"},
    {"r5", T_INT, offsetof(VCPU_Repr, vcpu.registers[5]), 0, "int"},
    {"r6", T_INT, offsetof(VCPU_Repr, vcpu.registers[6]), 0, "int"},
    {"r7", T_INT, offsetof(VCPU_Repr, vcpu.registers[7]), 0, "int"},
    
    {"r8", T_INT, offsetof(VCPU_Repr, vcpu.registers[8]), 0, "int"},
    {"r9", T_INT, offsetof(VCPU_Repr, vcpu.registers[9]), 0, "int"},
    {"r10", T_INT, offsetof(VCPU_Repr, vcpu.registers[10]), 0, "int"},
    {"r11", T_INT, offsetof(VCPU_Repr, vcpu.registers[11]), 0, "int"},
    
    {"r12", T_INT, offsetof(VCPU_Repr, vcpu.registers[12]), 0, "int"},
    {"r13", T_INT, offsetof(VCPU_Repr, vcpu.registers[13]), 0, "int"},
    {"r14", T_INT, offsetof(VCPU_Repr, vcpu.registers[14]), 0, "int"},
    {"r15", T_INT, offsetof(VCPU_Repr, vcpu.registers[15]), 0, "int"},
     
    {"flags", T_INT, offsetof(VCPU_Repr, vcpu.flags), 0, "int"},
    {"stop_flag", T_INT, offsetof(VCPU_Repr, vcpu.stop_flag), 0, "int"},
    {"error_flag", T_INT, offsetof(VCPU_Repr, vcpu.error_flag), 0, "int"},
    {NULL}
};


// Описание методов стрктуры, но у классической структуры не может быть методов!
static PyMethodDef VCPU_Repr_methods[] = 
{
    {NULL}  /* Sentinel */
};


// Структура описывающая нашу структуру. Какие атрибуты, методы, конструкторы, деструкторы и т.д. и т.п.
PyTypeObject VCPU_Repr_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "testmod.VCPU_Repr",                  /* tp_name */
    sizeof(VCPU_Repr),                    /* tp_basicsize */
    0,                                  /* tp_itemsize */
    (destructor) VCPU_Repr_dealloc,       /* tp_dealloc */
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
    "VCPU_Repr objects",         /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    VCPU_Repr_methods,           /* tp_methods */
    VCPU_Repr_members,           /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) VCPU_Repr_init,   /* tp_init */
    0,                         /* tp_alloc */
    VCPU_Repr_new,               /* tp_new */
};
