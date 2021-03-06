/*******************************************************************************
 *
 *                              Delta Chat Core
 *                      Copyright (C) 2017 Björn Petersen
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
 ******************************************************************************/


#ifndef __MROSNATIVE_H__
#define __MROSNATIVE_H__
#ifdef __cplusplus
extern "C" {
#endif


/*** library-private **********************************************************/


typedef struct _mrmailbox mrmailbox_t;

int  mrosnative_setup_thread   (mrmailbox_t*); /*returns true/false*/
void mrosnative_unsetup_thread (mrmailbox_t*);


#ifdef __cplusplus
} /* /extern "C" */
#endif
#endif /* __MROSNATIVE_H__ */
