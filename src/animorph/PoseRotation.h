/* SPDX-License-Identifier: GPL-3.0-or-later */
/*
 *  Copyright (C) 2005-2007  MakeHuman Project
 *
 *  This program is free software; you  can  redistribute  it  and/or
 *  modify  it  under  the terms of the GNU General Public License as
 *  published by the Free Software Foundation; either  version  3  of
 *  the License, or (at your option) any later version.
 *
 *  This  program  is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the  implied  warranty  of
 *  MERCHANTABILITY  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software Foun-
 *  dation, Inc., 59 Temple Place, Suite 330, Boston,  MA  02111-1307
 *  USA
 *
 *  File: PoseRotation.h
 *  Project: MakeHuman <info@makehuman.org>, http://www.makehuman.org/
 *  Library: ANIMORPH
 *
 *  For individual developers look into the AUTHORS file.
 *
 */
#pragma once

#include <set>
#include <string>
#include <vector>

#include <iostream>
#include <sstream>

#include "FileReader.h"
#include "Matrix.h"
#include "util.h"

using std::set;
using std::string;
using std::vector;

namespace Animorph
{

struct PoseTargetData {
	int   vertex_number;
	float rotation;
};

typedef vector<int> UnsortedUsedVertex;

/*! \brief Represents the rotational data of a PoseTarget

This class can be loaded from files.

The format of PoseRotation file:
\verbatim
<int>,<float>
...
\endverbatim

Each line is read into a PoseTargetData struct and consists of a vertex_number
and a rotation angle in radians.

The filenames of these files end in ".rot".

The format of PoseRotation info file:
\verbatim
<int>,<int>,<int>,...
[X,Y,Z]
<float>,<float>
\endverbatim

The first line contains the centerVertexNumbers.
The second line indicates the axis.
The third line indicates minAngle and maxAngle.
Further lines are ignored.

The filenames of these files end in ".rot.info".

*/
class PoseRotation
{
public:
	vector<PoseTargetData> m_targetData;

	/// Used to calculate center
	vector<int> centerVertexNumbers;
	/// Will be used as parameter for Matrix::setRoation()
	RotateAxis axis;
	/// Set of all indices in the ".rot" file
	UnsortedUsedVertex modVertex;
	/// Currently unused
	bool hasCenter = false;
	/// Minimum angle in radians
	float minAngle = 0.0f;
	/// Maximum angle in radians
	float maxAngle = 0.0f;
	/// will be set to true by PoseTarget::calcNormalizations() if our
	/// (min|max)Angle != PoseTarget::(min|max)Angle
	bool normalize = false;
	// string inFilename;
	/* \brief "Category"? Currently always "00"
	 * First two characters of the filename, eg . "00" for "00_Z_LIMB_SPINE1.rot"
	 */
	string cat;

	/* \brief Centroid of centerVertexNumbers
	 * Is initialized by PoseTarget::calcRotationsCenteroids()
	 */
	glm::vec3 center;
	/// Limb rotation Type
	bool mbLimb;

	/*!
	 * \param filename the file with PoseTarget data to load
	 * \return true if file is found
	 * \return false if file isn't found
	 */
	bool load(const string & filename);

	const vector<int> &  getCenterVertexNumbers() { return centerVertexNumbers; }
	UnsortedUsedVertex & getModVertex() { return modVertex; }
	const glm::vec3 &    getCenter() const { return center; }
	void                 setCenter(const glm::vec3 & c) { center = c; }

	const RotateAxis & getAxis() const { return axis; }
	bool               getHasCenter() const { return hasCenter; }
	void               setHasCenter(bool c) { hasCenter = c; }

	float getMinAngle() const { return minAngle; }
	float getMaxAngle() const { return maxAngle; }
	bool  getNormalize() const { return normalize; }
	void  setNormalize(bool inNormalize) { normalize = inNormalize; }

	const string & getCat() const { return cat; }
	void           setCat(string inCat) { cat = inCat; }

	void setLimb(bool limb) { mbLimb = limb; }
	bool getLimb() const { return mbLimb; }
};

} // namespace Animorph
