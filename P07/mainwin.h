#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <climits>
#include <gtkmm.h>
#include "student.h"
#include "parent.h"

const std::string TITLE = "SMART"; 
const std::string VERSION = "0.3.0";
const std::string COMM_VERSION = "V0_1";
const std::string FILE_VERSION = "0.1";   // So we can adapt to file format changes later
const std::string COPYRIGHT = "2021";
const std::string EXTENSION = "smart";
const std::string FILE_PATTERN = "*." + EXTENSION;
const std::string DEFAULT_FILENAME = "untitled." + EXTENSION;
const std::string COOKIE = "«SmAr✞»";     // Weird string unlikely to be in a non-SMART file

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_school_click();      // Create a new school
        void on_save_click();            // Save the game to the current file
        void on_save_as_click();         // Save the game to a specified file
        void on_open_click();            // Load the game from a specified file
        void on_new_student_click();     // Create a new student
        void on_new_parent_click();      // Create a new parent
        void on_student_parent_click();  // Relate student and parent
        void on_about_click();           // Display About dialog
        void on_quit_click();            // Exit the game
        void on_easter_egg();            // Load test data
    private:
        void show_data();                // Display students and parents
        int select_student();
        int select_parent();
        int select(std::string prompt, int max = INT_MAX, int min = 0);
        void error(std::string msg, std::exception& e);
        
        std::vector<Student*> students;
        std::vector<Parent*> parents;
        std::string _filename;           // Current filename of school

        Gtk::Label *display;             // Display of data
        Gtk::Label *msg;                 // Status message display
};
#endif 

