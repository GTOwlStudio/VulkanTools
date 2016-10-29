#include "MathUtil.h"

namespace mathutil {

	uint32_t factorial(uint32_t n)
	{
		uint32_t f = 1;
		for (uint32_t i = 1; i <= n; i++) {
			f *= i;
		}
		return f;
	}

	float binomial(uint32_t n, uint32_t k) {
		return (factorial(n) / (factorial(k)*factorial(n - k)));
	}

	float Bp(uint32_t n, uint32_t i, float u) {
		return binomial(n, i)*pow(u, i)*pow(1 - u, n - i);
	}

}