#pragma once
#include "icVector.H"
#include <list>
#include <vector>

class Polyline2 {
	public:
		std::list<icVector3> vertices;
		icVector3 rgb = icVector3(1.0, 0.0, 0.0);
		double weight = 1.0;
		bool isNeighbor(const Polyline2 polyline);
		bool merge(const Polyline2 polyline);
};

void displayPolylines(std::vector<Polyline2> polylines);
