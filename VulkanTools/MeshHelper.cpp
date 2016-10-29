#include "MeshHelper.h"

namespace meshhelper 
{
	bool isAnEdge(uint32_t a, uint32_t b, std::vector<uint32_t> indicesCollection)
	{
		if (a==b) {
			return false; //There is no need to look
		}
		uint32_t fa, fb; // We want a<b
		fa = std::min(a,b);
		fb = std::max(a,b);
		for (size_t i = 1; i < indicesCollection.size();i++) {
			if (indicesCollection[i]==b&&indicesCollection[i-1]==a) {
				return true;
			}
		}
		return false;
	}
}