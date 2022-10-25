#include <list>
#include <vector>
#include "polyhedron.h"

void part2A();
void part2B();
void part2C();
void part2D();

class CriticalPoint {
public:
	icVector3 vector;
	icVector3 color;
	double scalar;
public:
	CriticalPoint(icVector3 newVector, icVector3 newColor, double newScalar) {
		color = newColor;
		vector = newVector;
		scalar = newScalar;
	}
};

std::list<CriticalPoint> getCriticalPoints();
void part3B(std::list<CriticalPoint> criticalPoints);