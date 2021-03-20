#include "test.h"
#include "demorec_struct.h"
#include "demorec_extern.h"

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
    static char *kwlist[] = {"val1", "val2", "val3", NULL};

    if (! PyArg_ParseTupleAndKeywords(args, kwds, "|idb", kwlist, &self->val1, &self->val2, &self->val3))
        return -1;

    return 0;
}


// Описываем аттрибуты из которых состоит структура
static PyMemberDef DemoRec_members[] = 
{
    {"val1", T_INT, offsetof(DemoRec, val1), 0, "int"},
    {"val2", T_DOUBLE, offsetof(DemoRec, val2), 0, "double"},
    {"val3", T_CHAR, offsetof(DemoRec, val3), 0, "char"},
    {NULL}
};


// Метод структуры, который печатает структуру
//static PyObject* DemoRec_print(PyObject *self, PyObject *args)
//{
//    DemoRec *st;
    
    // Получаем структуру из Python
//    if (!PyArg_ParseTuple(args, "O", &st)) // O - объект данных
//        Py_RETURN_NONE;
//    
//    printf("method: val1 - %d, val2 - %f, val3 - %d\n", st->val1++, st->val2++, st->val3++);
//    Py_RETURN_NONE;
//}

// Описание методов стрктуры, но у классической структуры не может быть методов!
// А здесь может!
//static PyMethodDef DemoRec_methods[] = {
//    {"print", DemoRec_print, METH_VARARGS, "doc string"},
//    {NULL}  /* Sentinel */
//};


static PyMethodDef DemoRec_methods[] = {
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
