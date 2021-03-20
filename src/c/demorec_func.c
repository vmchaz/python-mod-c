//#include "test.h"
#include <Python.h>
#include "demorec_struct.h"
#include "demorec_extern.h"

PyObject * testmod_func_ret_struct(PyObject *self, PyObject *args) 
{
    DemoRec *st;
    
    // Получаем структуру из Python
    if (!PyArg_ParseTuple(args, "O", &st)) // O - объект данных
        Py_RETURN_NONE;
    
    printf("C get test_st: val1 - %d, val2 - %f, val3 - %d\n", st->val1++, st->val2++, st->val3++);

    return Py_BuildValue("O", st);
}

PyObject * testmod_func_set_element(PyObject *self, PyObject *args) 
{
    DemoRec *st;
    int idx;
    int val;
    
    // Получаем структуру из Python
    if (!PyArg_ParseTuple(args, "Oii", &st, &idx, &val)) // O - объект данных
        Py_RETURN_NONE;
    
    st->data[idx] = val;
    //printf("C get test_st: val1 - %d, val2 - %f, val3 - %d\n", st->val1++, st->val2++, st->val3++);
    Py_RETURN_NONE;
}

PyObject * testmod_func_get_element(PyObject *self, PyObject *args) 
{
    DemoRec *st;
    int idx;
    int val;
    
    // Получаем структуру из Python
    if (!PyArg_ParseTuple(args, "Oi", &st, &idx)) // O - объект данных
        Py_RETURN_NONE;
    
    val = st->data[idx];
    //printf("C get test_st: val1 - %d, val2 - %f, val3 - %d\n", st->val1++, st->val2++, st->val3++);
    Py_BuildValue("i", val);
}
