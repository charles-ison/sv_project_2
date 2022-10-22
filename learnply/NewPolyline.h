#pragma once
#include "polyhedron.h"
#include <utility>
#include <vector>
#include <list>

class NewPolyline {
public:
	std::list<icVector3> vertices;
	icVector3 rgb = icVector3(1.0, 0.0, 0.0);
	double weight = 1.0;
	bool isNeighbor(const NewPolyline);
	bool merge(const NewPolyline);
};

void displayPolyline(std::vector<NewPolyline> polylines);