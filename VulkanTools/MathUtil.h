#pragma once
#include <stdint.h>
#include <math.h>
namespace mathutil
{ 
	uint32_t factorial(uint32_t n);

	float binomial(uint32_t n, uint32_t k);


	float Bp(uint32_t n, uint32_t i, float u);
}