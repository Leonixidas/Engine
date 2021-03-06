#pragma once
#pragma comment(lib,"xinput.lib")
#include "targetver.h"

#include <stdio.h>
#include <iostream> // std::cout
#include <sstream> // stringstream
#include <tchar.h>
#include <memory> // smart pointers
#include <vector>
#pragma warning(push)
#pragma warning (disable:4201)
#pragma warning (disable:26495)
#include "glm/glm.hpp"
#pragma warning(pop)


#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "Log.h" // Various logging functions