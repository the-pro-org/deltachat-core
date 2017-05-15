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
 * File:    mre2ee.h
 * Purpose: Handle End-To-End-Encryption
 *
 ******************************************************************************/


#ifndef __MRE2EE_H__
#define __MRE2EE_H__
#ifdef __cplusplus
extern "C" {
#endif


/*** library-private **********************************************************/

#define MR_E2EE_DEFAULT_ENABLED 1

void mre2ee_init    (mrmailbox_t*);
void mre2ee_exit    (mrmailbox_t*);
void mre2ee_encrypt (mrmailbox_t*, const clist* recipients_addr, struct mailmime** in_out_message);
void mre2ee_decrypt (mrmailbox_t*, struct mailmime** in_out_message);


#ifdef __cplusplus
} /* /extern "C" */
#endif
#endif /* __MRE2EE_H__ */

