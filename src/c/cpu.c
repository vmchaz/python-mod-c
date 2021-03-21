#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <stdbool.h>

#include "vcpu.h"
#include "instructionsequence.h"
#include "field.h"
#include "unitvarstruct.h"
#include "opcodes.h"




int check_register(int reg)
{
    return ((reg >= 0) && (reg < 16));
}

int check_flags_allow(int cpu_flags, int instruction_flags)
{
    if (instruction_flags == 0)
        return 1;
    
    if (cpu_flags & instruction_flags != 0)
        return 1;
        
    return 0;
}

int check_flags_deny(int cpu_flags, int instruction_flags)
{
    if (instruction_flags == 0)
        return 0;
    
    if (cpu_flags & instruction_flags != 0)
        return 1;
        
    return 0;
}

int set_register(VCPU * vcpu, int reg, int v)
{
    if ((reg < 0) | (reg > 15))
    {
        vcpu->error_flag = 1;
        return -1;
    }
        
    vcpu->registers[reg] = (v & 0xFF);
}

int get_register(VCPU * vcpu, int reg)
{
    if ((reg < 0) | (reg > 15))
    {
        vcpu->error_flag = 1;
        return -1;
    }
        
    return vcpu->registers[reg];
}

int set_acc(VCPU * vcpu, int v)
{
    vcpu->accumulator = (v & 0xFF);
}

int get_acc(VCPU * vcpu)
{
    return vcpu->accumulator;
}

int set_flags(VCPU * vcpu, int flags, bool v)
{
    flags = flags & 0x0F;
    
    vcpu->flags |= flags;
    if (!v)
        vcpu->flags ^= flags;
}




int safe_val(int v)
{
}

int lf_nop(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}





int lf_mov_ri(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_register(vcpu, instruction->reg_dest, instruction->imm);
    return 0;
}

int lf_mov_rr(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_register(vcpu, instruction->reg_dest, get_register(vcpu, instruction->reg_src));
    return 0;
}

int lf_mov_ra(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_acc(vcpu, get_register(vcpu, instruction->reg_src));
    return 0;
}

int lf_mov_ar(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_acc(vcpu, get_register(vcpu, instruction->reg_src));
    return 0;
}

int lf_mov_ai(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_acc(vcpu, get_register(vcpu, instruction->imm));
    return 0;
}





int lf_add_rr(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_register(vcpu, instruction->reg_dest, get_register(vcpu, instruction->reg_dest) + get_register(vcpu, instruction->reg_src));
    return 0;
}

int lf_add_ri(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_register(vcpu, instruction->reg_dest, get_register(vcpu, instruction->reg_dest) + instruction->imm);
    return 0;
}

int lf_add_ra(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_register(vcpu, instruction->reg_dest, get_register(vcpu, instruction->reg_dest) + get_acc(vcpu));
    return 0;
}

int lf_add_ar(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_acc(vcpu, get_acc(vcpu) + get_register(vcpu, instruction->reg_src));
    return 0;
}

int lf_add_ai(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_acc(vcpu, get_acc(vcpu) + instruction->imm);
    return 0;
}




int lf_sub_rr(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_register(vcpu, instruction->reg_dest, get_register(vcpu, instruction->reg_dest) - get_register(vcpu, instruction->reg_src));
    return 0;
}

int lf_sub_ri(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_register(vcpu, instruction->reg_dest, get_register(vcpu, instruction->reg_dest) - instruction->imm);
    return 0;
}

int lf_sub_ra(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_register(vcpu, instruction->reg_dest, get_register(vcpu, instruction->reg_dest) - get_acc(vcpu));
    return 0;
}

int lf_sub_ar(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_acc(vcpu, get_acc(vcpu) - get_register(vcpu, instruction->reg_src));
    return 0;
}

int lf_sub_ai(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_acc(vcpu, get_acc(vcpu) - instruction->imm);
    return 0;
}




int lf_equals_rr(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_register(vcpu, instruction->reg_dest) == get_register(vcpu, instruction->reg_src));
    return 0;
}

int lf_equals_ri(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_register(vcpu, instruction->reg_dest) == instruction->imm);
    return 0;
}

int lf_equals_ra(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_register(vcpu, instruction->reg_dest) == get_acc(vcpu));
    return 0;
}

int lf_equals_ar(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_acc(vcpu) == get_register(vcpu, instruction->reg_src));
    return 0;
}

int lf_equals_ai(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_acc(vcpu) == instruction->imm);
    return 0;
}




int lf_nequals_rr(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_register(vcpu, instruction->reg_dest) != get_register(vcpu, instruction->reg_src));
    return 0;
}

int lf_nequals_ri(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_register(vcpu, instruction->reg_dest) != instruction->imm);
    return 0;
}

int lf_nequals_ra(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_register(vcpu, instruction->reg_dest) != get_acc(vcpu));
    return 0;
}

int lf_nequals_ar(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_acc(vcpu) != get_register(vcpu, instruction->reg_src));
    return 0;
}

int lf_nequals_ai(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_acc(vcpu) != instruction->imm);
    return 0;
}





int lf_greater_rr(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_register(vcpu, instruction->reg_dest) > get_register(vcpu, instruction->reg_src));
    return 0;
}

int lf_greater_ri(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_register(vcpu, instruction->reg_dest) > instruction->imm);
    return 0;
}

int lf_greater_ra(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_register(vcpu, instruction->reg_dest) > get_acc(vcpu));
    return 0;
}

int lf_greater_ar(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_acc(vcpu) > get_register(vcpu, instruction->reg_src));
    return 0;
}

int lf_greater_ai(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_acc(vcpu) > instruction->imm);
    return 0;
}




int lf_less_rr(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_register(vcpu, instruction->reg_dest) < get_register(vcpu, instruction->reg_src));
    return 0;
}

int lf_less_ri(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_register(vcpu, instruction->reg_dest) < instruction->imm);
    return 0;
}

int lf_less_ra(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_register(vcpu, instruction->reg_dest) < get_acc(vcpu));
    return 0;
}

int lf_less_ar(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_acc(vcpu) < get_register(vcpu, instruction->reg_src));
    return 0;
}

int lf_less_ai(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, get_acc(vcpu) < instruction->imm);
    return 0;
}





int lf_set_action_stand(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_set_action_eat(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_set_action_forward(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_set_action_turn_left(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_set_action_turn_right(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_set_action_turn_backward(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_set_action_turn_move_left(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_set_action_turn_move_right(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_set_action_turn_move_backward(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}




int lf_detect_obstacle(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_detect_food(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_detect_hazard(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_detect_predator(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_detect_prey(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}




int lf_detect_obstacle_far(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_detect_food_far(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_detect_hazard_far(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_detect_predator_far(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}

int lf_detect_prey_far(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    return 0;
}




int lf_inc_r(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_register(vcpu, instruction->reg_dest, get_register(vcpu, instruction->reg_dest) + 1);
    return 0;
}

int lf_inc_a(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_acc(vcpu, get_acc(vcpu) + 1);
    return 0;
}

int lf_dec_r(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_register(vcpu, instruction->reg_dest, get_register(vcpu, instruction->reg_dest) - 1);
    return 0;
}

int lf_dec_a(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_acc(vcpu, get_acc(vcpu) - 1);
    return 0;
}

int lf_set_flags(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, 1);
    return 0;
}

int lf_reset_flags(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    set_flags(vcpu, instruction->flags_target, 0);
    return 0;
}


int lf_jmp_abs_r(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    vcpu->ip = get_register(vcpu, instruction->reg_src);
    vcpu->ip_mod_flag = 1;
    return 0;
}

int lf_jmp_abs_i(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    vcpu->ip = instruction->imm;
    vcpu->ip_mod_flag = 1;
    return 0;
}

int lf_jmp_abs_a(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    vcpu->ip = vcpu->accumulator;
    vcpu->ip_mod_flag = 1;
    return 0;
}

int lf_jmp_rel_r(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    vcpu->ip = ((128 + get_register(vcpu, instruction->reg_src)) % 256) - 128;
    vcpu->ip_mod_flag = 1;
    return 0;
}

int lf_jmp_rel_i(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    vcpu->ip = ((128 + instruction->imm) % 256) - 128;
    vcpu->ip_mod_flag = 1;
    return 0;
}

int lf_jmp_rel_a(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    vcpu->ip = ((128 + vcpu->accumulator) % 256) - 128;
    vcpu->ip_mod_flag = 1;
    return 0;
}




int vcpu_switch(VCPU * vcpu, Instruction * instruction, Field * field, UnitVarStruct * u)
{
    if (instruction->cmd == cmdNOP) {
        lf_nop(vcpu, instruction, field, u); }
        
    else if (instruction->cmd == cmdMOV_RI) {
        lf_mov_ri(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdMOV_RR) {
        lf_mov_rr(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdMOV_RA) {
        lf_mov_ra(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdMOV_AR) {
        lf_mov_ar(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdMOV_AI) {
        lf_mov_ai(vcpu, instruction, field, u); }
        
        
    else if (instruction->cmd == cmdADD_RI) {
        lf_add_ri(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdADD_RR) {
        lf_add_rr(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdADD_RA) {
        lf_add_ra(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdADD_AR) {
        lf_add_ar(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdADD_AI) {
        lf_add_ai(vcpu, instruction, field, u); }
        
        
        
    else if (instruction->cmd == cmdSUB_RI) {
        lf_sub_ri(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdSUB_RR) {
        lf_sub_rr(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdSUB_RA) {
        lf_sub_ra(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdSUB_AR) {
        lf_sub_ar(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdSUB_AI) {
        lf_sub_ai(vcpu, instruction, field, u); }
        
        
        
        
    else if (instruction->cmd == cmdEQUALS_RI) {
        lf_equals_ri(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdEQUALS_RR) {
        lf_equals_rr(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdEQUALS_RA) {
        lf_equals_ra(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdEQUALS_AR) {
        lf_equals_ar(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdEQUALS_AI) {
        lf_equals_ai(vcpu, instruction, field, u); }
        
        
        
    else if (instruction->cmd == cmdNEQUALS_RI) {
        lf_nequals_ri(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdNEQUALS_RR) {
        lf_nequals_rr(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdNEQUALS_RA) {
        lf_nequals_ra(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdNEQUALS_AR) {
        lf_nequals_ar(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdNEQUALS_AI) {
        lf_nequals_ai(vcpu, instruction, field, u); }
        
        

    else if (instruction->cmd == cmdGREATER_RI) {
        lf_greater_ri(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdGREATER_RR) {
        lf_greater_rr(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdGREATER_RA) {
        lf_greater_ra(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdGREATER_AR) {
        lf_greater_ar(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdGREATER_AI) {
        lf_greater_ai(vcpu, instruction, field, u); }
        
        
        
    else if (instruction->cmd == cmdLESS_RI) {
        lf_less_ri(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdLESS_RR) {
        lf_less_rr(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdLESS_RA) {
        lf_less_ra(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdLESS_AR) {
        lf_less_ar(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdLESS_AI) {
        lf_less_ai(vcpu, instruction, field, u); }
        
        
        
        
    else if (instruction->cmd == cmdSET_ACTION_STAND) {
        lf_set_action_stand(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdSET_ACTION_EAT) {
        lf_set_action_eat(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdSET_ACTION_FORWARD) {
        lf_set_action_forward(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdSET_ACTION_TURN_LEFT) {
        lf_set_action_turn_left(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdSET_ACTION_TURN_RIGHT) {
        lf_set_action_turn_right(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdSET_ACTION_TURN_BACKWARD) {
        lf_set_action_turn_backward(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdSET_ACTION_TURN_MOVE_LEFT) {
        lf_set_action_turn_move_left(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdSET_ACTION_TURN_MOVE_RIGHT) {
        lf_set_action_turn_move_right(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdSET_ACTION_TURN_MOVE_BACKWARD) {
        lf_set_action_turn_move_backward(vcpu, instruction, field, u); }
        
        
        
    else if (instruction->cmd == cmdDETECT_OBSTACLE) {
        lf_detect_obstacle(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdDETECT_FOOD) {
        lf_detect_food(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdDETECT_HAZARD) {
        lf_detect_hazard(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdDETECT_PREDATOR) {
        lf_detect_predator(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdDETECT_PREY) {
        lf_detect_prey(vcpu, instruction, field, u); }
        
        


    else if (instruction->cmd == cmdDETECT_OBSTACLE_FAR) {
        lf_detect_obstacle_far(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdDETECT_FOOD_FAR) {
        lf_detect_food_far(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdDETECT_HAZARD_FAR) {
        lf_detect_hazard_far(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdDETECT_PREDATOR_FAR) {
        lf_detect_predator_far(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdDETECT_PREY_FAR) {
        lf_detect_prey_far(vcpu, instruction, field, u); }
        
        
    else if (instruction->cmd == cmdINC_R) {
        lf_inc_r(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdDEC_R) {
        lf_dec_r(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdINC_A) {
        lf_inc_a(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdDEC_A) {
        lf_dec_a(vcpu, instruction, field, u); }
        
        
    else if (instruction->cmd == cmdSET_FLAG) {
        lf_set_flags(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdRESET_FLAG) {
        lf_reset_flags(vcpu, instruction, field, u); }
        
        
    else if (instruction->cmd == cmdJMP_ABS_R) {
        lf_jmp_abs_r(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdJMP_ABS_I) {
        lf_jmp_abs_i(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdJMP_ABS_A) {
        lf_jmp_abs_a(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdJMP_REL_R) {
        lf_jmp_rel_r(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdJMP_REL_I) {
        lf_jmp_rel_i(vcpu, instruction, field, u); }
    else if (instruction->cmd == cmdJMP_REL_A) {
        lf_jmp_rel_a(vcpu, instruction, field, u); }
        
        

    
}

int vcpu_step(VCPU * vcpu, InstructionSequence * sequence, Field * field, UnitVarStruct * u, int maxsteps)
{
    printf("VCPU:%p InstructionSequence:%p Field:%p UnitVarStruct:%p maxsteps:%d\n", vcpu, sequence, field, u, maxsteps);
    if ((vcpu->ip < 0) || (vcpu->ip >= sequence->count))
        return 1;
        
    if (vcpu->stop_flag)
        return 1;
        
    while ((maxsteps > 0) && (!vcpu->stop_flag) && (!vcpu->error_flag))
        
    {
        Instruction inst = sequence->instructions[vcpu->ip];
        
        vcpu->ip_mod_flag = 0;
        
        if (check_flags_allow(vcpu->flags, inst.flags_allow))
        {
            if (!check_flags_deny(vcpu->flags, inst.flags_deny))
            {
                vcpu_switch(vcpu, &inst, field, u);
            }
        }
        
        if (!vcpu->ip_mod_flag)
            vcpu->ip += 1;
        
        if ((vcpu->ip < 0) || (vcpu->ip >= sequence->count))
            vcpu->stop_flag = 1;
    }
}
