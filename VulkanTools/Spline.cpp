#include "Spline.h"



CSpline::CSpline(glm::vec3 a, glm::vec3 b)
{
	addPoint(a, 1);
	addPoint(b, 1);
}


CSpline::~CSpline()
{
}

void CSpline::addPoint(glm::vec3 p, float weight)
{
	m_control.push_back(p);
	m_indices.push_back(m_control.size()-1);
	m_weight.push_back(weight);
}

void CSpline::movePoint(uint32_t id, glm::vec3 value)
{
	if (id<m_control.size()) {
		m_control[m_indices[id]] = value;
	}
}

void CSpline::insertPoint(uint32_t a, uint32_t b, float weight)
{
	if ((a||b)>m_control.size()-1) {
		return;
	}
	glm::vec3 npc = (m_control[a]+m_control[b])/2.0f;//New Point Coordinate
	
	m_control.push_back(npc);
	m_weight.push_back(weight);
	
	m_indices.push_back(0);
	for (size_t i = m_indices.size()-1; i > a;i--) {
		m_indices[i] = m_indices[i - 1];
	}
	m_indices[b] = m_control.size() - 1;
}

void CSpline::generateSpline(uint32_t subdivision)
{
	m_splines.resize(0);
	glm::vec3 tmp;
	for (float t = 0; t < 1;t+=(float(1.0f/subdivision))) {
		tmp = glm::vec3(0.0f,0.0f,0.0f);
		for (size_t i = 0; i < m_indices.size();i++) {
			tmp += mathutil::Bp(m_indices.size()-1, i, t)*m_control[m_indices[i]];
		}
		m_splines.push_back(tmp);
	}
}

std::string CSpline::dev_getS()
{
	return helper::arrayToString(m_splines.data(),m_splines.size());
}

std::string CSpline::dev_getL()
{
	return helper::arrayToString(m_control.data(), m_control.size());
}
