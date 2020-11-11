#include <ui_framework/MGuiFactory.hpp>


void msgBox(GtkWindow *parent, const char *title, const char *msg)
{
    GtkWidget *dialog = gtk_message_dialog_new (
            parent,
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_OTHER,
            GTK_BUTTONS_OK,
            "%s",
            msg);
    gtk_window_set_title((GtkWindow*)dialog, title);
    gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);
}

void MGuiFactory::messageBox(MWindow &parent, const char *title, const char *msg)
{
    msgBox((GtkWindow*)parent.GetGtkWidget(), title, msg);
}

void MGuiFactory::messageBox(const char *title, const char *msg)
{
    msgBox(NULL, title, msg);
}