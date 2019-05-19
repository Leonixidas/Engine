#pragma once

#ifndef PCH_H
#define PCH_H

// TODO: add headers that you want to pre-compile here
#include <stdio.h>
#include <iostream> // std::cout
#include <sstream> // stringstream
#include <tchar.h>
#include <memory> // smart pointers
#include <vector>

#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/glm.hpp>
#pragma warning(pop)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#endif //PCH_H
