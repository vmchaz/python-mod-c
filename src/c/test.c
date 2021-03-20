/*
 * gcc -fPIC -shared -o libtest.so test.c
 */

#include <Python.h>

#include "test.h"
#include "demorec_struct.h"
#include "demorec_extern.h"
#include "demorec_func.h"
#include "basic_func.h"

// Список функций модуля
static PyMethodDef methods[] = {
    {"func_hello", func_hello, METH_NOARGS, "func_hello"}, // Функция без аргументов
    {"func_ret_int", func_ret_int, METH_VARARGS, "func_ret_int"}, // Функция с аргументами
    {"func_ret_double", func_ret_double, METH_VARARGS, "func_ret_double"},
    {"func_ret_str", func_ret_str, METH_VARARGS, "func_ret_str"},
    {"func_many_args", func_many_args, METH_VARARGS, "func_many_args"},
    {"func_ret_struct", func_ret_struct, METH_VARARGS, "func_ret_struct"},
    {"func_set_element", func_set_element, METH_VARARGS, "func_get_element"},
    {"func_get_element", func_get_element, METH_VARARGS, "func_get_element"},
    {NULL, NULL, 0, NULL}
};

// Описание модуля
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT, "testmod", "Test module", -1, methods
};

// Инициализация модуля
PyMODINIT_FUNC PyInit_testmod(void) {
    PyObject *mod = PyModule_Create(&module);

    // Добавляем глобальные переменные
    
    PyModule_AddObject(mod, "ModuleVarA", PyLong_FromLong(ModuleVarA)); // int
    PyModule_AddObject(mod, "ModuleVarB", PyFloat_FromDouble(ModuleVarB)); // double
    PyModule_AddObject(mod, "ModuleVarC", Py_BuildValue("b", ModuleVarC)); // char

    // Добавляем структуру
    
    // Завершение инициализации структуры
    if (PyType_Ready(&DemoRec_Type) < 0)
        return NULL;
    
    Py_INCREF(&DemoRec_Type);
    PyModule_AddObject(mod, "DemoRec", (PyObject *) &DemoRec_Type);
    
    return mod;
}

/**
 * Тестовые функции, тестовые переменные.
 */

int ModuleVarA = 5;
double ModuleVarB = 5.12345;
char ModuleVarC = 'X'; // 88

