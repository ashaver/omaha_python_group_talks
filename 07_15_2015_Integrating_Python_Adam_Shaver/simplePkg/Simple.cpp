#include <python2.7/Python.h>  //Contains the spec for the Python API, pyObject, etc.

//Function 1
static PyObject * answer_to_everything(PyObject *self, PyObject *args)
{
    return PyLong_FromLong(42); // convert to Python object of a type
}

//Function 2
static PyObject * missing_from_answer_to_everything(PyObject *self, PyObject *args)
{
    int sts;
    if (!PyArg_ParseTuple(args, "i", &sts)) //"((ii)(ii))(ii)", is f((0, 0), (400, 300)), (10, 10))
        return NULL;                        //"s|si", is f('wer','d', 10) or f('cmd')
    sts = 42 - sts;
    PyObject * ret = PyLong_FromLong(sts); // convert to Python object of a type
    return ret;
}

// Static that maps C names to python and outlines the variables
static PyMethodDef SimpleMethods[] = {
    {"what_is_the_answer",  answer_to_everything, METH_VARARGS,
     "Gets The Answer."}, 
    {"missing_answer",  missing_from_answer_to_everything, METH_VARARGS,
     "Finds what you're missing."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};



// Registration of the functions and generation of the module
PyMODINIT_FUNC
initSimple(void)  // MUST be named "initFoo" for a library with name of "Foo"
{
    (void) Py_InitModule("Simple", SimpleMethods);
}