#include <iostream>
using namespace std;
class OOPClass{
private:
	static int count;
public:
	OOPClass(){
	count++;
	cout<<"Instance of OOPClass created"<<endl;
};
	static void printCount(){
		cout<<"Instance of OOPClass: "<<count<<endl;
	}
};

int OOPClass::count = 0;

int main(){
	OOPClass a1;
	OOPClass a2;
	OOPClass a3;
	OOPClass::printCount();

	OOPClass a4;
	OOPClass a5;
	OOPClass::printCount();
}
