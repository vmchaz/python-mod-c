//#include "test.h"
#include <Python.h>
#include "vcpu.h"

/*PyObject * testmod_func_ret_struct(PyObject *self, PyObject *args) 
{
    VCPU *st;
    
    // Получаем структуру из Python
    if (!PyArg_ParseTuple(args, "O", &st)) // O - объект данных
        Py_RETURN_NONE;
    
    printf("C get test_st: id:%d, ip:%f, flags:%d, stop_flag:%d\n", st->id, st->ip, st->flags, st->stop_flag);

    return Py_BuildValue("O", st);
}*/

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
