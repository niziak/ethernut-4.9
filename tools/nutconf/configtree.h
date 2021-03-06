#ifndef CONFIGTREE_H_
#define CONFIGTREE_H_

/* ----------------------------------------------------------------------------
 * Copyright (C) 2004-2007 by egnite Software GmbH
 * Copyright (C) 1998, 1999, 2000 Red Hat, Inc.
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
 * ----------------------------------------------------------------------------
 */

/*
 * $Log$
 * Revision 1.4  2008/03/17 10:17:19  haraldkipp
 * Removed dispensable scroll handlers.
 *
 * Revision 1.3  2006/10/05 17:04:46  haraldkipp
 * Heavily revised and updated version 1.3
 *
 * Revision 1.2  2004/08/18 13:34:20  haraldkipp
 * Now working on Linux
 *
 * Revision 1.1  2004/06/07 16:13:15  haraldkipp
 * Complete redesign based on eCos' configtool
 *
 */

#include <wx/wx.h>

#include "iconlist.h"
#include "scrolledtree.h"

/*!
 * \brief Configuration tree.
 */
class CConfigTree:public CScrolledTreeCtrl {
    DECLARE_CLASS(CConfigTree);

  public:
    CConfigTree(wxWindow * parent, wxWindowID id = -1, const wxPoint & pt = wxDefaultPosition,
                const wxSize & sz = wxDefaultSize, long style = wxTR_HAS_BUTTONS);

    void OnMouseEvent(wxMouseEvent & event);
    void OnSelChanged(wxTreeEvent & event);
    wxTreeItemId FindNextItemId(wxTreeItemId treeItemId, const wxString& text,
                                bool checkFirst, bool matchCase, bool matchWord);

    CIconList & GetIconDB();

  protected:
    wxImageList * m_imageList;
    CIconList m_iconDB;
    /*! \brief Context menu.
     *
     * \todo Unused.
     */
    wxMenu *m_propertiesMenu;

    DECLARE_EVENT_TABLE();
};


#endif
