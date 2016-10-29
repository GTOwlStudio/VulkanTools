#include "Mesh.h"



CMesh::CMesh()
{
}


CMesh::~CMesh()
{
}

void CMesh::insertEdge(uint32_t a, uint32_t b) {
	if (!meshhelper::isAnEdge(a,b,m_indices)) { // Check if there is not already an edge
		m_indices.push_back(a);
		m_indices.push_back(b);
	}
}

void CMesh::addEdge(uint32_t a, uint32_t b, glm::vec3 v)
{
	if (!meshhelper::isAnEdge(a, b, m_indices)) { return; }
	m_vertices.push_back(m_vertices[a]+v);
	m_vertices.push_back(m_vertices[b]+v);
	m_indices.push_back(m_vertices.size()-2);
	m_indices.push_back(m_vertices.size() - 1);
}

