#include "mainwin.h"

int main (int argc, char *argv[]) {
    srand (time(NULL));
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.smart." + COMM_VERSION);
    Mainwin win;
    return app->run(win);
}

