#ifndef _BASIC_FUNC_H_
#define _BASIC_FUNC_H_
#include <Python.h>

PyObject *testmod_func_hello(PyObject *self, PyObject *args);
PyObject *testmod_func_ret_int(PyObject *self, PyObject *args);
PyObject *testmod_func_ret_double(PyObject *self, PyObject *args);
PyObject *testmod_func_ret_str(PyObject *self, PyObject *args);
PyObject *testmod_func_many_args(PyObject *self, PyObject *args);

#endif
