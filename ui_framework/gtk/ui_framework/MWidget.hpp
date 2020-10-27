#ifndef __MWidget_hpp__
#define __MWidget_hpp__
#include <gtk/gtk.h>
#include <functional>

typedef std::function<void(int, int)> ResizeHandler;
class MWidget
{
public:
    virtual void AddChild(MWidget & child);
    void Close();
    void SetGtkWidget(GtkWidget*);
    GtkWidget *GetGtkWidget() {return gtkwidget;}
    int GetLeft() { return x; }
    int GetTop() { return y; }
    int GetWidth() { return w; }
    int GetHeight() { return h; }
    virtual void GetClientRect(int &w, int &h);
    void OnResize(ResizeHandler f);
    GtkContainer *GetParentContainer() { return gtkcontainer;}
    void SetParentContainer(GtkContainer *container)
    {
        gtkcontainer = container;
    }
    void SetDimensions(int w, int h)
    {
        if (gtkwidget)
            gtk_widget_set_size_request (GetGtkWidget(), w, h);
    }
    void SetPosition(int x, int y)
    {
        if(this->x != x && this->y != y)
        {
            if (gtkwidget)
                gtk_layout_move(GTK_LAYOUT(gtkcontainer), gtkwidget, x, y);
        }
    }

    ResizeHandler HandleResize = [](int w, int h){};
    int x = 0,
        y = 0,
        w = 100,
        h = 100;
private:
    GtkWidget *gtkwidget;
    GtkContainer *gtkcontainer;
};

#endif