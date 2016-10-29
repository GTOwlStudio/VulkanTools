#pragma once
#include <vector>
#include <glm\glm.hpp>
#include "MeshHelper.h"

struct Vertex {
	Vertex(float px, float py, float pz) { x = px; y = py; z = pz; }
	float x, y, z;
};

struct Cell {
public:
	Vertex vertices[4];
	uint32_t indices[6] = { 0,1,2,2,3,0 };
	void indicesSwitch() {
		if (indices[0]==0) {
			indices[0] = 3;
			indices[3] = 1;
		}
		else {
			indices[0] = 0;
			indices[3] = 2;
		}
	};
};

class CMesh
{
public:
	CMesh();
	~CMesh();
	void addVertex(glm::vec3 vertex); //add Vertex
	void deleteVertex(uint32_t a);
	void deleteEdge(uint32_t a, uint32_t b); // Delete the vertices
	void addEdge(uint32_t a, uint32_t b, glm::vec3 v); //Add an Edge beetween a and b and move it along v
	void insertEdge(uint32_t a, uint32_t b);// Insert an edge between a and b
	
	//void createFace(uint32_t a, uint32_t b, uint32_t c, uint32_t d); //Create a face with the vertices a,b,c,d
protected:
	std::vector<glm::vec3> m_vertices;
	std::vector<uint32_t> m_indices;

};

