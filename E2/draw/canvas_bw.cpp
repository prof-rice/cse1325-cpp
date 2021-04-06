#include "canvas.h"
#include <iostream>
#include <vector>

// Draw the lines any time gtkmm needs to refresh the widget
bool Canvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {

    cr->set_line_width(5.0);
    std::vector<double> dash_m = {9.0, 5.0};
    cr->set_dash(dash_m, 0.0);
    cr->set_source_rgb(0, 0, 0); // Set lines to black

    // Draw the letter M
    cr->move_to(10, 390);
    cr->line_to(10, 10);
    cr->line_to(300, 390);
    cr->line_to(590, 10);
    cr->line_to(590, 390);
    cr->stroke();
/*
    // Draw the letter X
    cr->move_to(10, 10);
    cr->line_to(590, 390);
    cr->move_to(10, 390);
    cr->line_to(590, 10);
    cr->stroke();

    // Draw the letter Z
    cr->move_to(10, 10);
    cr->line_to(590, 10);
    cr->line_to(10, 390);
    cr->line_to(590, 390);
    cr->stroke();
*/
    // Drawing was successful
    return true;
}


