#ifndef __THEMES_H
#define __THEMES_H

#ifndef NO_CONFIGURE_MENUS

#include "objmenu.h"
#include "obj.h"

class YMenu;
class YSMListener;
class YActionListener;

class DTheme: public DObject {
public:
    DTheme(IApp *app, YSMListener *smActionListener, const ustring &label, const ustring &theme);
    virtual ~DTheme();

    virtual void open();
private:
    YSMListener *smActionListener;
    ustring fTheme;
    IApp *app;
};

class ThemesMenu: public ObjectMenu {
public:
    ThemesMenu(IApp *app, YSMListener *smActionListener, YActionListener *wmActionListener, YWindow *parent = 0);
    virtual ~ThemesMenu();

    void updatePopup();
    void refresh();

private:
    void findThemes(const upath& path, YMenu *container);

    static YMenuItem *newThemeItem(
        IApp *app,
        YSMListener *smActionListener,
        const ustring& label,
        const ustring& relThemeName);
    
    static void findThemeAlternatives(
        IApp *app,
        YSMListener *smActionListener,
        const upath& path,
        const ustring& relName,
        YMenuItem *item);
        
    // this solution isn't nice. Saving it globaly somewhere would be
    // much better, we would have a themeCound from the last refresh
    // cycle and update it after menu construction, counting themes that
    // are actually added to menues
    int countThemes(const upath& path);
    int themeCount;
    
    YSMListener *smActionListener;
    YActionListener *wmActionListener;
    IApp *app;
};

#endif

#endif
