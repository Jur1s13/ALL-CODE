#define _CRT_SECURE_NO_WARNINGS
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <math.h>

static double rhs(double x)
{
	return exp(x);
}

static PyObject*
simulate_4(PyObject* self, PyObject* args)
{
    double i;
    double m;

    m = 0;
    for (i = 1.0; i <= 100; i++) {
        m = rhs((double)i);
        printf("%lf\n", m);
    }
    //printf("%lf\n", m);
    return 0;
}

static PyMethodDef ExpMethods[] = {
    {"simulate_4",  simulate_4, METH_VARARGS, "Runs a exp() simulation."},
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