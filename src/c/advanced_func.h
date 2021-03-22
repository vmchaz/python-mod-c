#ifndef _ADVANCED_FUNC_H_
#define _ADVANCED_FUNC_H_
#include <Python.h>

//PyObject * testmod_func_ret_struct(PyObject *self, PyObject *args);
//PyObject * testmod_func_set_element(PyObject *self, PyObject *args);
//PyObject * testmod_func_get_element(PyObject *self, PyObject *args);

//PyObject * testmod_func_set_register(PyObject *self, PyObject *args);
PyObject * testmod_func_animal_get_instruction_seq(PyObject *self, PyObject *args);
PyObject * testmod_func_animal_set_instruction_seq(PyObject *self, PyObject *args);

PyObject * testmod_func_get_instruction(PyObject *self, PyObject *args);
PyObject * testmod_func_set_instruction(PyObject *self, PyObject *args);
PyObject * testmod_func_add_instruction(PyObject *self, PyObject *args);

PyObject * testmod_vcpu_run(PyObject *self, PyObject *args);
PyObject * testmod_vcpu_reset(PyObject *self, PyObject *args);
PyObject * testmod_vcpu_get_state(PyObject *self, PyObject *args);

//PyObject * testmod_field_set_object(PyObject *self, PyObject *args);
//PyObject * testmod_field_get_object(PyObject *self, PyObject *args);
//PyObject * testmod_field_get_object_type(PyObject *self, PyObject *args);

#endif

