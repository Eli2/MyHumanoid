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
 *  File   : BsPanelSelectionListener.cpp
 *  Project: MakeHuman <info@makehuman.org>, http://www.makehuman.org/
 *  App    : makehuman
 *
 *  For individual developers look into the AUTHORS file.
 *
 */

#include <animorph/Mesh.h>

#include <gui/CGUtilities.h>
#include <gui/Component.h>
#include <gui/GLUTWrapper.h>
#include <gui/Window.h>

#include <assert.h>
#include <stdio.h>

#include "BsCategoryPanel.h"
#include "BsPanel.h"
#include "BsPanelSelectionListener.h"
#include "ComponentID.h"
#include "Global.h"
#include "ImageButton.h"

using namespace Animorph;
using namespace std;

BsPanelSelectionListener::BsPanelSelectionListener()
    : AbstractListener()
{
}

BsPanelSelectionListener::~BsPanelSelectionListener() {}

bool BsPanelSelectionListener::mouseOver(const Point &inMousePos,
                                         Component *source)
{
	ImageButton *imgSource = dynamic_cast<ImageButton *>(source); // req. RTTI!
	assert(imgSource); // Check if this is really an Image object?

	imgSource->setOverlayRectangle(Color(1, 0, 0, 0.5));

	return false;
}

bool BsPanelSelectionListener::mouseOut(const Point &inMousePos,
                                        Component *source)
{
	ImageButton *imgSource = dynamic_cast<ImageButton *>(source); // req. RTTI!
	assert(imgSource); // Check if this is really an Image object?

	imgSource->setOverlayRectangle(false);

	return false;
}

bool BsPanelSelectionListener::mouseDragged(const Point &inMousePos,
                                            Component *source)
{
	return true;
}

bool BsPanelSelectionListener::mouseWheel(const Point &inMousePos, int inButton,
                                          Component *source)
{
	return false;
}

bool BsPanelSelectionListener::mousePressed(const Point &inMousePos, int button,
                                            Component *source)
{
	if (button == GLUT_LEFT_BUTTON) {
		ImageButton *imgSource = dynamic_cast<ImageButton *>(source); // req. RTTI!
		assert(imgSource); // Check if this is really an Image object?
		imgSource->setOverlayRectangle(Color(1, 1, 1, 0.5));

		return true;
	}
	return false;
}

bool BsPanelSelectionListener::mouseReleased(const Point &inMousePos,
                                             int button, Component *source)
{
	std::ostringstream out_stream;
	if (button == GLUT_LEFT_BUTTON) {
		ImageButton *imgSource = dynamic_cast<ImageButton *>(source); // req. RTTI!
		assert(imgSource); // Check if this is really an Image object?

		imgSource->setOverlayRectangle(false);

		if (!imgSource->getAbsoluteRect().isHitBy(inMousePos))
			return false;

		Mesh *mesh = g_global.getMesh();

		CharactersMap &charactersmap = mesh->getCharactersMapRef();
		mesh->doMorph(charactersmap[imgSource->infoCommand], 1.0, true);
		mesh->calcNormals();

		loadSelectorsPositions(
		    charactersmap[imgSource->infoCommand].cursorPositions);
	}

	return false;
}

bool BsPanelSelectionListener::keyType(unsigned char key, Component *source)
{
	return false;
}
