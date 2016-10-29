#pragma once
#include <vector>
#include <glm\glm.hpp>
#include "MathUtil.h"
#include "Helper.h"
class CSpline
{
public:
	CSpline(glm::vec3 a, glm::vec3 b); //create a line from a to b
	~CSpline();
	void addPoint(glm::vec3 p, float weight = 1); //add a point at the end of the spline
	void movePoint(uint32_t id, glm::vec3 value);
	//void pointArray(glm::vec3* pa, size_t size,float weight=1);
	void insertPoint(uint32_t a, uint32_t b, float weight=1.0f); //Insert a point between a and b
	void generateSpline(uint32_t subdivision);// Generate B Spline
	std::string dev_getS();
	std::string dev_getL();

protected:
	std::vector<glm::vec3> m_control; //Control Line vertices
	std::vector<uint32_t> m_indices; // With vulkan with have to use indices
	std::vector<float> m_weight; // The weight of each vertices
	std::vector<glm::vec3> m_splines;


};

