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
 * File:    mrmimeparser.h
 * Authors: Björn Petersen
 * Purpose: Parse MIME body; this is the text part of an IMF handled by
 *          MrImfParser
 *
 ******************************************************************************/


#ifndef __MRMIMEPARSER_H__
#define __MRMIMEPARSER_H__


#include "mrmsg.h"


class MrMimePart
{
public:
						MrMimePart();
	                    ~MrMimePart();
	MrMsgType           m_type;
	char*               m_msg;
	char*               m_msg_raw;
};


class MrMimeParser
{
public:
	                    MrMimeParser         ();
	                    ~MrMimeParser        ();
	void                Empty                ();

	// The data returned from Parse() must not be freed (it is free()'d when the MrMimeParser object gets destructed)
	// Unless memory-allocation-errors occur, Parse() returns at least one empty part.
	// (this is because we want to add even these message to our database to avoid reading them several times.
	// of course, these empty messages are not added to any chat)
	void                Parse                (const char* body_not_terminated, size_t body_bytes);

	// data, read-only, must not be free()'d (it is free()'d when the MrMimeParser object gets destructed)
	carray*             m_parts;
	mailmime*           m_mimeroot;
	mailimf_fields*     m_header;
	char*               m_subjectEncoded;

	// find out the mimetype - one of the MR_MIMETYPE_* constants
	#define             MR_MIMETYPE_MP             0x100 // eg. mixed
	#define             MR_MIMETYPE_MP_ALTERNATIVE (MR_MIMETYPE_MP+1)
	#define             MR_MIMETYPE_MP_RELATED     (MR_MIMETYPE_MP+2)
	#define             MR_MIMETYPE_TEXT           0x200 // eg. plain
	#define             MR_MIMETYPE_TEXT_PLAIN     (MR_MIMETYPE_TEXT+1)
	#define             MR_MIMETYPE_TEXT_HTML      (MR_MIMETYPE_TEXT+2)
	#define             MR_MIMETYPE_IMAGE          0x300
	#define             MR_MIMETYPE_AUDIO          0x400
	#define             MR_MIMETYPE_VIDEO          0x500
	#define             MR_MIMETYPE_FILE           0x600
	static int          GetMimeType          (struct mailmime_content*);

private:
	bool                ParseMimeRecursive   (mailmime*);
	bool                AddSinglePartIfKnown (mailmime*);
};


#endif // __MRMIMEPARSER_H__
