#pragma once
#include <iostream>
#include <fstream> 
#include "IFileEditor.cpp"
#include <list>
using namespace std; 
class FileEditor : public IFileEditor { //издатель
public:
bool existing = 1;
int size = 0;
fstream file; 
bool edited = 0;
  
	 FileEditor(const char* path)
 {
	 file.open(path);
	 if (file.bad() == true)
		 existing = 0;
	 else
	 {
		 file.seekg(0, ios::end);
		 size = file.tellg();
		 cout << size;
	 }
	 file.seekg(0, ios::beg);
 }


	
	 void write(string data) {
		 if (existing)
		 {
			 file << data;
			 edited = 1;
			 file.seekg(0, ios::end);
			 size = file.tellg();
			 cout << size;
		 }
		 Notify();
	 }
	 void Attach(IObserver* observer) override {
		 list_observer_.push_back(observer);
	 }
	 void Detach(IObserver* observer) override {
		 list_observer_.remove(observer);
	 }
	 void Notify() override { //!!!!!!!!!!!!!!!!
		 list<IObserver*>::iterator iterator = list_observer_.begin();
		 HowManyObserver();
		 while (iterator != list_observer_.end()) {
			 (*iterator)->Update(size, existing);
			 // зачем разыменовываю?
			 ++iterator;
		 } 
	 }

	 void SomeBusinessLogic() {
		 this->message_ = "change message message";
		 Notify();
		 cout << "I'm about to do some thing important\n";
	 }




	 void HowManyObserver() {
		 cout << "There are " << list_observer_.size() << " observers in the list.\n";
	 }
	 
private:
	 list<IObserver*> list_observer_;
	 string message_;
};	



class observer: public IObserver {
private: 
	int FileSize = 0;

public:
	void Update (int size, bool existing=0)override {
		FileSize = size;
		EmptyCheck();
	}
	void EmptyCheck()
	{
		if (FileSize >0)
			cout << "файл не пустой";
	}
	};


class EditChecker : public IObserver {
private:
	int FileSize = 0;
	bool FileExisting = 0;
public:
	void Update(int size, bool existing )override {
		int oldsize = FileSize;
		FileSize = size;
		FileExisting = existing;
		EditCheck(oldsize);
	}
	void EditCheck(int oldsize)
	{
		if ((FileExisting)&&(FileSize>oldsize))
		{
			cout << "файл существует\n";
			cout << "файл изменен\n"<< "Размер: " << FileSize;
		}
		
	}
};


class ExsistingChecker : public IObserver {
private:
	bool FileExisting = 0;
	int FileSize = 0;
public:
	void Update(int size, bool existing)override {
		FileExisting = existing;
		FileSize = size;
		ExistingCheck();
	}
	void ExistingCheck()
	{
		if ((FileExisting) && (FileSize > 0))
		{
			cout << "файл существует\n";
			cout << FileSize << "размер";
		}
		if (!FileExisting) { cout << "файл не существует\n"; }
	}


};




