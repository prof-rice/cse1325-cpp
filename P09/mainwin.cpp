#include "mainwin.h"
#include "entrydialog.h"
#include "comboboxcontainer.h"
#include <iostream> // for std::cerr logging
#include <fstream>
#include <sstream>

Mainwin::Mainwin() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(800, 600);
    set_title("SMART");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*menubar);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         N E W   S C H O O L
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New School", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_school_click();});
    filemenu->append(*menuitem_new);

    //         S A V E   S C H O O L
    // Append Save to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

    //         S A V E   S C H O O L
    // Append Save As... to the File menu
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("Save _As", true));
    menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_save_as);

    //         O P E N   S C H O O L
    // Append Open... to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     I N S E R T
    // Create an Insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    //         N E W   S T U D E N T
    // Append New Student to the Insert menu
    Gtk::MenuItem *menuitem_new_student = Gtk::manage(new Gtk::MenuItem("New _Student", true));
    menuitem_new_student->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_new_student);

    //         N E W   P A R E N T
    // Append New Parent to the Insert menu
    Gtk::MenuItem *menuitem_new_parent = Gtk::manage(new Gtk::MenuItem("New _Parent", true));
    menuitem_new_parent->signal_activate().connect([this] {this->on_new_parent_click();});
    insertmenu->append(*menuitem_new_parent);

    //         N E W   T E A C H E R
    // Append New Teacher to the Insert menu
    Gtk::MenuItem *menuitem_new_teacher = Gtk::manage(new Gtk::MenuItem("New _Teacher", true));
    menuitem_new_teacher->signal_activate().connect([this] {this->on_new_teacher_click();});
    insertmenu->append(*menuitem_new_teacher);

    //         N E W   C O U R S E
    // Append New Course to the Insert menu
    Gtk::MenuItem *menuitem_new_course = Gtk::manage(new Gtk::MenuItem("New _Course", true));
    menuitem_new_course->signal_activate().connect([this] {this->on_new_course_click();});
    insertmenu->append(*menuitem_new_course);
    
    //         N E W   S E C T I O N
    // Append New Section to the Insert menu
    Gtk::MenuItem *menuitem_new_section = Gtk::manage(new Gtk::MenuItem("New _Section", true));
    menuitem_new_section->signal_activate().connect([this] {this->on_new_section_click();});
    insertmenu->append(*menuitem_new_section);

    //         N E W   T R A N S C R I P T
    // Append New Transcript to the Insert menu
    Gtk::MenuItem *menuitem_new_transcript = Gtk::manage(new Gtk::MenuItem("New _Transcript", true));
    menuitem_new_transcript->signal_activate().connect([this] {this->on_new_transcript_click();});
    insertmenu->append(*menuitem_new_transcript);

    //         T E S T   D A T A
    // Append Test Data to the Insert menu
    Gtk::MenuItem *menuitem_test_data = Gtk::manage(new Gtk::MenuItem("_Test Data", true));
    menuitem_test_data->signal_activate().connect([this] {this->on_easter_egg();});
    insertmenu->append(*menuitem_test_data);

    //     R E L A T E
    // Create a Relate menu and add to the menu bar
    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_relate);
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
    menuitem_relate->set_submenu(*relatemenu);

    //         S T U D E N T  T O  P A R E N T
    // Append Student to Parent to the Insert menu
    Gtk::MenuItem *menuitem_student_parent = Gtk::manage(new Gtk::MenuItem("_Student to Parent", true));
    menuitem_student_parent->signal_activate().connect([this] {this->on_student_parent_click();});
    relatemenu->append(*menuitem_student_parent);

    //     V I E W
    // Create a View menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);
    
    //         S T U D E N T S
    // Append Students to the View menu
    Gtk::MenuItem *menuitem_view_student = Gtk::manage(new Gtk::MenuItem("_Students", true));
    menuitem_view_student->signal_activate().connect([this] {this->show_data(View::STUDENTS);});
    viewmenu->append(*menuitem_view_student);

    //         P A R E N T S
    // Append Parents to the View menu
    Gtk::MenuItem *menuitem_view_parent = Gtk::manage(new Gtk::MenuItem("_Parents", true));
    menuitem_view_parent->signal_activate().connect([this] {this->show_data(View::PARENTS);});
    viewmenu->append(*menuitem_view_parent);
    
    //        T E A C H E R S
    // Append Teachers to the View menu
    Gtk::MenuItem *menuitem_view_teacher = Gtk::manage(new Gtk::MenuItem("_Teachers", true));
    menuitem_view_teacher->signal_activate().connect([this] {this->show_data(View::TEACHERS);});
    viewmenu->append(*menuitem_view_teacher);
    
    //         C O U R S E S
    // Append Coursess to Courses to the View menu
    Gtk::MenuItem *menuitem_view_courses = Gtk::manage(new Gtk::MenuItem("_Courses", true));
    menuitem_view_courses->signal_activate().connect([this] {this->show_data(View::COURSES);});
    viewmenu->append(*menuitem_view_courses);
    
    //         S E C T I O N S
    // Append Sections to the View menu
    Gtk::MenuItem *menuitem_view_sections = Gtk::manage(new Gtk::MenuItem("Se_ctions", true));
    menuitem_view_sections->signal_activate().connect([this] {this->show_data(View::SECTIONS);});
    viewmenu->append(*menuitem_view_sections);

    //        T R A N S C R I P T S
    // Append Transcripts to the View menu
    Gtk::MenuItem *menuitem_view_transcript = Gtk::manage(new Gtk::MenuItem("T_ranscripts", true));
    menuitem_view_transcript->signal_activate().connect([this] {this->show_data(View::TRANSCRIPTS);});
    viewmenu->append(*menuitem_view_transcript);
    
    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);

    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*toolbar);

    //     N E W   S C H O O L
    // Add a new school icon
    Gtk::Image* new_image = Gtk::manage(new Gtk::Image{"new.png"});
    Gtk::ToolButton *new_school_button = Gtk::manage(new Gtk::ToolButton(*new_image));//Gtk::Stock::NEW));
    new_school_button->set_tooltip_markup("Create a new school");
    new_school_button->signal_clicked().connect([this] {this->on_new_school_click();});
    toolbar->append(*new_school_button);
    
    //    O P E N
    // Add the stock Open icon
    Gtk::Image* open_image = Gtk::manage(new Gtk::Image{"open.png"});
    Gtk::ToolButton *new_open_button = Gtk::manage(new Gtk::ToolButton(*open_image));//Gtk::Stock::OPEN));
    new_open_button->set_tooltip_markup("Open a school from a file");
    new_open_button->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*new_open_button);

    //    S A V E
    // Add the stock Save icon
    Gtk::Image* save_image = Gtk::manage(new Gtk::Image{"save.png"});
    Gtk::ToolButton *new_save_button = Gtk::manage(new Gtk::ToolButton(*save_image));//Gtk::Stock::SAVE));
    new_save_button->set_tooltip_markup("Save school to this file");
    new_save_button->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*new_save_button);

    //    S A V E   A S
    // Add the stock Save As icon
    Gtk::Image* save_as_image = Gtk::manage(new Gtk::Image{"save_as.png"});
    Gtk::ToolButton *new_save_as_button = Gtk::manage(new Gtk::ToolButton(*save_as_image));//Gtk::Stock::SAVE_AS));
    new_save_as_button->set_tooltip_markup("Save school to a new file");
    new_save_as_button->signal_clicked().connect([this] {this->on_save_as_click();});
    toolbar->append(*new_save_as_button);

   // Add a little space 
    Gtk::SeparatorToolItem *sep1 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep1);
    
    //    N E W   S T U D E N T
    // Add a custom New Student icon
    Gtk::Image* student_image = Gtk::manage(new Gtk::Image{"student.png"});
    Gtk::ToolButton *student_button = Gtk::manage(new Gtk::ToolButton(*student_image));
    student_button->set_tooltip_markup("Create a new student");
    student_button->signal_clicked().connect([this] {this->on_new_student_click();});
    toolbar->append(*student_button);

    //    N E W   P A R E N T
    // Add a custom New Parent icon
    Gtk::Image* parent_image = Gtk::manage(new Gtk::Image{"parent.png"});
    Gtk::ToolButton *parent_button = Gtk::manage(new Gtk::ToolButton(*parent_image));
    parent_button->set_tooltip_markup("Create a new parent");
    parent_button->signal_clicked().connect([this] {this->on_new_parent_click();});
    toolbar->append(*parent_button);
    
    //    R E L A T E   P A R E N T
    // Add a custom Relate Student to Parent icon
    Gtk::Image* ps_relate_image = Gtk::manage(new Gtk::Image{"ps_relate.png"});
    Gtk::ToolButton *ps_relate_button = Gtk::manage(new Gtk::ToolButton(*ps_relate_image));
    ps_relate_button->set_tooltip_markup("Relate student to parent");
    ps_relate_button->signal_clicked().connect([this] {this->on_student_parent_click();});
    toolbar->append(*ps_relate_button);

    //    N E W   T E A C H E R
    // Add a custom New Teacher icon
    Gtk::Image* teacher_image = Gtk::manage(new Gtk::Image{"teacher.png"});
    Gtk::ToolButton *teacher_button = Gtk::manage(new Gtk::ToolButton(*teacher_image));
    teacher_button->set_tooltip_markup("Create a new teacher");
    teacher_button->signal_clicked().connect([this] {this->on_new_teacher_click();});
    toolbar->append(*teacher_button);
    
   // Add a little space 
    Gtk::SeparatorToolItem *sep2 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep2);
    
    //    N E W   C O U R S E
    // Add a custom New Course icon
    Gtk::Image* course_image = Gtk::manage(new Gtk::Image{"course.png"});
    Gtk::ToolButton *course_button = Gtk::manage(new Gtk::ToolButton(*course_image));
    course_button->set_tooltip_markup("Create a new course");
    course_button->signal_clicked().connect([this] {this->on_new_course_click();});
    toolbar->append(*course_button);

    //    N E W   S E C T I O N
    // Add a custom New Section icon
    Gtk::Image* section_image = Gtk::manage(new Gtk::Image{"section.png"});
    Gtk::ToolButton *section_button = Gtk::manage(new Gtk::ToolButton(*section_image));
    section_button->set_tooltip_markup("Create a new section");
    section_button->signal_clicked().connect([this] {this->on_new_section_click();});
    toolbar->append(*section_button);
    
    //    N E W   T R A N S C R I P T
    // Add a custom New transcript icon
    Gtk::Image* transcript_image = Gtk::manage(new Gtk::Image{"transcript.png"});
    Gtk::ToolButton *transcript_button = Gtk::manage(new Gtk::ToolButton(*transcript_image));
    transcript_button->set_tooltip_markup("Create a new transcript (assign child to section)");
    transcript_button->signal_clicked().connect([this] {this->on_new_transcript_click();});
    toolbar->append(*transcript_button);

    //    S E T   G R A D E
    // Add a custom Assign Grade icon
    Gtk::Image* grade_image = Gtk::manage(new Gtk::Image{"grade.png"});
    Gtk::ToolButton *grade_button = Gtk::manage(new Gtk::ToolButton(*grade_image));
    grade_button->set_tooltip_markup("Assign a grade");
    grade_button->signal_clicked().connect([this] {this->on_set_grade_click();});
    toolbar->append(*grade_button);
    
     // /////////////////////////// ////////////////////////////////////////////
    // D I S P L A Y
    // Provide a text entry box to show the data
    display = Gtk::manage(new Gtk::Label{"", Gtk::ALIGN_START, Gtk::ALIGN_START});
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);
    
    // S T A T U S   B A R   D I S P L A Y ////////////////////////////////////
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
    // vbox->add(*msg);

    // Make the box and everything in it visible
    vbox->show_all();

    // Start a new game
    on_new_school_click();
}

Mainwin::~Mainwin() { 
    for(Student* s : students) delete s;
    for(Parent* p : parents) delete p;
}

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_new_school_click() {
    for(Student* s : students) delete s;
    students.clear();

    for(Parent* p : parents) delete p;
    parents.clear();

    for(Teacher* t : teachers) delete t;
    teachers.clear();

    for(Course* c : courses) delete c;
    courses.clear();

    for(Section* s : sections) delete s;
    sections.clear();

    for(Transcript* t : transcripts) delete t;
    transcripts.clear();

    _filename = DEFAULT_FILENAME;
    show_data(View::STUDENTS);
}

//
// Save a school to the filesystem
//
void Mainwin::on_save_as_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("SMART files");
    filter_smart->add_pattern(FILE_PATTERN);
    dialog.add_filter(filter_smart);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(_filename);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Save", Gtk::RESPONSE_OK);

    int result = dialog.run();
    if(result == Gtk::RESPONSE_OK) {
        _filename = dialog.get_filename();
        on_save_click();
    }
}


//
// Save a school to the file specified in _filename
//
void Mainwin::on_save_click() {
    try {
        std::ofstream ofs{_filename};
        
        // Save "magic cookie" to identify file
        ofs << COOKIE << '\n';  
        ofs << FILE_VERSION << '\n';      // File format version number
        
        // Save composite data for students and parents
        ofs << students.size() << '\n';
        for(Student* student : students) student->save(ofs);
        ofs << parents.size() << '\n';
        for(Parent* parent : parents) parent->save(ofs);
  
        // Save aggregate data for students and parents
        for(Student* student : students) student->save_aggregates(ofs);
        for(Parent* parent : parents) parent->save_aggregates(ofs);

        // File version 0.2
        // Save composite data for courses and sections
        ofs << courses.size() << '\n';
        for(Course* course : courses) course->save(ofs);
        ofs << sections.size() << '\n';
        for(Section* section : sections) section->save(ofs);
        
        // File version 0.3
        // Save composite data for teachers and transcripts
        ofs << teachers.size() << '\n';
        for(Teacher* teacher : teachers) teacher->save(ofs);
        ofs << transcripts.size() << '\n';
        for(Transcript* transcript : transcripts) transcript->save(ofs);
       
        if(!ofs) throw std::runtime_error{"Error writing file"};
    } catch(std::exception& e) {
        error("Unable to save school", e);
    }
}
//
// Open a school from the filesystem
//
void Mainwin::on_open_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("smart files");
    filter_smart->add_pattern(FILE_PATTERN);
    dialog.add_filter(filter_smart);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(_filename);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    int result = dialog.run();

    if (result == Gtk::RESPONSE_OK) {
        try {
            // Try to open the selected file - if it fails, preserve current data
            std::ifstream ifs{dialog.get_filename()};
            
            // Success! Clear data and remember filename
            on_new_school_click();
            show_data();
            _filename = dialog.get_filename();
            
            // Check the magic cookie
            std::string cookie;
            std::getline(ifs, cookie);
            if(cookie != COOKIE) throw std::runtime_error{"Not a " + TITLE + " file"};
            std::string version;
            std::getline(ifs, version);
            if(version > FILE_VERSION) throw std::runtime_error{"Unsupported file version"};
            
            // Load the composite students
            int size;
            ifs >> size; ifs.ignore(32767, '\n');
            while(size--) students.push_back(new Student{ifs});
            
            // Load the composite parents
            ifs >> size; ifs.ignore(32767, '\n');
            while(size--) parents.push_back(new Parent{ifs});
            
            // Aggregate the student relationships
            std::ostringstream oss;
            std::map<std::string, Parent*> parent_aggregates;
            for(Parent* p : parents) {
                oss.str("");
                oss << *p;
                parent_aggregates[oss.str()] = p;
            }
            for(Student* s : students) s->load_aggregates(ifs, parent_aggregates);
            
            // Aggregate the parent relationships
            std::map<std::string, Student*> student_aggregates;
            for(Student* s : students) {
                oss.str("");
                oss << *s;
                student_aggregates[oss.str()] = s;
            }
            for(Parent* p : parents) p->load_aggregates(ifs, student_aggregates);
            
            // If file version 0.2 or greater, also load the courses and sections
            if(version >= "0.2") {
                ifs >> size; ifs.ignore(32767, '\n');
                while(size--) courses.push_back(new Course{ifs});

                ifs >> size; ifs.ignore(32767, '\n');
                while(size--) sections.push_back(new Section{ifs});            
            }
            
            // If file version 0.3 or greater, also load the teachers and transscripts
            if(version >= "0.3") {
                ifs >> size; ifs.ignore(32767, '\n');
                while(size--) teachers.push_back(new Teacher{ifs});

                ifs >> size; ifs.ignore(32767, '\n');
                while(size--) transcripts.push_back(new Transcript{ifs});            
            }
            
            
            // If an error occurred warn user, otherwise show the loaded data
            if(!ifs) throw std::runtime_error{"File contents bad"};
            show_data();
        } catch (std::exception& e) {
            error("Unable to open school", e);
        }
    }
}

void Mainwin::on_new_student_click() {     // Create a new student
    try {
        EntryDialog name{*this, "Student name?"};
        if(name.run() == Gtk::RESPONSE_OK) name.hide();
        else return;  // Other response codes are at 
        //    https://developer.gnome.org/gtkmm/stable/classGtk_1_1ResponseType__Wrapper.html
        
        EntryDialog email{*this, "Student email?"};
        if(email.run() == Gtk::RESPONSE_OK) email.hide();
        else return;

        int grade = select("Student grade?", 12, 1);
        if(grade < 1) return;
        
        students.push_back(new Student{name.get_text(), email.get_text(), grade});
    } catch(std::exception& e) {
        error("Invalid input", e);
    }
    show_data(View::STUDENTS);
}
void Mainwin::on_new_parent_click() {      // Create a new parent
    try {
        EntryDialog name{*this, "Parent name?"}; 
        if(name.run() == Gtk::RESPONSE_OK) name.hide();
        else return;
        
        EntryDialog email{*this, "Parent email?"}; 
        if(email.run() == Gtk::RESPONSE_OK) email.hide();
        else return;
        
        parents.push_back(new Parent{name.get_text(), email.get_text()});
    } catch(std::exception& e) {
        error("Invalid input", e);
    }
    show_data(View::PARENTS);
}
void Mainwin::on_new_teacher_click() {      // Create a new teacher
    try {
        EntryDialog name{*this, "Teacher name?"}; 
        if(name.run() == Gtk::RESPONSE_OK) name.hide();
        else return;
        
        EntryDialog email{*this, "Teacher email?"}; 
        if(email.run() == Gtk::RESPONSE_OK) email.hide();
        else return;
        
        teachers.push_back(new Teacher{name.get_text(), email.get_text()});
    } catch(std::exception& e) {
        error("Invalid input", e);
    }
    show_data(View::TEACHERS);
}
void Mainwin::on_student_parent_click() {  // Relate student and parent
    try {
        Gtk::Dialog d{"Relate Student to Parent", *this};
        auto vbox = d.get_content_area();
        
        ComboBoxContainer<std::vector<Student*>> cbt_students(students, students.size()-1);
        vbox->pack_start(cbt_students);
        
        ComboBoxContainer<std::vector<Parent*>> cbt_parents(parents, parents.size()-1);
        vbox->pack_start(cbt_parents);
        
        d.add_button("Cancel", 0);
        d.add_button("Relate", 1);
        
        d.show_all();
        if(d.run() == 1) {
            int student = cbt_students.get_active_row_number();
            int parent = cbt_parents.get_active_row_number();
            students.at(student)->add_parent(*parents.at(parent));
            parents.at(parent)->add_student(*students.at(student));
        }
    } catch(std::exception& e) {
        error("Unable to relate", e);
    }
    show_data(View::STUDENTS);
}
void Mainwin::on_new_course_click() {      // Create a new course
    try {
        // Select subject
        std::string s = "Subject name?\n\n";
        for(int i=0; i<subjects_vector.size(); ++i) {
            s += std::to_string(i) + ") " + subject_to_string.at(subjects_vector[i]) + '\n';
        }
        
        EntryDialog ds{*this, s}; 
        if(ds.run() == Gtk::RESPONSE_OK) ds.hide();
        else return;

        Subject subject = subjects_vector.at(std::stoi(ds.get_text()));
        
        // Select grade
        EntryDialog grade{*this, "Grade (1-12)?"}; 
        if(grade.run() == Gtk::RESPONSE_OK) grade.hide();
        else return;
        
        courses.push_back(new Course{subject, std::stoi(grade.get_text())});
    } catch(std::exception& e) {
        error("Invalid input", e);
    }
    show_data(View::COURSES);
}
void Mainwin::on_new_section_click() {      // Create a new section
    try {
        // Select Course
        Gtk::Dialog d{"Course", *this};
        auto vbox = d.get_content_area();
        
        ComboBoxContainer<std::vector<Course*>> cbt_courses(courses, courses.size()-1);
        vbox->pack_start(cbt_courses);
        
        ComboBoxContainer<std::vector<Teacher*>> cbt_teachers(teachers, teachers.size()-1);
        vbox->pack_start(cbt_teachers);
        
        Gtk::HBox hbox;
        Gtk::Label l_year("Year:");
        Gtk::SpinButton sb_year;
        sb_year.set_range(2020, 2100);
        sb_year.set_increments(1, 25);
        hbox.pack_start(l_year);
        hbox.pack_start(sb_year);
        vbox->pack_start(hbox);

        d.add_button("Cancel", 0);
        d.add_button("Fall", 1);
        d.add_button("Spring", 2);
        d.add_button("Summer", 3);
        d.show_all();
        int r = d.run();
        if(!r) return;
        Course& course = *courses.at(cbt_courses.get_active_row_number());
        Teacher& teacher = *teachers.at(cbt_teachers.get_active_row_number());
        Semester semester = (r==1) ? Semester::FALL :
                           ((r==2) ? Semester::SPRING : Semester::SUMMER);
        
        int year = sb_year.get_value();
/*        
        // Select max students
        EntryDialog x{*this, "Maximum Students"};
        if(!x.run()) return;
        int max_students = std::stoi(x.get_text());
*/        
        sections.push_back(new Section{course, semester, year, teacher});
    } catch(std::exception& e) {
        error("Invalid input", e);
    }
    show_data(View::SECTIONS);
}
void Mainwin::on_new_transcript_click() {  // Create a new transcript
        // Select Student
        Gtk::Dialog d{"Create Transcript", *this};
        auto vbox = d.get_content_area();

        ComboBoxContainer<std::vector<Student*>> cbt_students(students, students.size()-1);
        vbox->pack_start(cbt_students);

        ComboBoxContainer<std::vector<Section*>> cbt_sections(sections, sections.size()-1);
        vbox->pack_start(cbt_sections);
        
        d.add_button("Cancel", 0);
        d.add_button("Create", 1);

        d.show_all();
        if(d.run() != 1) return;  
        
        Student& student = *students.at(cbt_students.get_active_row_number());
        Section& section = *sections.at(cbt_sections.get_active_row_number());
        
        transcripts.push_back(new Transcript{student, section});
        
        show_data(View::TRANSCRIPTS);
}
void Mainwin::on_set_grade_click() {       // Change a grade in a transcript 

        Gtk::Dialog d{"Assign Grade", *this};
        auto vbox = d.get_content_area();

        // Select Transcript
        ComboBoxContainer<std::vector<Transcript*>> cbt_transcripts(transcripts, transcripts.size()-1);
        vbox->pack_start(cbt_transcripts);

        // Select Grade using Button
        d.add_button("Cancel", -1);
        int index = 0;
        for(Grade grade : grades_vector) d.add_button(grade_to_string.at(grade), index++);

        d.show_all();
        try {
            int result = d.run();
            if(result < 0 || result >= grades_vector.size()) return;  

            Transcript& transcript = *transcripts.at(cbt_transcripts.get_active_row_number());
            transcript.assign_grade(grades_vector.at(result));
        } catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Invalid transcript selected"}.run();
        }
        show_data(View::TRANSCRIPTS);
}
void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name(TITLE);
    auto logo = Gdk::Pixbuf::create_from_file("smart_logo.png");
    dialog.set_logo(logo);
    dialog.set_version("Version " + VERSION);
    dialog.set_copyright("Copyright " + COPYRIGHT);
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"George F. Rice"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "mohamed_hassan, licensed under the Pixabay License https://pixabay.com/illustrations/learning-graduation-college-2963757/",
        "Icons made by Becris, Pixel Perfect, and Freepik https://www.flaticon.com", 
    };
    dialog.set_artists(artists);
    dialog.run();
}

// /////////////////
// U T I L I T I E S
// /////////////////

void Mainwin::show_data(View view) {
    static View current_view;
    if(view != View::SAME) current_view = view;
    
    std::ostringstream oss;
    
    if(current_view == View::STUDENTS) {
        oss << "    <b><big>Students</big></b>\n\n";
        for(int i=0; i<students.size(); ++i) 
            oss << students.at(i)->full_info() << '\n';
            
    } else if(current_view == View::PARENTS) {
        oss << "    <b><big>Parents</big></b>\n\n";
        for(int i=0; i<parents.size(); ++i) 
            oss << parents.at(i)->full_info() << '\n';

    } else if(current_view == View::TEACHERS) {
        oss << "    <b><big>Teachers</big></b>\n\n";
        for(int i=0; i<teachers.size(); ++i) 
            oss << teachers.at(i)->full_info() << '\n';

    } else if(current_view == View::COURSES) {
        oss << "    <b><big>Courses</big></b>\n\n";
        for(auto course : courses) 
            oss << *course << '\n';

    } else if(current_view == View::SECTIONS) {
        oss << "    <b><big>Sections</big></b>\n\n";
        for(auto section : sections) 
            oss << *section << '\n';

    } else if(current_view == View::TRANSCRIPTS) {
        oss << "    <b><big>Transcripts</big></b>\n\n";
        for(auto transcript : transcripts) 
            oss << *transcript << '\n';

    } else {
        current_view = View::STUDENTS;
    }
            
    display->set_markup(oss.str());
}

// Returns index of selected student, or -1 for Cancel / Close
int Mainwin::select_student() {
    std::string prompt = "Select Student\n\n";
    for(int i=0; i<students.size(); ++i)
        prompt += std::to_string(i) + ") " + students[i]->to_string() +'\n';
    return select(prompt, students.size()-1);
}

// Returns index of selected parent, or -1 for Cancel / Close
int Mainwin::select_parent() {
    std::string prompt = "Select Parent\n\n";
    for(int i=0; i<parents.size(); ++i)
        prompt += std::to_string(i) + ") " + parents[i]->to_string() +'\n';
    return select(prompt, parents.size()-1);
}

// Returns int between [min, max], or min-1 for Cancel / Close
int Mainwin::select(std::string prompt, int max, int min) {
    int selection = min-1;
    while(true) {
        try {
            EntryDialog dialog{*this, prompt}; 
            int response = dialog.run();
            if(response == Gtk::RESPONSE_OK) {
                selection = std::stoi(dialog.get_text());
                if (min <= selection && selection <= max) break;
                throw std::out_of_range{"Invalid selection"};
            } else {
                selection = -1; // Likely Cancel or X
                break;
            }
        } catch(std::exception& e) {
            error("Invalid selection", e);
        }
    }
    return selection;
}

void Mainwin::on_easter_egg() {
    const std::vector<std::string> names{
        "Enrique Young",  // student
        "Isabella Young", // student
        "Biniti Adani", // student
        "James Montgomery", //student
        "Robert Young",
        "Susan Young",
        "Nimish Adani",
        "Oscar Montgomery",
      };
    const std::vector<std::string> emails{
        "eyoung@gmale.com",
        "iyoung@fmale.com",
        "biniti@myschool.org",
        "james.q.montgomery@british.uk",
        "bob-young@woohoo.com",
        "youngsr@uta.edu",
        "nimish.adani@hatmail.com",
        "oscar.the.m@funville.net",
      };
    const std::vector<int> grades {
          1, 5, 3, 12, // For students only
      };
      
    try {
        for(int i=0; i<grades.size(); ++i)
            students.push_back(new Student{names[i], emails[i], grades[i]});
        for(int i=grades.size(); i<names.size(); ++i)
           parents.push_back(new Parent{names[i], emails[i]});
        students[0]->add_parent(*parents[0]); parents[0]->add_student(*students[0]);
        students[0]->add_parent(*parents[1]); parents[1]->add_student(*students[0]);
        students[1]->add_parent(*parents[0]); parents[0]->add_student(*students[1]);
        students[1]->add_parent(*parents[1]); parents[1]->add_student(*students[1]);
        students[2]->add_parent(*parents[2]); parents[2]->add_student(*students[2]);
        students[2]->add_parent(*parents[1]); parents[1]->add_student(*students[2]);
        students[3]->add_parent(*parents[1]); parents[1]->add_student(*students[3]);
        students[3]->add_parent(*parents[2]); parents[2]->add_student(*students[3]);
        students[3]->add_parent(*parents[3]); parents[3]->add_student(*students[3]);

        const std::vector<std::string> tnames = {
            "Elizabeth Crabtree",
            "Saint Bingham",
            "Kermit Harness",
        };
        
        const std::vector<std::string> temails = {
            "crabtree@hallsferry.edu",
            "bingham@hallsferry.edu",
            "kharness@vwsd.org",
        };
        for(int i=0; i<tnames.size(); ++i)
            teachers.push_back(new Teacher{tnames[i], temails[i]});

        int i= 0;
        while(i < 31) {
            for(Subject subject : subjects_vector) {
                int grade = std::min(i++ % 3 + 1, 12);
                courses.push_back(new Course{subject, grade});
            }
        }
        
        for(int i=0; i<=2; ++i) {
            Semester semester = static_cast<Semester>(i);
            for(int j=0; j<=15; ++j) {
                Course course = *courses.at(rand() % courses.size());
                sections.push_back(new Section{course, semester, 2021, *teachers[i]});
            }
        }
        
        show_data();
    } catch(std::exception& e) {
        error("Easter Egg failed", e);
    }
}

void Mainwin::error(std::string msg, std::exception& e) {
    Gtk::MessageDialog{*this, msg + '\n' + e.what(), false, Gtk::MESSAGE_WARNING}.run();
}
