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
 *******************************************************************************
 *
 * File:    mrkeyring.h
 * Purpose: Handle keys
 *
 ******************************************************************************/


#ifndef __MRKEYRING_H__
#define __MRKEYRING_H__
#ifdef __cplusplus
extern "C" {
#endif


/*** library-private **********************************************************/

typedef struct mrkey_t mrkey_t;

typedef struct mrkeyring_t
{
	mrkey_t** m_keys; /* only pointers to keys, the caller is responsible for freeing them and should make sure, the pointers are valid as long as the keyring is valid */
	int       m_count;
	int       m_allocated;
} mrkeyring_t;

void  mrkeyring_init  (mrkeyring_t*);
void  mrkeyring_empty (mrkeyring_t*); /* this does not free any key! */
void  mrkeyring_add   (mrkeyring_t*, const mrkey_t*); /* only copies the pointer! */

#ifdef __cplusplus
} /* /extern "C" */
#endif
#endif /* __MRKEYRING_H__ */

