#include "ui_framework/MTextBox.hpp"
#include <iostream>

MTextBox::MTextBox(MWidget & parent)
{
    int w = GetWidth();
    int h = GetHeight();
    int x = GetLeft();
    int y = GetHeight();
    SetGtkWidget(gtk_text_view_new ());
    parent.AddChild(*this);
    SetPosition(x, y);
    SetDimensions(w, h);
}

void MTextBox::SetText(const char *str)
{
    GtkTextBuffer *buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (GetGtkWidget()));
    gtk_text_buffer_set_text (buffer, str, -1);
}

std::string MTextBox::GetText()
{
    GtkTextBuffer *buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (GetGtkWidget()));
    GtkTextIter start, end;
    gtk_text_buffer_get_start_iter (buffer, &start);
    gtk_text_buffer_get_end_iter (buffer, &end);
    std::string ret = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    return ret;
}