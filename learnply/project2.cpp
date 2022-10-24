#include "project2.h"
#include "polyhedron.h"
#include "iostream"
#include "GL/freeglut.h"
#include <vector>
#include <set>
#include "polyline2.h"

extern Polyhedron* poly;
extern std::vector<Polyline2> polylines;

double findMin() {
	double min = poly->vlist[0]->scalar;
	for (int i = 1; i < poly->nverts; i++) {
		double vertexScalar = poly->vlist[i]->scalar;
		if (vertexScalar < min) {
			min = vertexScalar;
		}
	}
	return min;
}

double findMax() {
	double max = poly->vlist[0]->scalar;
	for (int i = 1; i < poly->nverts; i++) {
		double vertexScalar = poly->vlist[i]->scalar;
		if (vertexScalar > max) {
			max = vertexScalar;
		}
	}
	return max;
}

icVector3 convertHSVToRGB(icVector3 hsv) {
	double h = hsv.x;
	double s = hsv.y;
	double v = hsv.z;
	double r, g, b;

	double c = s * v;
	double x = c * (1 - abs(fmod(h / 60.0, 2) - 1));
	double m = v - c;

	if (h >= 0 && h < 60) {
		r = c, g = x, b = 0;
	}
	else if (h >= 60 && h < 120) {
		r = x, g = c, b = 0;
	}
	else if (h >= 120 && h < 180) {
		r = 0, g = c, b = x;
	}
	else if (h >= 180 && h < 240) {
		r = 0, g = x, b = c;
	}
	else if (h >= 240 && h < 300) {
		r = x, g = 0, b = c;
	}
	else {
		r = c, g = 0, b = x;
	}

	return icVector3(r + m, g + m, b + m);
}

icVector3 convertRGBToHSV(icVector3 rgb) {
	double r = rgb.x;
	double g = rgb.y;
	double b = rgb.z;
	double h, s, v;

	double cmax = std::max(r, std::max(g, b));
	double cmin = std::min(r, std::min(g, b));
	double diff = cmax - cmin;

	if (cmax == cmin) {
		h = 0;
	} 
	else if (cmax == r) {
		h = fmod(60 * ((g - b) / diff) + 360, 360);
	}
	else if (cmax == g) {
		h = fmod(60 * ((b - r) / diff) + 120, 360);
	}
	else if (cmax == b) {
		h = fmod(60 * ((r - g) / diff) + 240, 360);
	}

	if (cmax == 0) {
		s = 0;
	}
	else {
		s = (diff / cmax);
	}

	v = cmax;

	return icVector3(h, s, v);

}

void part2A() {
	polylines.clear();
	double numberOfContours = 20.0;
	for (int i = 0; i < numberOfContours; i++) {
		std::list<Polyline2> edges = marchingSquare(*poly, i * 10);
		std::vector<Polyline2> newPolylines = makePolylineFromEdges(edges);
		for (auto polyline : newPolylines) {
			polyline.rgb = icVector3(1, 0, 0);
			polylines.push_back(polyline);
		}
	}
	glutPostOverlayRedisplay();
}

void part2B() {
	polylines.clear();
	double numberOfContours = 20.0;
	for (int i = 0; i < numberOfContours; i++) {
		std::list<Polyline2> edges = marchingSquare(*poly, i * 10);
		std::vector<Polyline2> newPolylines = makePolylineFromEdges(edges);
		for (auto polyline : newPolylines) {
			icVector3 redRGB(1.0, 0.0, 0.0);
			icVector3 blueRGB(0.0, 0.0, 1.0);
			icVector3 redHSV = convertRGBToHSV(redRGB);
			icVector3 blueHSV = convertRGBToHSV(blueRGB);

			double redScalar = i / numberOfContours;
			double blueScalar = (20 - i) / numberOfContours;
			icVector3 newHSV = (redHSV * redScalar) + (blueHSV * blueScalar);
			polyline.rgb = convertHSVToRGB(newHSV);

			polylines.push_back(polyline);
		}
	}
	glutPostOverlayRedisplay();
}

void part2C() {

	double min = findMin();
	double max = findMax();

	for (int i = 0; i < poly->nverts; i++) {
		auto& vertex = poly->vlist[i];
		double vertexScalar = vertex->scalar;
		double height = (vertexScalar - min) / (max - min);
		vertex->z = 10 * height;
	}

	polylines.clear();
	double numberOfContours = 20.0;
	for (int i = 0; i < numberOfContours; i++) {
		std::list<Polyline2> edges = marchingSquare(*poly, i * 10);
		std::vector<Polyline2> newPolylines = makePolylineFromEdges(edges);
		for (auto polyline : newPolylines) {
			polyline.rgb = icVector3(1, 0, 0);
			polylines.push_back(polyline);
		}
	}
	glutPostOverlayRedisplay();
}

void part2D() {
	double min = findMin();
	double max = findMax();

	for (int i = 0; i < poly->nverts; i++) {
		auto& vertex = poly->vlist[i];
		double vertexScalar = vertex->scalar;
		double height = (vertexScalar - min) / (max - min);
		vertex->z = 10 * height;
	}

	polylines.clear();
	double numberOfContours = 20.0;
	for (int i = 0; i < numberOfContours; i++) {
		std::list<Polyline2> edges = marchingSquare(*poly, i * 10);
		std::vector<Polyline2> newPolylines = makePolylineFromEdges(edges);
		for (auto polyline : newPolylines) {
			icVector3 redRGB(1.0, 0.0, 0.0);
			icVector3 blueRGB(0.0, 0.0, 1.0);
			icVector3 redHSV = convertRGBToHSV(redRGB);
			icVector3 blueHSV = convertRGBToHSV(blueRGB);

			double redScalar = i / numberOfContours;
			double blueScalar = (20 - i) / numberOfContours;
			icVector3 newHSV = (redHSV * redScalar) + (blueHSV * blueScalar);
			polyline.rgb = convertHSVToRGB(newHSV);

			polylines.push_back(polyline);
		}
	}
	glutPostOverlayRedisplay();
}

std::list<Vertex> getCriticalPoints() {
	std::list<Vertex> criticalPoints;
	enum Relationship {min, max};

	for (int i = 0; i < poly->nverts; i++) {
		std::set<Relationship> relationships;
		Vertex* potentialCriticalPoint = poly->vlist[i];
		for (int j = 0; j < potentialCriticalPoint->nquads; j++) {
			Quad* quad = potentialCriticalPoint->quads[j];
			for (int k = 0; k < 4; k++) {
				Vertex* vertex = quad->verts[k];
				if (potentialCriticalPoint->scalar < vertex->scalar) {
					relationships.insert(min);
				}
				else if (potentialCriticalPoint->scalar > vertex->scalar) {
					relationships.insert(max);
				}				
			}
		}
		if (relationships.size() == 1) {
			criticalPoints.push_back(*potentialCriticalPoint);
		}
	}

	for (int i = 0; i < poly->nquads; i++) {
		Quad* quad = poly->qlist[i];
		Vertex* x2y2 = quad->verts[0];
		Vertex* x1y2 = quad->verts[1];
		Vertex* x1y1 = quad->verts[2];
		Vertex* x2y1 = quad->verts[3];

		double x1 = x1y2->x;
		double x2 = x2y2->x;
		double y1 = x1y1->y;
		double y2 = x1y2->y;

		double x1y1Scalar = x1y1->scalar;
		double x1y2Scalar = x1y2->scalar;
		double x2y1Scalar = x2y1->scalar;
		double x2y2Scalar = x2y2->scalar;

		double x0 = (x2 * x1y1Scalar - x1 * x2y1Scalar - x2 * x1y2Scalar + x1 * x2y2Scalar) / (x1y1Scalar - x2y1Scalar - x1y2Scalar + x2y2Scalar);
		double y0 = (y2 * x1y1Scalar - y2 * x2y1Scalar - y1 * x1y2Scalar + y1 * x2y2Scalar) / (x1y1Scalar - x2y1Scalar - x1y2Scalar + x2y2Scalar);

		bool criticalPoint = true;

		if (x0 > x1 && x0 < x2 && y0 > y1 && y0 < y2) {
			double zAverage = (x2y2->z + x1y2->z + x2y1->z + x2y2->z) / 4;
			criticalPoints.push_back(Vertex(x0, y0, zAverage));
		}
	}
	return criticalPoints;
}

void part3B() {
	
}