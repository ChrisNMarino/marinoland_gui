#ifndef __MApplication_hpp__
#define __MApplication_hpp__

#include <string>
#include <iostream>
#include <functional>
#include "ui_framework/MGuiFactory.hpp"

class MApplication
{
public:
    MApplication(const char *appname);
    virtual void Ready(MGuiFactory *gui) = 0;
    std::string appname;
private:
};


#endif