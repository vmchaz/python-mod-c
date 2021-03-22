//#include "test.h"
#include <Python.h>
#include "demorec.h"
#include "vcpu.h"
#include "field.h"
#include "unitvarstruct.h"
#include "instructionsequence.h"

#include "cpu.h"


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
    return Py_BuildValue("i", val);
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
    
    return Py_BuildValue("i", val);
}



PyObject * testmod_func_set_instruction(PyObject *self, PyObject *args) 
{
    InstructionSequence * sequence;
    int idx;
    int cmd;
    int reg_dest;
    int reg_src;
    int imm;
    int flags_allow;
    int flags_deny;
    int flags_target;
    
    // Получаем структуру из Python
    if (!PyArg_ParseTuple(args, "Oiiiiiiii", &sequence, &idx, &cmd, &reg_dest, &reg_src, &imm, &flags_allow, &flags_deny, &flags_target)) // O - объект данных
        Py_RETURN_NONE;
        
    if ((idx < 0) || (idx >= sequence->count))
        Py_RETURN_NONE;
    
    sequence->instructions[idx].cmd = cmd;
    sequence->instructions[idx].reg_dest = reg_dest;
    sequence->instructions[idx].reg_src = reg_src;
    sequence->instructions[idx].imm = imm;
    
    sequence->instructions[idx].flags_allow = flags_allow;
    sequence->instructions[idx].flags_deny = flags_deny;
    sequence->instructions[idx].flags_target = flags_target;
    
    Py_RETURN_NONE;
}



PyObject * testmod_func_add_instruction(PyObject *self, PyObject *args) 
{
    InstructionSequence * sequence;
    int idx;
    int cmd;
    int reg_dest;
    int reg_src;
    int imm;
    int flags_allow;
    int flags_deny;
    int flags_target;
    
    // Получаем структуру из Python
    if (!PyArg_ParseTuple(args, "Oiiiiiii", &sequence, &cmd, &reg_dest, &reg_src, &imm, &flags_allow, &flags_deny, &flags_target)) // O - объект данных
        Py_RETURN_NONE;
        
    if (sequence->count >= MaxInstructions)
        Py_RETURN_NONE;
    
    idx = sequence->count;
    
    sequence->instructions[idx].cmd = cmd;
    sequence->instructions[idx].reg_dest = reg_dest;
    sequence->instructions[idx].reg_src = reg_src;
    sequence->instructions[idx].imm = imm;
    
    sequence->instructions[idx].flags_allow = flags_allow;
    sequence->instructions[idx].flags_deny = flags_deny;
    sequence->instructions[idx].flags_target = flags_target;
    
    sequence->count++;
    
    Py_RETURN_NONE;
}



PyObject * testmod_vcpu_step(PyObject *self, PyObject *args) 
{
    VCPU * vcpu;
    InstructionSequence * sequence;
    Field * field;
    UnitVarStruct * u;
    int maxsteps;
    
    if (!PyArg_ParseTuple(args, "OOOOi", &vcpu, &sequence, &field, &u, &maxsteps)) // O - объект данных
        Py_RETURN_NONE;
        
    int res = vcpu_step(vcpu, sequence, field, u, maxsteps);
    
    return Py_BuildValue("i", res);
}

PyObject * testmod_vcpu_set_callback(PyObject *self, PyObject *args)
{
    PyObject * temp_f;
    PyObject * temp_cb;
    VCPU * vcpu;
    int res;
    
    if (!PyArg_ParseTuple(args, "OOO", &vcpu, &temp_f, &temp_cb))
        Py_RETURN_NONE;
    
    res = VCPU_init_callback(vcpu, temp_f, temp_cb);
    
    return Py_BuildValue("i", res);
}



// ===================================================================================

PyObject * testmod_field_set_object(PyObject *self, PyObject *args) 
{
    Field * field;
    void * obj;
    int obj_t;
    int x;
    int y;
    
    // Получаем структуру из Python
    if (!PyArg_ParseTuple(args, "OiiOi", &field, &x, &y, &obj, &obj_t)) // O - объект данных
        Py_RETURN_NONE;
    
    if ((x >= 0) && (x < field->width) && (y >= 0) && (y < field->height))
    {
        int offset = y * field->width + x;
        field->cells[offset].obj = obj;
        field->cells[offset].type = obj_t;
    }
    //printf("C get test_st: val1 - %d, val2 - %f, val3 - %d\n", st->val1++, st->val2++, st->val3++);
    Py_RETURN_NONE;
}


PyObject * testmod_field_get_object(PyObject *self, PyObject *args) 
{
    Field * field;
    void * obj;
    int obj_t;
    int x;
    int y;
    
    // Получаем структуру из Python
    if (!PyArg_ParseTuple(args, "Oii", &field, &x, &y)) // O - объект данных
        Py_RETURN_NONE;
    
    if ((x >= 0) && (x < field->width) && (y >= 0) && (y < field->height))
    {
        int offset = y * field->width + x;
        obj = field->cells[offset].obj;
        if (obj == NULL)
            Py_RETURN_NONE;
        
        return Py_BuildValue("O", obj);
        
    }
    //printf("C get test_st: val1 - %d, val2 - %f, val3 - %d\n", st->val1++, st->val2++, st->val3++);
    Py_RETURN_NONE;
}


PyObject * testmod_field_get_object_type(PyObject *self, PyObject *args) 
{
    Field * field;
    void * obj;
    int obj_t;
    int x;
    int y;
    
    // Получаем структуру из Python
    if (!PyArg_ParseTuple(args, "Oii", &field, &x, &y)) // O - объект данных
        Py_RETURN_NONE;
    
    if ((x >= 0) && (x < field->width) && (y >= 0) && (y < field->height))
    {
        int offset = y * field->width + x;
        obj_t = field->cells[offset].type;

        return Py_BuildValue("i", obj_t);
    }
    //printf("C get test_st: val1 - %d, val2 - %f, val3 - %d\n", st->val1++, st->val2++, st->val3++);
    Py_RETURN_NONE;
}

PyObject * testmod_field_get_object_subtype(PyObject *self, PyObject *args) 
{
    Field * field;
    int obj_st;
    int x;
    int y;
    
    // Получаем структуру из Python
    if (!PyArg_ParseTuple(args, "Oii", &field, &x, &y)) // O - объект данных
        Py_RETURN_NONE;
    
    if ((x >= 0) && (x < field->width) && (y >= 0) && (y < field->height))
    {
        int offset = y * field->width + x;
        obj_st = field->cells[offset].subtype;

        return Py_BuildValue("i", obj_st);
    }
    //printf("C get test_st: val1 - %d, val2 - %f, val3 - %d\n", st->val1++, st->val2++, st->val3++);
    Py_RETURN_NONE;
}
