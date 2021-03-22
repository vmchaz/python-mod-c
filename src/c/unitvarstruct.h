#ifndef _UNITVARSTRUCT_H_
#define _UNITVARSTRUCT_H_

#include <Python.h>
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <structmember.h>


typedef struct {
    int id;
    int energy;
    int action;
    int action_p;
    int use_action_p;
    int x;
    int y;
    int direction;
} UnitVarStruct;

#endif
