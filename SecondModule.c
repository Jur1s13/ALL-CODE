#define _CRT_SECURE_NO_WARNINGS
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <math.h>

static double rhs(double i)
{
    double sum = 0;
    for (int i = 0; i < 100; i++) {
        sum += exp(1 / (1 + (double)i);
    }
    return sum;
}

static PyObject*
simulate_4(PyObject* self, PyObject* args)
{
    long n;
    double sum1;
    if (!PyArg_ParseTuple(args, "l", &n)) {
        PyErr_SetString(PyExc_Exception, "Incorrect input arguments.");
        return 0;
    }
    sum1 = 0;
    for (x = 1; x <= n; x++) {
        sum += rhs((double)x);
    }
    return PyFloat_FromDouble(sum1);
}

static PyObject*
simulate_5(PyObject* self, PyObject* args)
{
    long n;
    double sum1;
    PyObject* function;
    PyObject* argument;
    PyObject* result;

    if (!PyArg_ParseTuple(args, "lO", &n, &function)) {
        PyErr_SetString(PyExc_Exception, "Incorrect input arguments.");
        return 0;
    }

    sum1 = 0;
    for (x = 1; x <= n; x++) {
        argument = PyFloat_FromDouble((double)x);

        result = PyObject_CallFunctionObjArgs(function, argument, NULL);

        sum1 += PyFloat_AsDouble(result);

        Py_DECREF(argument);
        Py_DECREF(result);
    }

    return PyFloat_FromDouble(sum1);
}

static PyMethodDef ExpMethods[] = {
    {"simulate_4",  simulate_4, METH_VARARGS, "Runs a exp() simulation with a C RHS."},
    {"simulate_5",  simulate_5, METH_VARARGS, "Runs a exp() simulation with a Python RHS."},
    {NULL}
};

static struct PyModuleDef exp_module = {
    PyModuleDef_HEAD_INIT,
    "ExpModule",       
    "A module with a exp() calculation", 
    -1,                 
    ExpMethods    
};

PyMODINIT_FUNC
PyInit_ExpModule(void)
{
    return PyModule_Create(&exp_module);
}
