#pragma once

#include <vector>
#include <algorithm>
#include "Mesh.h"

namespace meshhelper {

	bool isAnEdge(uint32_t a, uint32_t b, std::vector<uint32_t> indicesCollection);

}
