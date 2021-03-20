#include <Python.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "basic_func.h"


static PyObject * func_hello(PyObject *self, PyObject *args) 
{ // Можно без args, но будет warning при компиляции.
    puts("Hello!");
    Py_RETURN_NONE;
}


/**
 * Получение значения переменной содержащей значение типа int и возврат его.
 */
static PyObject * func_ret_int(PyObject *self, PyObject *args) 
{
    int val;

    // Проверка кол-ва аргументов
    if (PyTuple_Size(args) != 1) {
        PyErr_SetString(self, "func_ret_int args error");
    }

    PyArg_ParseTuple(args, "i", &val);
    /* 
     * Альтернативный вариант.
     * 
    // Получаем аргумент
    PyObject *obj = PyTuple_GetItem(args, 0);
    // Проверяем его на тип int/long
    if (PyLong_Check(obj)) {
        PyErr_Print();
    }
    // Приводим (PyObject *) к int
    val = _PyLong_AsInt(obj);
     */
    printf("C get func_ret_int: %d\n", val);
    return Py_BuildValue("i", val);
}

/**
 * Получение значения переменной содержащей значение типа double и возврат его.
 */
static PyObject * func_ret_double(PyObject *self, PyObject *args) {
    double val;

    if (PyTuple_Size(args) != 1) {
        PyErr_SetString(self, "func_ret_double args error");
    }

    PyArg_ParseTuple(args, "d", &val);

    printf("C get func_ret_double: %f\n", val);
    return Py_BuildValue("f", val);
}

/**
 * Получение string и возврат его.
 */
static PyObject * func_ret_str(PyObject *self, PyObject *args) {
    char *val;

    if (PyTuple_Size(args) != 1) {
        PyErr_SetString(self, "func_ret_str args error");
    }

    PyArg_ParseTuple(args, "s", &val);
    /* 
     * Альтернативный вариант.
     * 
    PyObject *obj = PyTuple_GetItem(args, 0);
    
    PyObject* pResultRepr = PyObject_Repr(obj);
    val = PyBytes_AS_STRING(PyUnicode_AsEncodedString(pResultRepr, "utf-8", "ERROR"));
     */
    printf("C get func_ret_str: %s\n", val);
    return Py_BuildValue("s", val);
}

/**
 * Получение значения переменных содержащих значения типа int, double, char *.
 */
static PyObject * func_many_args(PyObject *self, PyObject *args) {
    int val1;
    double val2;
    char *val3;

    if (PyTuple_Size(args) != 3) {
        PyErr_SetString(self, "func_ret_str args error");
    }

    PyArg_ParseTuple(args, "ids", &val1, &val2, &val3);

    printf("C get func_many_args: int - %d, double - %f, string - %s\n", val1, val2, val3);
    return Py_BuildValue("ifs", val1, val2, val3);
}

