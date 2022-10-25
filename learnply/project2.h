#include <list>
#include <vector>
#include "polyhedron.h"

void part2A();
void part2B();
void part2C();
void part2D();
void part3B();

class CriticalPoint {
public:
	icVector3 vector;
	int significance;
public:
	CriticalPoint(icVector3 newVector, int newSignificance) {
		vector = newVector;
		significance = newSignificance;
	}
};

std::list<CriticalPoint> getCriticalPoints();