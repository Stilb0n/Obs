#include <iostream>#include <fstream>   
#include "FileEditor.cpp"
 using namespace std;
 class className {
 public:
	 int b;
	 className(int j) : b(j) {}
	 void PrintB() {
		 cout << b;
	 };
 };
int main()
{
	setlocale(LC_ALL, "Russian");
	//FileEditor a("C:\\101\\infile.txt");
	//string b;
	//cin >> b;	
	//a.write(b);
	//className obj(1);
	//obj.PrintB();
	FileEditor obj("C:\\101\\infile.txt");
	EditChecker a;
	ExsistingChecker b;
	obj.Attach(&a);
	obj.Attach(&b);
	obj.write("sssssssssss");
	
	//a.EditCheck(1);
		cout << "стоп";
}	