/*
 * gcc -fPIC -shared -o libtest.so test.c
 */

#include <Python.h>

#include "test.h"
#include "demorec_struct.h"
#include "demorec_extern.h"

#include "demorec_func.h"

#include "vcpu.h"

#include "vcpu_func.h"
#include "basic_func.h"

// Список функций модуля
static PyMethodDef methods[] = {
    {"func_hello", testmod_func_hello, METH_NOARGS, "func_hello"}, // Функция без аргументов
    {"func_ret_int", testmod_func_ret_int, METH_VARARGS, "func_ret_int"}, // Функция с аргументами
    {"func_ret_double", testmod_func_ret_double, METH_VARARGS, "func_ret_double"},
    {"func_ret_str", testmod_func_ret_str, METH_VARARGS, "func_ret_str"},
    {"func_many_args", testmod_func_many_args, METH_VARARGS, "func_many_args"},
    {"func_ret_struct", testmod_func_ret_struct, METH_VARARGS, "func_ret_struct"},
    {"func_get_element", testmod_func_get_element, METH_VARARGS, "func_get_element"},
    {"func_set_element", testmod_func_set_element, METH_VARARGS, "func_set_element"},
    {"func_get_register", testmod_func_get_register, METH_VARARGS, "func_get_register"},
    {"func_set_register", testmod_func_set_register, METH_VARARGS, "func_set_register"},
    
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
    if (PyType_Ready(&VCPU_Type) < 0)
        return NULL;        
    
    Py_INCREF(&DemoRec_Type);
    Py_INCREF(&VCPU_Type);
    
    PyModule_AddObject(mod, "DemoRec", (PyObject *) &DemoRec_Type);
    PyModule_AddObject(mod, "VCPU", (PyObject *) &VCPU_Type);
    
    return mod;
}

/**
 * Тестовые функции, тестовые переменные.
 */

int ModuleVarA = 5;
double ModuleVarB = 5.12345;
char ModuleVarC = 'X'; // 88

