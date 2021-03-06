#include "PyPool.h"
#include "CPools.h"
#include "../ScriptData.hpp"

PyObject* PyPool::GetScriptPool(PyObject* self, PyObject* args)
{
    size_t size = ScriptData::scripts->size();
    PyObject* list = PyList_New(size);
    size_t index = 0;

    for (auto it = ScriptData::scripts->begin(); it != ScriptData::scripts->end(); ++it)
    {
        PyList_SetItem(list, index, Py_BuildValue("s", (*it)->fileName.c_str()));
        ++index;
    }

    return list;
}

PyObject* PyPool::GetVehPool(PyObject* self, PyObject* args)
{
    size_t size = 0;

    for (CVehicle* pVeh : CPools::ms_pVehiclePool)
    {
        ++size;
    }

    PyObject* list = PyList_New(size);
    size_t index = 0;

    for (CVehicle* pVeh : CPools::ms_pVehiclePool)
    {
        PyList_SetItem(list, index, Py_BuildValue("i", CPools::GetVehicleRef(pVeh)));
        ++index;
    }

    return list;
}

PyObject* PyPool::GetPedPool(PyObject* self, PyObject* args)
{
    size_t size = 0;

    for (CPed* ele : CPools::ms_pPedPool)
    {
        ++size;
    }

    PyObject* list = PyList_New(size);
    size_t index = 0;

    for (CPed* ele : CPools::ms_pPedPool)
    {
        PyList_SetItem(list, index, Py_BuildValue("i", CPools::GetPedRef(ele)));
        ++index;
    }

    return list;
}

PyObject* PyPool::GetBuildingPool(PyObject* self, PyObject* args)
{
    size_t size = 0;

    for (CBuilding* ele : CPools::ms_pBuildingPool)
    {
        ++size;
    }

    PyObject* list = PyList_New(size);
    size_t index = 0;

    for (CBuilding* ele : CPools::ms_pBuildingPool)
    {
        PyList_SetItem(list, index, Py_BuildValue("i", ele));
        ++index;
    }

    return list;
}

PyObject* PyPool::GetObjectPool(PyObject* self, PyObject* args)
{
    size_t size = 0;

    for (CObject* ele : CPools::ms_pObjectPool)
    {
        ++size;
    }

    PyObject* list = PyList_New(size);
    size_t index = 0;

    for (CObject* ele : CPools::ms_pObjectPool)
    {
        PyList_SetItem(list, index, Py_BuildValue("i", CPools::GetObjectRef(ele)));
        ++index;
    }

    return list;
}