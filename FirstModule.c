#define _CRT_SECURE_NO_WARNINGS
#define PY_SSIZE_T_CLEAN
#include <Python.h>

static double rhs(double x)
{
    return 1.0 / x;
}

/*
 * Simulate using an RHS function that is written in C.
 */
static PyObject*
simulate_0(PyObject* self, PyObject* args)
{
    long i;
    long n;
    double sum;

    /* Parse input arguments (get value of n) */
    if (!PyArg_ParseTuple(args, "l", &n)) {
        /* Set a nice error string for the user */
        PyErr_SetString(PyExc_Exception, "Incorrect input arguments.");
        /* Return 0 (or NULL) to indicate an error */
        return 0;
    }

    /* Run the "simulation" (just a for loop) */
    sum = 0;
    for (i = 1; i <= n; i++) {
        sum += rhs((double)i);
    }

    /* Return the result */
    return PyFloat_FromDouble(sum);
}

//*
//*Simulate using an RHS function that is written in Python.
//* /
static PyObject*
simulate_1(PyObject* self, PyObject* args)
{
    long i;
    long n;
    double sum;
    PyObject* function;
    PyObject* argument;
    PyObject* result;

    /* Parse input arguments:
      - value of n
      - python function to call
    */
    if (!PyArg_ParseTuple(args, "lO", &n, &function)) {
        PyErr_SetString(PyExc_Exception, "Incorrect input arguments.");
        return 0;
    }

    /* Run the "simulation" (just a for loop) */
    sum = 0;
    for (i = 1; i <= n; i++) {
        /* Create Python float */
        argument = PyFloat_FromDouble((double)i);

        /* Call Python function */
        result = PyObject_CallFunctionObjArgs(function, argument, NULL);

        /* Update the sum */
        sum += PyFloat_AsDouble(result);

        /* Tell Python's garbage collector that we no longer need the created objects in argument and result */
        Py_DECREF(argument);
        Py_DECREF(result);
    }

    /* Return the result */
    return PyFloat_FromDouble(sum);
}

static PyMethodDef ForLoopMethods[] = {
    {"simulate_0",  simulate_0, METH_VARARGS, "Runs a simulation with a C RHS."},
    {"simulate_1",  simulate_1, METH_VARARGS, "Runs a simulation with a Python RHS."},
    /*{"simulate_2",  simulate_2, METH_VARARGS, "Runs a simulation with an llvmlite RHS, called via Python."},*/
    {NULL}
};

static struct PyModuleDef for_loop_module = {
    PyModuleDef_HEAD_INIT,
    "ForLoopModule",       /* The module name (in Python) */
    "A module with a for loop", /* Module docstring. */
    -1,                 /* See the docs for this one! */
    ForLoopMethods    /* This module's methods. */
};

PyMODINIT_FUNC
PyInit_ForLoopModule(void)
{
    return PyModule_Create(&for_loop_module);
}