    //
    // Empty Parent Vector
    // 
    
    {
      // Constructor Data
      std::vector<std::string> names{
        "Enrique Young",
      };
      std::vector<std::string> emails{
        "eyoung@gmale.com",
      };
      int grade = 1;
      
      // Construct units under test
      std::vector<Person*> people;
      Student s1{names[0], emails[0], grade};

      people.push_back(&s1);
    
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
        std::string g = std::to_string(grade);
        if (s.find(g) != std::string::npos) {
            std::cerr << "FAIL <<: grade " << g << " was found in " << s << std::endl;
            result |= vector;
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
        std::string g = std::to_string(grade);
        if (s.find(g) != std::string::npos) {
            std::cerr << "FAIL to_string: grade " << g << " was found in " << s << std::endl;
            result |= vector;
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
        std::string g = std::to_string(grade);
        if (s.find(g) == std::string::npos) {
            std::cerr << "FAIL full_info: grade " << g << " NOT found in " << s << std::endl;
            result |= vector;
        }
      }
    }

