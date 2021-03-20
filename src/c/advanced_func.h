#ifndef _ADVANCED_FUNC_H_
#define _ADVANCED_FUNC_H_
#include <Python.h>

PyObject * testmod_func_ret_struct(PyObject *self, PyObject *args);
PyObject * testmod_func_set_element(PyObject *self, PyObject *args);
PyObject * testmod_func_get_element(PyObject *self, PyObject *args);

PyObject * testmod_func_set_register(PyObject *self, PyObject *args);
PyObject * testmod_func_get_register(PyObject *self, PyObject *args);

#endif

