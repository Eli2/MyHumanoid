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
 *  File   : BottomPanel.h
 *  Project: MakeHuman <info@makehuman.org>, http://www.makehuman.org/
 *  App    : makehuman
 *
 *  For individual developers look into the AUTHORS file.
 *
 */

#ifndef BOTTOMPANEL_H
#define BOTTOMPANEL_H 1

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "util.h"
#include <gui/Image.h>
#include <gui/Panel.h>
#include <iostream>

using namespace mhgui;

class BottomPanel : public Panel
{
public:
	BottomPanel();
	virtual ~BottomPanel();

	void createWidgets();

private: // intentionally not implemented
	BottomPanel(const BottomPanel &);
	BottomPanel &operator=(const BottomPanel &);

	Image *frame1;
	Image *frame2;
	Image *frame3;
};

#endif // BOTTOMPANEL_H
