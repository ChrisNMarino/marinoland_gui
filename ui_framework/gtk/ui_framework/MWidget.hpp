#ifndef __MWidget_hpp__
#define __MWidget_hpp__
#include <gtk/gtk.h>

class MWidget
{
public:
    void AddChild(MWidget & child);
    void Close();
protected:
    GtkWidget *gtkwidget;
};

#endif