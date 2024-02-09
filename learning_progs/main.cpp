#include <iostream>
using namespace std;

class Animal{
    
    string species;
    string color;
    string habitat;
    
    // public: //should be public or else cannot be accessed in the function displayDetails and neither can these arguments be assigned to the instance variables.
    // Animal(string species,string color, string habitat) : species(species), color(color), habitat(habitat) {}
    
    //or
    public:
    Animal(string species,string color, string habitat) {
        
        this -> species = species;
        this -> color = color;
        this -> habitat = habitat; 

        //initializer lists can also be used.
    } 
    
        
    void displayDetails(){
            cout << "My specie is, " <<species; 
    }    
        
    
    
};

int main(){
    
    /*
    int id = 20;
    
    for(int i = 10;i<20;i++){
        
        id = 10;
        //https://stackoverflow.com/questions/7992332/variable-declared-in-for-loop-is-local-variable
        
        cout << "Value of i: "<<i<<endl;
    }
    printf("id :  %i",id); // id = 10. If we redefine id as int id = x in for loop, then the value remains the same as that of the global id, loop local variables end with the end of loop
    */
    
    Animal zebra("Zebra","Black&White","Savannah");
    zebra.displayDetails();
    
    
    return 0;
}