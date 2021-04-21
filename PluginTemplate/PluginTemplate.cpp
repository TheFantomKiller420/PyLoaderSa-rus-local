#include "PluginTemplate.h"
#include "CHud.h"

PyObject* CTest::Func(PyObject* self, PyObject* args)
{
    CHud::SetHelpMessage("TESTFUNC", false, false, false);
    return PyBool_FromLong(1);
}

extern "C" void DllExport RegisterPlugin(void)
{
    PyImport_AppendInittab("test", &CTest::Init);
}