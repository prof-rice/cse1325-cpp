#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <climits>
#include <gtkmm.h>
#include "student.h"
#include "parent.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_school_click();      // Create a new school
        void on_new_student_click();     // Create a new student
        void on_new_parent_click();      // Create a new parent
        void on_easter_egg();            // Load test data
        void on_student_parent_click();  // Relate student and parent
        void on_quit_click();            // Exit the game
    private:
        void show_data();                // Display students and parents
        int select_student();
        int select_parent();
        int select(std::string prompt, int max = INT_MAX, int min = 0);
        
        std::vector<Student> students;
        std::vector<Parent> parents;

        Gtk::Label *display;             // Display of data
        Gtk::Label *msg;                 // Status message display
};
#endif 

