#pragma once

#include <string>
#include <vulkan\vulkan.h>
#include <glm\glm.hpp>
#include <fstream>

namespace helper {
	
	std::string flagsToString(VkBufferUsageFlags flags, std::string sufix = "", std::string prefix = " | ");
	template<typename T>
	T bufferXY(T* buf, uint32_t size, uint32_t width, uint32_t x, uint32_t y);
	std::string arrayToString(glm::vec3* arr, uint32_t size);
	void stringToFile(std::string filename, std::string str, bool append = true);

	template<typename T>
	T bufferXY(T * buf, uint32_t size, uint32_t width, uint32_t x, uint32_t y)
	{
		if (y*width+x>size) {
			return T();
		}
		return buf[y*width + x];
	}

}