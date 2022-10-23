#pragma once
#include "polyline2.h"
#include "GL/glew.h"
#include <vector>
#define EPSILON 1.0e-5

bool Polyline2::isNeighbor(const Polyline2 polyline) {
	return (vertices.front() - polyline.vertices.front()).length() < EPSILON ||
		(vertices.front() - polyline.vertices.back()).length() < EPSILON ||
		(vertices.back() - polyline.vertices.front()).length() < EPSILON ||
		(vertices.back() - polyline.vertices.back()).length() < EPSILON;
}

bool Polyline2::merge(const Polyline2 polyline) {
	return true;
}

void displayPolylines(std::vector<Polyline2> polylines) {
	glDisable(GL_LIGHTING);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	for (Polyline2 polyline : polylines) {
		glLineWidth(polyline.weight);
		glColor3f(polyline.rgb.entry[0], polyline.rgb.entry[1], polyline.rgb.entry[2]);
		glBegin(GL_LINE_STRIP);

		for (auto it = polyline.vertices.begin(); it != polyline.vertices.end(); it++) {
			glVertex3d(it->entry[0], it->entry[1], it->entry[2]);
		}
		glEnd();
	}

	glDisable(GL_BLEND);
	glLineWidth(1);
}
