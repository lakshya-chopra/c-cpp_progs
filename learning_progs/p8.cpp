#include <iostream>
using namespace std;

int main()
{
    char *a = new char(65); //another way to initialize some data, dynamically allocated, so make sure you delete it.
    cout<<*a<<endl;

    delete a;

    /*Using the delete operator on an object deallocates its memory. A program that dereferences a pointer after the object is deleted can have unpredictable results or crash.
    Refer to: https://learn.microsoft.com/en-us/cpp/cpp/delete-operator-cpp?
    
    */

   int z = 10;
   int y = 8;

   int x;
   
   x = z + y++; 

   //postfix (++) has a higher precedence than most other operators, but it seems to get executed at the end, why? Because that's the nature of postfix, postfix does increment the value but returns the old value. https://stackoverflow.com/a/9255317

   cout<<"x: "<<x<<"\ny: "<<y<<endl;

    return 0;
}