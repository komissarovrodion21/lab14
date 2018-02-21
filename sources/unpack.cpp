#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Email {
  string nickname;
  string server;
};

struct Person {
  string  first_name;
  string  last_name;
  Email        email;
  size_t       age;
  string  phone;
};

int main(int argc, char* argv[])
{
   try {
      string Path = argv[1];
      Person file;

      YAML::Node node2 = YAML::LoadFile(Path);
      file.first_name = node2["person"]["First name"].as<std::string>();
      file.last_name = node2["person"]["Last name"].as<std::string>(); 
      file.email.nickname = node2["person"]["Email"].as<std::string>();
      file.age = node2["person"]["Age"].as<size_t>();
      file.phone= node2["person"]["Phone"].as<std::string>();  
       
      cout << "[Person]" << endl;
      cout << "First name: " << file.first_name << endl;
      cout << "Last name:  " << file.last_name << endl;
      cout << "Email:      " << file.email.nickname << endl;
      cout << "Age:        " << file.age << endl;
      cout << "Phone:      " << file.phone << endl;
      
  }
  catch(const exception& e) {
    cout << e.what() << endl;
  }
}
