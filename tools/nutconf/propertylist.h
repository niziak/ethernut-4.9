#ifndef PROPERTYLIST_H_
#define PROPERTYLIST_H_

/* ----------------------------------------------------------------------------
 * Copyright (C) 2004 by egnite Software GmbH
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
 * Parts are
 *
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
 *
 * ----------------------------------------------------------------------------
 */

/*
 * $Log$
 * Revision 1.4  2006/10/05 17:04:46  haraldkipp
 * Heavily revised and updated version 1.3
 *
 * Revision 1.3  2004/08/18 13:34:20  haraldkipp
 * Now working on Linux
 *
 * Revision 1.2  2004/08/03 15:03:25  haraldkipp
 * Another change of everything
 *
 * Revision 1.1  2004/06/07 16:11:22  haraldkipp
 * Complete redesign based on eCos' configtool
 *
 */

#include <wx/wx.h>
#include <wx/listctrl.h>

#include "configitem.h"

class CPropertyList:public wxListCtrl {
  public:
    enum nutPropertyType {
        nutEnabled,
        nutActive,
        nutRequires,
        nutProvides,
        nutExclusivity,
        nutType,
        nutFile,
        nutMacro,
        nutValue,
        nutMAXFIELDTYPE
    };

     CPropertyList(wxWindow * parent, wxWindowID id, const wxPoint & pos, const wxSize & size, long style);

    void OnRightClick(wxMouseEvent & event);
    void OnDoubleClick(wxMouseEvent & event);

    int SetItem(nutPropertyType type, const wxString & value);

    void RefreshValue();
    void Fill(CConfigItem * pti);
    void AddColumns();

  private:
     DECLARE_EVENT_TABLE()
     DECLARE_CLASS(CPropertyList)

    CConfigItem *m_pti;

    static const wxChar *m_propertyName[nutMAXFIELDTYPE];
};


#endif
