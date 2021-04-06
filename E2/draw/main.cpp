#include "canvas.h"

int main (int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.e2.draw");
    Gtk::Window win;
    win.set_title("M, X, or Z");
    win.set_default_size(600,400);  // Window is 600 x 400 pixels
    win.set_resizable(false);       // Window cannot be resized!
    
    Canvas canvas;
    win.add(canvas);
    canvas.show();
    
    return app->run(win);
}

