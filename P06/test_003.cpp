    //
    // Mixed Parent / Student Vector
    // 
    
    {
      // Constructor Data
      std::vector<std::string> names{
        "Enrique Young",  // student
        "Isabella Young", // student
        "Biniti Adani", // student
        "James Montgomery", //student
        "Robert Young",
        "Susan Young",
        "Nimish Adani",
        "Oscar Montgomery",
      };
      std::vector<std::string> emails{
        "eyoung@gmale.com",
        "iyoung@fmale.com",
        "biniti@myschool.org",
        "james.q.montgomery@british.uk",
        "bob-young@woohoo.com",
        "youngsr@uta.edu",
        "nimish.adani@hatmail.com",
        "oscar.the.m@funville.net",
      };
      std::vector<int> grades {
          1, 5, 3, 12, // For students only
      };

      // Construct units under test
      std::vector<Person*> people;
      for(int i=0; i<grades.size(); ++i)
          people.push_back(new Student{names[i], emails[i], grades[i]});
      for(int i=grades.size(); i<names.size(); ++i)
          people.push_back(new Parent{names[i], emails[i]});

      // Link students to parents and vice-versa
      dynamic_cast<Student*>(people[0])->add_parent(*dynamic_cast<Parent*>(people[4]));
          dynamic_cast<Parent*>(people[4])->add_student(*dynamic_cast<Student*>(people[0]));
      dynamic_cast<Student*>(people[0])->add_parent(*dynamic_cast<Parent*>(people[5]));
          dynamic_cast<Parent*>(people[5])->add_student(*dynamic_cast<Student*>(people[0]));
      dynamic_cast<Student*>(people[1])->add_parent(*dynamic_cast<Parent*>(people[4]));
          dynamic_cast<Parent*>(people[4])->add_student(*dynamic_cast<Student*>(people[1]));
      dynamic_cast<Student*>(people[1])->add_parent(*dynamic_cast<Parent*>(people[5]));
          dynamic_cast<Parent*>(people[5])->add_student(*dynamic_cast<Student*>(people[1]));
      dynamic_cast<Student*>(people[2])->add_parent(*dynamic_cast<Parent*>(people[6]));
          dynamic_cast<Parent*>(people[6])->add_student(*dynamic_cast<Student*>(people[2]));
      dynamic_cast<Student*>(people[2])->add_parent(*dynamic_cast<Parent*>(people[5]));
          dynamic_cast<Parent*>(people[5])->add_student(*dynamic_cast<Student*>(people[2]));
      dynamic_cast<Student*>(people[3])->add_parent(*dynamic_cast<Parent*>(people[5]));
          dynamic_cast<Parent*>(people[5])->add_student(*dynamic_cast<Student*>(people[3]));
      dynamic_cast<Student*>(people[3])->add_parent(*dynamic_cast<Parent*>(people[6]));
          dynamic_cast<Parent*>(people[6])->add_student(*dynamic_cast<Student*>(people[3]));
      dynamic_cast<Student*>(people[3])->add_parent(*dynamic_cast<Parent*>(people[7]));
          dynamic_cast<Parent*>(people[7])->add_student(*dynamic_cast<Student*>(people[3]));
    
      // Verify units
      {
        // stream out
        std::ostringstream oss;
        for(auto p : people) oss << *p << '\n';
        std::string s = oss.str();
        // Names should be present
        for(auto n : names) {
            if (s.find(n) == std::string::npos) {
                std::cerr << "FAIL <<: " << n << " NOT found in " << s << std::endl;
                result |= vector;
            }
        }
        // Emails should NOT be present
        for(auto e : emails) {
            if (s.find(e) != std::string::npos) {
                std::cerr << "FAIL <<: " << e << " was found in " << s << std::endl;
                result |= vector;
            }
        }
        // Grade should NOT be present
        for(auto gi : grades) {
            std::string g = std::to_string(gi);
            if (s.find(g) != std::string::npos) {
                std::cerr << "FAIL <<: grade " << g << " was found in " << s << std::endl;
                result |= vector;
            }
        }
      }

      {
        // to_string
        std::ostringstream oss;
        for(auto p : people) oss << p->to_string() << '\n';
        std::string s = oss.str();
        // Names should be present
        for(auto n : names) {
            if (s.find(n) == std::string::npos) {
                std::cerr << "FAIL to_string: " << n << " NOT found in " << s << std::endl;
                result |= vector;
            }
        }
        // Emails should NOT be present
        for(auto e : emails) {
            if (s.find(e) != std::string::npos) {
                std::cerr << "FAIL to_string: " << e << " was found in " << s << std::endl;
                result |= vector;
            }
        }
        // Grade should NOT be present
        for(auto gi : grades) {
            std::string g = std::to_string(gi);
            if (s.find(g) != std::string::npos) {
                std::cerr << "FAIL to_string: grade " << g << " was found in " << s << std::endl;
                result |= vector;
            }
        }
      }

      {
        // full_info
        std::ostringstream oss;
        for(auto p : people) oss << p->full_info() << '\n';
        std::string s = oss.str();
        // Names should be present
        for(auto n : names) {
            if (s.find(n) == std::string::npos) {
                std::cerr << "FAIL full_info: " << n << " NOT found in " << s << std::endl;
                result |= vector;
            }
        }
        // Emails should be present
        for(auto e : emails) {
            if (s.find(e) == std::string::npos) {
                std::cerr << "FAIL full_info: " << e << " NOT found in " << s << std::endl;
                result |= vector;
            }
        }
        // Grade should be present
        for(auto gi : grades) {
            std::string g = std::to_string(gi);
            if (s.find(g) == std::string::npos) {
                std::cerr << "FAIL full_info: grade " << g << " NOT found in " << s << std::endl;
                result |= vector;
            }
        }
      }
    }

