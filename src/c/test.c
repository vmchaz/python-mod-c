/*
 * gcc -fPIC -shared -o libtest.so test.c
 */

#include <Python.h>


#include "test.h"
#include "demorec.h"

#include "vcpu_repr.h"
#include "instructionsequence_repr.h"
#include "field.h"
#include "unitvarstruct_repr.h"

#include "basic_func.h"
#include "advanced_func.h"
#include "demorec_func.h"



// Список функций модуля
static PyMethodDef methods[] = {
//    {"func_hello", testmod_func_hello, METH_NOARGS, "Test function func_hello"}, // Функция без аргументов
//    {"func_ret_int", testmod_func_ret_int, METH_VARARGS, "Test function func_ret_int"}, // Функция с аргументами
//    {"func_ret_double", testmod_func_ret_double, METH_VARARGS, "Test function func_ret_double"},
//    {"func_ret_str", testmod_func_ret_str, METH_VARARGS, "Test function func_ret_str"},
//    {"func_many_args", testmod_func_many_args, METH_VARARGS, "Test function func_many_args"},
//    {"func_ret_struct", testmod_func_ret_struct, METH_VARARGS, "Test function func_ret_struct"},
//    {"func_get_element", testmod_func_get_element, METH_VARARGS, "Function func_get_element"},
//    {"func_set_element", testmod_func_set_element, METH_VARARGS, "Function func_set_element"},
//    {"get_register", testmod_func_get_register, METH_VARARGS, "Function get_register"},
//    {"set_register", testmod_func_set_register, METH_VARARGS, "Function set_register"},
//    {"set_instruction", testmod_func_set_instruction, METH_VARARGS, "Function set_instruction"},
    {"get_instruction", testmod_func_get_instruction, METH_VARARGS , "Function get_instruction"},
    {"set_instruction", testmod_func_set_instruction, METH_VARARGS, "Function set_instruction"},
    {"add_instruction", testmod_func_add_instruction, METH_VARARGS, "Function add_instruction"},
    
    {"animal_get_instruction_seq", testmod_func_animal_get_instruction_seq, METH_VARARGS , "Function animal_get_instruction_seq"},
    {"animal_set_instruction_seq", testmod_func_animal_set_instruction_seq, METH_VARARGS , "Function animal_set_instruction_seq"},
//    {"animal_get_seq", testmod_func_animal_get_seq, METH_VARARGS, "tmp0"},
//    {"animal_set_seq", testmod_func_animal_set_seq, METH_VARARGS, "tmp1"},
//    {"animal_get_vcpu", testmod_func_animal_get_vcpu, METH_VARARGS, "tmp2"},
//    {"animal_set_vcpu", testmod_func_animal_set_vcpu, METH_VARARGS, "tmp3"},
//    {"animal_get_unitvarstruct", testmod_func_animal_get_unitvarstruct, METH_VARARGS, "tmp4"},
//    {"animal_set_unitvarstruct", testmod_func_animal_set_unitvarstruct, METH_VARARGS, "tmp5"},
    {"vcpu_run", testmod_vcpu_run, METH_VARARGS | METH_KEYWORDS, "Function vcpu_step"},
    //{"vcpu_set_callback", testmod_vcpu_set_callback, METH_VARARGS, "Function vcpu_set_callback"},
    //{"field_set_object", testmod_field_set_object, METH_VARARGS, "Function field_set_object"},
    //{"field_get_object", testmod_field_get_object, METH_VARARGS, "Function field_get_object"},
    //{"field_get_object_type", testmod_field_get_object_type, METH_VARARGS, "Function field_get_object_type"},                    
    
    {NULL, NULL, 0, NULL}
};

// Описание модуля
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT, "testmod", "Test module", -1, methods
};

// Инициализация модуля
PyMODINIT_FUNC PyInit_testmod(void)
{
    PyObject *mod = PyModule_Create(&module);

    // Добавляем глобальные переменные
    
    PyModule_AddObject(mod, "ModuleVarA", PyLong_FromLong(ModuleVarA)); // int
    PyModule_AddObject(mod, "ModuleVarB", PyFloat_FromDouble(ModuleVarB)); // double
    PyModule_AddObject(mod, "ModuleVarC", Py_BuildValue("b", ModuleVarC)); // char

    // Добавляем структуру
    
    
    // Завершение инициализации структуры
    if (PyType_Ready(&DemoRec_Type) < 0)
        return NULL;
    if (PyType_Ready(&VCPU_Repr_Type) < 0)
        return NULL;
    if (PyType_Ready(&InstructionSequence_Repr_Type) < 0)
        return NULL;
    if (PyType_Ready(&Field_Type) < 0)
        return NULL;
    if (PyType_Ready(&UnitVarStruct_Repr_Type) < 0)
        return NULL;

    
    Py_INCREF(&DemoRec_Type);
    Py_INCREF(&VCPU_Repr_Type);
    Py_INCREF(&InstructionSequence_Repr_Type);
    Py_INCREF(&Field_Type);
    Py_INCREF(&UnitVarStruct_Repr_Type);
    
    PyModule_AddObject(mod, "DemoRec", (PyObject *) &DemoRec_Type);
    PyModule_AddObject(mod, "VCPU_Repr", (PyObject *) &VCPU_Repr_Type);
    PyModule_AddObject(mod, "InstructionSequence", (PyObject *) &InstructionSequence_Repr_Type);
    PyModule_AddObject(mod, "Field", (PyObject *) &Field_Type);
    PyModule_AddObject(mod, "UnitVarStruct", (PyObject *) &UnitVarStruct_Repr_Type);
    
    return mod;
}

/**
 * Тестовые функции, тестовые переменные.
 */

int ModuleVarA = 5;
double ModuleVarB = 5.12345;
char ModuleVarC = 'X'; // 88

