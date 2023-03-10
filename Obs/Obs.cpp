#include <iostream>#include <fstream>     
 using namespace std;
#include "State.cpp"

int main()
{
	setlocale(LC_ALL, "Russian");
	FileEditor a("C:\\101\\infile.txt");
	string b;
	cin >> b;	
	a.write(b);
}	