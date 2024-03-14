#include<iostream>
#include<stdexcept>

using namespace std;
#include<cmath>

int check_for_error(double a, double b, double c){

    try{

            if (a <= 0 || b <= 0 || c<= 0){
                throw invalid_argument("invalid args");
            }
        
    }
    catch(invalid_argument &e){
        cerr<<"\n"<<e.what()<<endl;
        return -1;

    }
    return 0;


}

class Triangle{

    private:
    double a,b,c;

    public:
    Triangle(double a, double b, double c){

        if (check_for_error(a,b,c) != -1) {
            this->a = a;
            this->b = b;
            this->c = c;


        }   
        else{
            exit(-1);
        }

    }

    double area(double base,double height){ //if parameter given then 1/2b*h

        try{
            if (base <= 0 || height <= 0){

                throw invalid_argument("invalid values of base or height");

            
            }
        }
        catch(invalid_argument &e){

            cerr<<"\n"<<e.what()<<endl;
            return -1;

        }
        return 1/2*base*height;

    }

    //heron's
    double area(){
        double s = (a+b+c)/2;
        return sqrt((s*(s-a)*(s-b)*(s-c)));
    }

};

int main(){

    Triangle t1(4,5,6);

    //method overloading
    cout<<"\n\n\nArea of triangle with sides: 4, 5, 6: "<<t1.area()<<endl;

    Triangle t2(3,4,5);
    cout<<"Area of triangle with sides: 3, 4, 5"<<t2.area(3,4)<<"\n"<<endl;

}
