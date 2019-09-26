#include "../include/animorph/Vertex.h"

using namespace Animorph;

void Vertex::addSharedFace(int shared_face)
{
	shared_faces_vector.push_back(shared_face);
}

std::vector<int> &Vertex::getSharedFaces() { return shared_faces_vector; }

origVertex::origVertex(std::vector<int> &i_faceVerts,
                       std::vector<int> &i_edgeVerts)
{
	valence = i_edgeVerts.size();
	fvalence = i_faceVerts.size();
	faceVerts = i_faceVerts;
	edgeVerts = i_edgeVerts;
}
