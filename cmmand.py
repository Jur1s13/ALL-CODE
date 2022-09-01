import time
import ForLoopModule
import numba
import ExpModule
import math
n = 100000
#Pure Python version
def rhs(x):
    return 1/x

x = 0
time_1 = time.perf_counter()
for i in range(1, 1+n):
    x += rhs(i)

time_2 = time.perf_counter()
print(time_2-time_1)
print(x)


#Pure C code
time_1 = time.perf_counter()
x = ForLoopModule.simulate_0(n)
time_2 = time.perf_counter()
print(time_2-time_1)
print(x)


#RHS in Python
time_1 = time.perf_counter()
x = ForLoopModule.simulate_1(n,rhs)
time_2 = time.perf_counter()
print(time_2-time_1)
print(x)


#Running RHS programs with numba
from numba import njit
@njit
def rhs(i):
    return 1/i

time_1 = time.perf_counter()
x = ForLoopModule.simulate_1(n,rhs)
time_2 = time.perf_counter()
print(time_2-time_1)
print(x)




#The Second Module
#Pure Python version
def rhs(i):
    global sum
    sum=0
    for i in range(1,101):
            sum += math.exp(1/(1+i))
    return sum

i = 0
time_1 = time.perf_counter()
for x in range(1, 1+n):
    i += rhs(x)

time_2 = time.perf_counter()
print(time_2-time_1)
print(i)


#Pure C code
time_1 = time.perf_counter()
i = ExpModule.simulate_4(n)
time_2 = time.perf_counter()
print(time_2-time_1)
print(i)


#RHS in Python
time_1 = time.perf_counter()
i = ExpModule.simulate_5(n,rhs)
time_2 = time.perf_counter()
print(time_2-time_1)
print(i)


#Running RHS programs with numba
from numba import njit
@njit
def rhs(i):
    sum = 0.000000000
    for i in range(1,101):
            sum += math.exp(1/(1+i))
    return sum

time_1 = time.perf_counter()
i = ExpModule.simulate_5(n,rhs)
time_2 = time.perf_counter()
print(time_2-time_1)
print(i)
