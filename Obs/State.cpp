#include <iostream>
#include <fstream> 
#include "IFileEditor.cpp"
using namespace std; 


class FileEditor {
bool existing = 1;
int size = 0;
fstream file;
bool edited = 0;
  
 public:

	 FileEditor(const char* path)
 {
	 file.open(path);
	 if (file.bad() == true)
		 existing = 0;
	 else
	 {
		 file.seekg(0, std::ios::end);
		 size = file.tellg();
		 cout << size;
	 }
	 file.seekg(0, std::ios::beg);
 }


	
	 void write(string data) {
		 if (existing)
		 {
			 file << data;
			 edited = 1;
			 file.seekg(0, std::ios::end);
			 size = file.tellg();
			 cout << size;
		 }
	 }
	
	
};	
