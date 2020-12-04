#pragma warning(disable: 4244)
#pragma warning(disable: 6031)
#pragma warning(disable: 26451)
#pragma warning(disable: 26495)
#pragma warning(disable: 26812)
#pragma warning(disable: 28020)

#define DLL_EXPORT extern "C" __declspec(dllexport)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <vector>

#include "submodules/cpp-httplib/httplib.h"
#include "submodules/ChaiScript/include/chaiscript/chaiscript.hpp"

#include "core/conversion.hpp"
#include "core/client.hpp"