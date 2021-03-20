#!/usr/bin/python3
#-*- coding: utf-8 -*-

import sys
import time

# пути до модуля testmod
sys.path.append('.')
sys.path.append('lib/')
sys.path.append('../../lib/')

import testmod 
 
###
## C
###

print("C API\n")
print("C\n")

start_time = time.time()


##
# Работа с функциями
##

print("Dir:")
print(dir(testmod))
    
print('Работа с функциями:')
print('ret func_hello: ', testmod.func_hello())
print('ret func_ret_int: ', testmod.func_ret_int(101))
print('ret func_ret_double: ', testmod.func_ret_double(12.123456789))
print('ret func_ret_str: ', testmod.func_ret_str('Hello!'))
print('ret func_many_args: ', testmod.func_many_args(15, 18.1617, "Many arguments!"))


##
# Работа с переменными
##

print('\nРабота с переменными:')
print('ret a: ', testmod.ModuleVarA)

# Изменяем значение переменной.
testmod.ModuleVarA = 22
print('new a: ', testmod.ModuleVarA)

print('ret b: ', testmod.ModuleVarB)

print('ret c: ', testmod.ModuleVarC)


##
# Работа со структурами
##

print('\nРабота со структурами:')

# Создаем структуру
st = testmod.DemoRec(100)
print("Dir DemoRec:")
print(dir(st))

print('st.id={}\nst.val1 = {}\nst.val2 = {}\nst.val3 = {}'.format(st.id, st.val1, st.val2, st.val3))
st = testmod.func_ret_struct(st)
print("ret func_ret_struct:")
print('st.id={}\nst.val1 = {}\nst.val2 = {}\nst.val3 = {}'.format(st.id, st.val1, st.val2, st.val3))

st = testmod.func_ret_struct(st)
print("ret func_ret_struct:")
print('st.id = {}\nst.val1 = {}\nst.val2 = {}\nst.val3 = {}'.format(st.id, st.val1, st.val2, st.val3))

for i in range(20):
    testmod.func_set_element(st, i, 1000+i)
    
l = []
for i in range(20):
    l.append(testmod.func_get_element(st, i))
    
print(l)

vcpu = testmod.VCPU(1)
u = testmod.UnitVarStruct(1, 1000, 0, 0, 0)
s = testmod.InstructionSequence(0)
f = testmod.Field(5, 5)
print(dir(vcpu))
print(dir(s))
print(dir(f))
print(dir(u))

# Вызывай метод print нашей структуры, только по скольку C частично ООП
# То нужно в этод метод передать указатель на нашу структуру
# st.print(st)


# Время работы
print("--- {} seconds ---".format((time.time() - start_time)))
