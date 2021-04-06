#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "fib.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_series_click();      // Display series
        void on_save_click();            // Save series to a specified file
        void on_quit_click();            // Exit the game
    private:
        int begin_fib;                   // First Fibonacci to show (e.g., fib[begin_fib]         
        int end_fib;                    // Last Fibonacci to show  (e.g., fib[end_fib]         
        void show_data();                // Display fib in main window, begin_fib to end_fib
        
        Fib fib;                        // The data generator
        Gtk::Label *display;             // Display of data
        
};
#endif 

