#ifndef _NUTDISC_H_
#define _NUTDISC_H_

/* ----------------------------------------------------------------------------
 * Copyright (C) 2009 by egnite GmbH
 * Copyright (C) 2005-2006 by egnite Software GmbH
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * ----------------------------------------------------------------------------
 */

/*
 * $Id: nutdisc.h 2839 2009-12-17 11:57:55Z haraldkipp $
 */

class CApp : public wxApp
{
public:
    virtual bool OnInit();
    virtual int OnExit();
    wxFrame *m_frame;
};


#endif