#pragma once
#define PY_SSIZE_T_CLEAN 
#define WIN32_LEAN_AND_MEAN
#include <Python.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <frameobject.h>
#include "plugin.h"
#include <filesystem>

namespace fs = std::filesystem;
constexpr const char* plugin_ver = "0.07";
extern size_t game_ticks;
extern std::ofstream flog;