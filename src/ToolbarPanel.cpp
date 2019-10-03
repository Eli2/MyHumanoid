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
 *  File   : ToolbarPanel.cpp
 *  Project: MakeHuman <info@makehuman.org>, http://www.makehuman.org/
 *  App    : makehuman
 *
 *  For individual developers look into the AUTHORS file.
 *
 */

#include "ToolbarPanel.h"
#include "ComponentID.h"
#include "ImageListener.h"

#include <algorithm>

#include <gui/Rect.h>
#include <gui/Tooltip.h>
#include <gui/Window.h>

using namespace std;
using namespace Animorph;

ToolbarPanel::ToolbarPanel()
        : Panel(kComponentID_ToolbarPanel, Rect(192, 16, 1248, 32))
{
}

ToolbarPanel::~ToolbarPanel()
{
	for_each(imageVector.begin(), imageVector.end(), deleteFunctor<Image *>());
}

void ToolbarPanel::createWidgets()
{
	Window & mainWindow   = *g_mainWindow;
	Panel *  tooltipPanel = mainWindow.getPanel(kComponentID_TooltipPanel);
	assert(tooltipPanel);

	const Color color_red(1.0, 0.0, 0.0);
	const float alpha = 1.0;
	const Point kTooltipPos(70, 12);

	Image * image;

	// -------------------------------------------------------------------------
	// -------------------------------------------------------------------------
	// -------------------------------------------------------------------------
	// -------------------------------------------------------------------------
	// -------------------------------------------------------------------------
	image = new Image(kComponentID_ImageToolbarPanel_CharacterSettings,
	                  searchPixmapFile("ui/toolbar_charac_sett.png"), Rect(0, 0, 32, 32));
	image->setListener(&imgListener1);
	image->setTooltip(Tooltip("Character setting (somatotypes, shapes, age, etc...)",
	                          kTooltipPos, color_red, tooltipPanel));
	image->setAlpha(alpha);
	imageVector.push_back(image);
	addWidget(image);

	// -------------------------------------------------------------------------
	image = new Image(kComponentID_ImageToolbarPanel_BodyDetailsRealistic,
	                  searchPixmapFile("ui/toolbar_body_det_real.png"), Rect(0, 0, 32, 32));
	image->setListener(&imgListener1);
	image->setTooltip(Tooltip("Body details (realistic morphings)", kTooltipPos, color_red,
	                          tooltipPanel));
	image->setAlpha(alpha);
	imageVector.push_back(image);
	addWidget(image);
	// -------------------------------------------------------------------------
	// -------------------------------------------------------------------------
	// -------------------------------------------------------------------------
	// -------------------------------------------------------------------------
	image = new Image(kComponentID_ImageToolbarPanel_MorphingList,
	                  searchPixmapFile("ui/toolbar_morph_list.png"), Rect(0, 0, 32, 32));
	image->setListener(&imgListener1);
	image->setTooltip(Tooltip("Used morphing list", kTooltipPos, color_red, tooltipPanel));
	image->setAlpha(alpha);
	imageVector.push_back(image);
	addWidget(image);


	image->setAlpha(alpha);
	imageVector.push_back(image);
	addWidget(image);
}