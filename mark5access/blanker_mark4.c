/***************************************************************************
 *   Copyright (C) 2007 by Walter Brisken                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "mark5access/mark5_stream.h"

/* Same as generic mark5 blanker, but also make sure start and end of each 
 * frame is blanked.
 */
int blanker_mark4(struct mark5_stream *ms)
{
	int r, s, delta, n;

	r = blanker_mark5(ms);

	n = ms->framebytes/20000;

	s = 160*n;

	delta = s - ms->blankzonestartvalid[0];
	if(delta > 0)
	{
		ms->blankzonestartvalid[0] = s;
		r += delta;
	}

	return r;
}
