// File: TypeDefinition.hpp
// Author: Pablo Jimeno Domínguez

#pragma once
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <thread> 
#include <functional>
#include <list> 
#include <string>
#include <cstdlib>
#include <assert.h>
#include <cassert>
#include <vector>

using namespace std;

typedef int_fast16_t Id;

typedef short byte;

typedef struct SDL_Window   SDL_Window;
typedef void* SDL_GLContext;
class Render_Node;

namespace glt
{
    class Render_Node;
    class Model_Obj;
    class Camera;
    class Light;

}