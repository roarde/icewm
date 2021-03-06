#ifndef __OBJ_H
#define __OBJ_H

#include "ypaint.h"

class IApp;

class DObject {
public:
    DObject(IApp *app, const ustring &name, ref<YIcon> icon);
    virtual ~DObject();

    ustring getName() { return fName; }
    ref<YIcon> getIcon() { return fIcon; }

    virtual void open();

private:
    ustring fName;
    ref<YIcon> fIcon;
protected:
    IApp *app;
};

class ObjectContainer {
public:
    virtual void addObject(DObject *object) = 0;
    virtual void addSeparator() = 0;
    virtual void addContainer(const ustring &name, ref<YIcon> icon, ObjectContainer *container) = 0;
protected:
    virtual ~ObjectContainer() {};
};


#endif

// vim: set sw=4 ts=4 et:
