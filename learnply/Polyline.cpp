#include "Polyline.h"
#include "GL/glew.h"

bool POLYLINE::isNeighbor(const POLYLINE polyline) {

}

bool POLYLINE::merge(const POLYLINE polyline) {

}

void displayPolyline(std::vector<POLYLINE> polylines) {
	glDisable(GL_LIGHTING);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDisable(GL_BLEND);
}