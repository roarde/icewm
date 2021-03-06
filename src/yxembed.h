#ifndef __YXEMBED_H
#define __YXEMBED_H

#include "ywindow.h"
#include "yarray.h"

class YXEmbedClient;

class YXEmbed: public YWindow {
public:
    YXEmbed(YWindow *aParent = 0);
    virtual ~YXEmbed();

//    YObjectArray<YWindow> fClients;

//    YXEmbedClient *manage(YXEmbed *embedder, Window win);
    virtual bool destroyedClient(Window /*win*/) = 0;
    virtual void handleClientUnmap(Window win) = 0;
};

class YXEmbedClient: public YWindow {
public:
    YXEmbedClient(YXEmbed *embedder, YWindow *aParent = 0, Window win = 0);
    virtual ~YXEmbedClient();

    void handleDestroyWindow(const XDestroyWindowEvent &destroyWindow);
    void handleUnmap(const XUnmapEvent &unmap);

private:
    YXEmbed *fEmbedder;
};

#endif

// vim: set sw=4 ts=4 et:
