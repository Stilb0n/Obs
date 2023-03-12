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

class Subject : public IFileEditor {
public:
	virtual ~Subject() {
		std::cout << "Goodbye, I was the Subject.\n";
	}

	/**
	 * ћетоды управлени€ подпиской. издатель
	 */
	void Attach(IObserver* observer) override {
		list_observer_.push_back(observer);
	}
	void Detach(IObserver* observer) override {
		list_observer_.remove(observer);
	}
	void Notify() override {
		std::list<IObserver*>::iterator iterator = list_observer_.begin();
		HowManyObserver();
		while (iterator != list_observer_.end()) {
			(*iterator)->Update(message_);
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
	 * ќбычно логика подписки Ц только часть того, что делает »здатель. »здатели
	 * часто содержат некоторую важную бизнес-логику, котора€ запускает метод
	 * уведомлени€ вс€кий раз, когда должно произойти что-то важное (или после
	 * этого).
	 */
	void SomeBusinessLogic() {
		this->message_ = "change message message";
		Notify();
		std::cout << "I'm about to do some thing important\n";
	}

private:
	std::list<IObserver*> list_observer_;
	std::string message_;
};
