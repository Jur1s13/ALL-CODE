>>> import time
>>> import ForLoopModule
>>> n = 100000
>>> #Pure Python version
>>> def rhs(x):
...     return 1/x
...
>>> x = 0
>>> time_1 = time.perf_counter()
>>> for i in range(1, 1+n):
...     x += rhs(i)
...
>>> time_2 = time.perf_counter()
>>> print(time_2-time_1)
16.336515499999223
>>> print(x)
12.090146129863335
>>> #Pure C code
>>> time_1 = time.perf_counter()
>>> x = ForLoopModule.simulate_0(n)
>>> time_2 = time.perf_counter()
>>> print(time_2-time_1)
0.295579199999338
>>> print(x)
12.090146129863335
>>> #RHS in Python
>>> time_1 = time.perf_counter()
>>> x = ForLoopModule.simulate_1(n,rhs)
>>> time_2 = time.perf_counter()
>>> print(time_2-time_1)
0.25232810000306927
>>> print(x)
12.090146129863335
>>> import numba
>>> import time
>>> import ForLoopModule
>>> n = 100000
>>> from numba import njit
>>> @njit
... def rhs(i):
...     return 1/i
...
>>> time_1 = time.perf_counter()
>>> x = ForLoopModule.simulate_1(n,rhs)
>>> time_2 = time.perf_counter()
>>> print(time_2-time_1)
0.2513921999998274
>>> print(x)
12.090146129863335

>>> import time
>>> import ExpModule
>>> import math
>>> n = 100000
>>> #Pure Python version
>>> def rhs(i):
...     global sum
...     sum=0
...     for i in range(1,101):
...             sum += math.exp(1/(1+i))
...     return sum
...
>>> i = 0
>>> time_1 = time.perf_counter()
>>> for x in range(1, 1+n):
...     i += rhs(x)
...
>>>
>>> time_2 = time.perf_counter()
>>> print(time_2-time_1)
15.74078229999941
>>> print(i)
10455225.123837588
>>> #Pure C code
>>> time_1 = time.perf_counter()
>>> i = ExpModule.simulate_4(n)
>>> time_2 = time.perf_counter()
>>> print(time_2-time_1)
1.1261911000001419
>>> print(i)
10626058.289968556
>>> #RHS in Python
>>> time_1 = time.perf_counter()
>>> i = ExpModule.simulate_5(n,rhs)
>>> time_2 = time.perf_counter()
>>> print(time_2-time_1)
2.052577399997972
>>> print(i)
10455225.123837588
>>> import numba
>>> import time
>>> import math
>>> import ExpModule
>>> n = 100000
>>> from numba import njit
>>> @njit
... def rhs(i):
...     sum = 0.000000000
...     for i in range(1,101):
...             sum += math.exp(1/(1+i))
...     return sum
...
>>> time_1 = time.perf_counter()
>>> i = ExpModule.simulate_5(n,rhs)
>>> time_2 = time.perf_counter()
>>> print(time_2-time_1)
0.5374398000021756
>>> print(i)
10455225.123837588
