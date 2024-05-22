#include <iostream>
     using namespace std;

     class first_class {

                     
     public:
        virtual void printit() {
             cout << "Print from first class" << endl;
            }
     }; 

     class second_class : public first_class  {
     public:
         void printit() {
             cout << "Print from second class" << endl;
             }
     }; 

     class third_class : public first_class  {
     }; 

     class four_class : public first_class  {
     public:
         void printit() {
             cout << "Print from four class" << endl;
             }
     }; 

     class five_class : public four_class  {
     }; 

int  main() {

     first_class one;        
     one.printit();   
     second_class second;     
     second.printit();    
     third_class third;    
     third.printit();
     four_class four;     
     four.printit();
     five_class five;     
     five.printit();
    return 0;
} 