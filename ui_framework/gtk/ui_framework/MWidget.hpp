#ifndef __MWidget_hpp__
#define __MWidget_hpp__
#include <gtk/gtk.h>

class MWidget
{
public:
    virtual void AddChild(MWidget & child);
    void Close();
    int GetLeft() { return x; }
    int GetTop() { return y; }
    int GetWidth() { return w; }
    int GetHeight() { return h; }
    void SetDimensions(int w, int h)
    {
        this->w = w;
        this->h = h;
    }
    void SetPosition(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    GtkWidget *gtkwidget;
protected:
    int x = 0,
        y = 0,
        w = 100,
        h = 100;
};

#endif