#include "canvas.h"
#include <iostream>
#include <vector>

// Draw the lines any time gtkmm needs to refresh the widget
bool Canvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {

    // Draw the letter M
    cr->set_line_width(7.0);
    std::vector<double> dash_m = {9.0, 3.0};
    cr->set_dash(dash_m, 0.0);
    cr->set_source_rgb(0.2, 0.2, 1.0); // Set lines to blue
    
    cr->move_to(10, 390);
    cr->line_to(10, 10);
    cr->line_to(300, 390);
    cr->line_to(590, 10);
    cr->line_to(590, 390);
    cr->stroke();

    // Draw the letter X
    cr->set_line_width(5.0);
    std::vector<double> dash_x = {10.0, 4.0};
    cr->set_dash(dash_x, 0.0);
    cr->set_source_rgb(0.0, 0.8, 0.0); // Set lines to green
    
    cr->move_to(10, 10);
    cr->line_to(590, 390);
    cr->move_to(10, 390);
    cr->line_to(590, 10);
    cr->stroke();
  
    // Draw the letter Z
    cr->set_line_width(3.0);
    std::vector<double> dash_z = {7.0, 6.0};
    cr->set_dash(dash_z, 0.0);
    cr->set_source_rgb(0.8, 0.0, 0.0); // Set lines to red

    cr->move_to(10, 10);
    cr->line_to(590, 10);
    cr->line_to(10, 390);
    cr->line_to(590, 390);
    cr->stroke();

    // Drawing was successful
    return true;
}


