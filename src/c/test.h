#ifndef _TEST_H_
#define	_TEST_H_

#ifdef	__cplusplus
extern "C" {
#endif

#include <Python.h>
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern int a;
extern double b;
extern char c;

static PyObject *func_hello(PyObject *self, PyObject *args);
static PyObject *func_ret_int(PyObject *self, PyObject *args);
static PyObject *func_ret_double(PyObject *self, PyObject *args);
static PyObject *func_ret_str(PyObject *self, PyObject *args);
static PyObject *func_many_args(PyObject *self, PyObject *args);
static PyObject *func_ret_struct(PyObject *self, PyObject *args);

#ifdef	__cplusplus
}
#endif

#endif	/* _TEST_H_ */
