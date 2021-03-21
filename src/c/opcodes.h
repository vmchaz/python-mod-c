#ifndef _OPCODES_H_
#define _OPCODES_H_
#define cmdNOP 1
#define cmdMOV_RR 2
#define cmdMOV_RI 3
#define cmdMOV_RA 4
#define cmdMOV_AR 5
#define cmdMOV_AI 6
#define cmdADD_RR 7
#define cmdADD_RI 8
#define cmdADD_RA 9
#define cmdADD_AR 10
#define cmdADD_AI 11
#define cmdSUB_RR 12
#define cmdSUB_RI 13
#define cmdSUB_RA 14
#define cmdSUB_AR 15
#define cmdSUB_AI 16
#define cmdINC_R 17
#define cmdINC_A 18
#define cmdDEC_R 19
#define cmdDEC_A 20
#define cmdEQUALS_RR 21
#define cmdEQUALS_RI 22
#define cmdEQUALS_RA 23
#define cmdEQUALS_AR 24
#define cmdEQUALS_AI 25
#define cmdNEQUALS_RR 26
#define cmdNEQUALS_RI 27
#define cmdNEQUALS_RA 28
#define cmdNEQUALS_AR 29
#define cmdNEQUALS_AI 30
#define cmdGREATER_RR 31
#define cmdGREATER_RI 32
#define cmdGREATER_RA 33
#define cmdGREATER_AR 34
#define cmdGREATER_AI 35
#define cmdLESS_RR 36
#define cmdLESS_RI 37
#define cmdLESS_RA 38
#define cmdLESS_AR 39
#define cmdLESS_AI 40
#define cmdSET_ACTION_STAND 41
#define cmdSET_ACTION_EAT 42
#define cmdSET_ACTION_FORWARD 43
#define cmdSET_ACTION_TURN_LEFT 44
#define cmdSET_ACTION_TURN_RIGHT 45
#define cmdSET_ACTION_TURN_BACKWARD 46
#define cmdSET_ACTION_TURN_MOVE_LEFT 47
#define cmdSET_ACTION_TURN_MOVE_RIGHT 48
#define cmdSET_ACTION_TURN_MOVE_BACKWARD 49
#define cmdDETECT_OBSTACLE 50
#define cmdDETECT_FOOD 51
#define cmdDETECT_HAZARD 52
#define cmdDETECT_PREDATOR 53
#define cmdDETECT_PREY 54
#define cmdDETECT_OBSTACLE_FAR 55
#define cmdDETECT_FOOD_FAR 56
#define cmdDETECT_HAZARD_FAR 57
#define cmdDETECT_PREDATOR_FAR 58
#define cmdDETECT_PREY_FAR 59
#define cmdSET_FLAG 60
#define cmdRESET_FLAG 61
#define cmdJMP_REL_R 62
#define cmdJMP_REL_I 63
#define cmdJMP_REL_A 64
#define cmdJMP_ABS_R 65
#define cmdJMP_ABS_I 66
#define cmdJMP_ABS_A 67
#endif
