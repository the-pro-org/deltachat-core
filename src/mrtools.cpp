/*******************************************************************************
 *
 *                             Messenger Backend
 *     Copyright (C) 2016 Björn Petersen Software Design and Development
 *                   Contact: r10s@b44t.com, http://b44t.com
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see http://www.gnu.org/licenses/ .
 *
 *******************************************************************************
 *
 * File:    mrtools.cpp
 * Authors: Björn Petersen
 * Purpose: Some tools, see header for details.
 *
 ******************************************************************************/


#include <stdlib.h>
#include <libetpan.h>


int carray_search(carray* haystack, void* needle, unsigned int* indx)
{
	void** data = carray_data(haystack);
	unsigned int  cnt = carray_count(haystack);
	for( unsigned int i=0; i<cnt; i++ )
	{
		if( data[i] == needle ) {
			if( indx ) {
				*indx = i;
			}
			return true;
		}
	}

	return false;
}