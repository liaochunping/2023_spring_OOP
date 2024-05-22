/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Student
		{
			int ID;
			string sName;
        public:
			Student(const string& _sName):sName(_sName){}
			Student() = default;
			Student(const Student& o) = default;
		};
int main(){
		Student s1;
		Student s2(s1);
}
