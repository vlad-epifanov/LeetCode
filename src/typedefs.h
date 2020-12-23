#pragma once

#include <string>
#include <vector>
#include <iostream>

#define EXPORT_SYM __declspec(dllexport)

using Graph = std::vector<std::vector<int>>;
using Vec2D = std::vector<std::vector<int>>;
using Vec = std::vector<int>;