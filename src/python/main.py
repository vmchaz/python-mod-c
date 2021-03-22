#!/usr/bin/python3
#-*- coding: utf-8 -*-

import sys
import time

# пути до модуля testmod
#sys.path.append('.')
#sys.path.append('lib/')
sys.path.append('../../lib/')

import testmod 
 
print("Dir:")
print(dir(testmod))
    

c = testmod.VCPU(1)
u = testmod.UnitVarStruct(1, 1000, 0, 0, 0)
s = testmod.InstructionSequence(0)
s1 = testmod.InstructionSequence(0)

a = testmod.Animal()


print("adding instructions...")

testmod.add_instruction(s, 3, 0, 0, 200, 0, 0, 0)
testmod.add_instruction(s, 3, 1, 0, 50,  0, 0, 0)
testmod.add_instruction(s, 7, 0, 1, 0,   0, 0, 0)
testmod.add_instruction(s, 5, 0, 0, 0,   0, 0, 0)

print(s.count)
testmod.animal_set_instruction_seq(a, 0, s);
testmod.animal_get_instruction_seq(a, 0, s1);
print(s1.count)

for i in range(s1.count):
    q1 = testmod.get_instruction(s1, i)
    print(q1)


def run_and_print(vcpu, sequence, unitvarstruct):
    testmod.vcpu_run(vcpu, sequence, unitvarstruct, 1)
    print(vcpu.ip, "    ", vcpu.accumulator, "[", vcpu.r0, vcpu.r1, vcpu.r2, vcpu.r3, vcpu.r4, vcpu.r5, vcpu.r6, vcpu.r7, vcpu.stop_flag, "]")
    
def run_until_stop_and_print(vcpu, sequence, unitvarstruct):
    #print(vcpu.ip, "    ", vcpu.accumulator, "[", vcpu.r0, vcpu.r1, vcpu.r2, vcpu.r3, vcpu.r4, vcpu.r5, vcpu.r6, vcpu.r7, vcpu.stop_flag, "]")
    print(testmod.vcpu_get_state(vcpu))
    testmod.vcpu_run(vcpu, sequence, unitvarstruct, 0)
    #print(vcpu.ip, "    ", vcpu.accumulator, "[", vcpu.r0, vcpu.r1, vcpu.r2, vcpu.r3, vcpu.r4, vcpu.r5, vcpu.r6, vcpu.r7, vcpu.stop_flag, "]")
    print(testmod.vcpu_get_state(vcpu))


run_until_stop_and_print(c, s, u)
