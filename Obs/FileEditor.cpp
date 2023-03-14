#include <iostream>
#include <fstream> 
#include "IFileEditor.cpp"
using namespace std; 


class FileEditor : public IFileEditor {
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
	 void Attach(IObserver* observer) override {
		 list_observer_.push_back(observer);
	 }
	 void Detach(IObserver* observer) override {
		 list_observer_.remove(observer);
	 }
	 void Notify() override {
		 list<IObserver*>::iterator iterator = list_observer_.begin();
		 HowManyObserver();
		 while (iterator != list_observer_.end()) {
			 (*iterator)->Update(message_);
			 // зачем разыменовываю?
			 ++iterator;
		 } 
	 }

	 void SomeBusinessLogic() {
		 this->message_ = "change message message";
		 Notify();
		 std::cout << "I'm about to do some thing important\n";
	 }

private:
	 std::list<IObserver*> list_observer_;
	 std::string message_;
};	

class Subject  : public ISubject {
	// ^издатель
public:
	virtual ~Subject() {
		std::cout << "Goodbye, I was the Editor.\n";
	}

	/**
	 * Методы управления подпиской. 
	 */
	void Attach(IObserver* observer) override {
		list_observer_.push_back(observer);
	}
	void Detach(IObserver* observer) override {
		list_observer_.remove(observer);
	}
	void Notify() override {
		list<IObserver*>::iterator iterator = list_observer_.begin();
		HowManyObserver();
		while (iterator != list_observer_.end()) {
			(*iterator)->Update(message_);
			// зачем разыменовываю?
			++iterator;
		}
	}

	void CreateMessage(std::string message = "Empty") {
		this->message_ = message;
		Notify();
	}
	void HowManyObserver() {
		std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
	}


	/**
	 * Обычно логика подписки – только часть того, что делает Издатель. Издатели
	 * часто содержат некоторую важную бизнес-логику, которая запускает метод
	 * уведомления всякий раз, когда должно произойти что-то важное (или после
	 * этого).
	 */
	void SomeBusinessLogic() {
		this->message_ = "change message message";
		Notify();
		std::cout << "I'm about to do some thing important\n";
	}

private:
	0
	
};
