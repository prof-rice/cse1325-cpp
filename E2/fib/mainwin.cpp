#include "mainwin.h"
#include <iostream> // for std::cerr logging
#include <fstream>
#include <sstream>

Mainwin::Mainwin() : fib{Fib{}} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(640, 160);
    set_title("Fibonacci Generator");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         S A V E   S E R I E S
    // Append Save to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     V I E W
    // Create a View menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    //         N E W   S E R I E S
    // Append Series to the Insert menu
    Gtk::MenuItem *menuitem_new_series = Gtk::manage(new Gtk::MenuItem("_Series", true));
    menuitem_new_series->signal_activate().connect([this] {this->on_new_series_click();});
    viewmenu->append(*menuitem_new_series);

    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*toolbar);

    //    S A V E
    // Add the stock Save icon
    Gtk::ToolButton *new_save_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
    new_save_button->set_tooltip_markup("Save Fibonacci series");
    new_save_button->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*new_save_button);

    //    N E W   S E R I E S
    // Add a custom New Series icon
    Gtk::Image* series_image = Gtk::manage(new Gtk::Image{"fib.png"});
    Gtk::ToolButton *series_button = Gtk::manage(new Gtk::ToolButton(*series_image));
    series_button->set_tooltip_markup("Select a Fibonacci series range");
    series_button->signal_clicked().connect([this] {this->on_new_series_click();});
    toolbar->append(*series_button);

    // /////////////////////////// ////////////////////////////////////////////
    // D I S P L A Y
    // Provide a text entry box to show the data
    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);
    
    // Make the box and everything in it visible
    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_new_series_click() {
    try {
      Gtk::Dialog dialog{"Select Fibonacci Range", *this};
      auto vbox = dialog.get_content_area();
  
      Gtk::Label start{"First Fibonacci index"};
      Gtk::Entry start_index;
      start_index.set_text("0");
      vbox->pack_start(start);
      vbox->pack_start(start_index);
       
      dialog.add_button("Cancel", 0);
      dialog.add_button("View 5", 5);
      dialog.add_button("View 15", 15);
      dialog.add_button("View 25", 25);
    
      dialog.show_all();
      int result = dialog.run();
      if(!result) return;
    
      begin_fib = std::stoi(start_index.get_text());
      end_fib = begin_fib + result;
    
      show_data();
    } catch(std::exception& e) {
      Gtk::MessageDialog{*this, std::string{"Invalid entry\n"} + e.what()}.run();
    }
}

//
// Save a subset of the Fibanocci series to the filesystem
//
void Mainwin::on_save_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_fib = Gtk::FileFilter::create();
    filter_fib->set_name("FIB files");
    filter_fib->add_pattern("*.fib");
    dialog.add_filter(filter_fib);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.fib");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Save", Gtk::RESPONSE_OK);

    int result = dialog.run();
    if(result != Gtk::RESPONSE_OK) return;

    try {
        std::ofstream ofs{dialog.get_filename()};
        for(int i=begin_fib; i<end_fib; ++i) ofs << fib[i] << ' ';     
        if(!ofs) throw std::runtime_error{"Error writing file"};
    } catch(std::exception& e) {
        Gtk::MessageDialog(*this, std::string{"Unable to save series"} + e.what());
    }
}

//
// Close the application
//
void Mainwin::on_quit_click() {
    close();
}

//
// Update the main window display
//
void Mainwin::show_data() {
    std::ostringstream oss;
    oss << "<big>";
    for(int i=begin_fib; i<end_fib; ++i) oss << fib[i] << ' ';
    oss << "</big>";
    display->set_markup(oss.str()); 
}

