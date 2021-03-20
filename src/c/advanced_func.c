//#include "test.h"
#include <Python.h>
#include "vcpu.h"
#include "demorec.h"


//==========================================================================


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



//==========================================================================




PyObject * testmod_func_set_register(PyObject *self, PyObject *args) 
{
    VCPU *st;
    int idx;
    int val;
    
    // Получаем структуру из Python
    if (!PyArg_ParseTuple(args, "Oii", &st, &idx, &val)) // O - объект данных
        Py_RETURN_NONE;
        
    if ((idx < 0) || (idx > 15))
        Py_RETURN_NONE;
    
    st->registers[idx] = val & 0xFF;
    
    Py_RETURN_NONE;
}

PyObject * testmod_func_get_register(PyObject *self, PyObject *args) 
{
    VCPU *st;
    int idx;
    int val;
    
    // Получаем структуру из Python
    if (!PyArg_ParseTuple(args, "Oi", &st, &idx)) // O - объект данных
        Py_RETURN_NONE;
        
    if ((idx < 0) || (idx > 15))
        Py_RETURN_NONE;
    
    val = st->registers[idx];
    
    Py_BuildValue("i", val);
}



PyObject * testmod_vcpu_step(PyObject *self, PyObject *args) 
{
    VCPU * vcpu;
    Field * field;
    UnitVarStruct * u;
    int maxsteps;
    
    // Получаем структуру из Python
    if (!PyArg_ParseTuple(args, "OOOi", &vcpu, &field, &u, &nsteps)) // O - объект данных
        Py_RETURN_NONE;
    
    val = st->registers[idx];
    
    Py_BuildValue("i", val);
}
