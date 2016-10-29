#pragma once
#include <stdint.h>
#include <vector>
#include <vulkan\vulkan.h>
#include "Helper.h"

struct group {
	VkBuffer buffer_id;
	std::vector<VkDeviceSize> offsets;
};

struct VirtualBuffer {
	
};

struct Buffer
{
	Buffer(uint32_t psize, VkBufferUsageFlags pFlags) { size = psize; flags = pFlags; }
	size_t size;
	uint32_t id;
	VkBufferUsageFlags flags;

};

class CMemoryManager
{
public:
	CMemoryManager();
	~CMemoryManager();
	//void requestMemory(uint32_t size);
	void allocBuffer(uint32_t s,VkBufferUsageFlags flags);
	void displayBuffers();

protected:
	std::vector<Buffer> buffers;
	std::vector<group> virtual_buffers;
};

