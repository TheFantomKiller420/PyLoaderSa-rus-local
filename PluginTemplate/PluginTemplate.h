#pragma once
#define WIN32_LEAN_AND_MEAN 
#define DllExport   __declspec( dllexport )
#include <windows.h>
#include <Python.h>

extern "C" void DllExport RegisterPlugin(void);

class CTest
{
private:
    static PyObject* Func(PyObject* self, PyObject* args);
    static inline PyMethodDef Methods[] =
    {
        {"func", Func, METH_VARARGS},
        {} // sentinel, required at the end
    };
    static inline PyModuleDef Module = { PyModuleDef_HEAD_INIT, "test", NULL, -1, Methods, NULL, NULL, NULL, NULL };

public:
    static PyObject* Init(void)
    {
        return PyModule_Create(&Module);
    }

    CTest() = delete;
    CTest(CTest&) = delete;
};