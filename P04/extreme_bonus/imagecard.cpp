#include "imagecard.h"
#include <cstdlib>

#ifdef EOG
// For use with Eye of Gnome, the Ubuntu / Gnome standard viewer
const std::string image_command = "eog ";

#elif FEH
// For use with feh, a lightweight borderless image viewer
const std::string image_command = "feh -x -g +0+0 ";

#elif ET
// For use with Enlightenment Terminology with embedded images
const std::string image_command = "tycat ";

#else
// For use in Xubuntu (the CSE-VM)
const std::string image_command = "ristretto ";
#endif

Imagecard::Imagecard(std::string question, std::string answer, std::string imagefile) 
      : Card(question, answer), _imagefile{imagefile} { }

void Imagecard::extended_question() const {
    std::string cmd = image_command + _imagefile;
    int result = system(cmd.c_str());
}
