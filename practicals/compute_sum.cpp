#include <iostream>
#include<cmath> //standard way of importing c libs in c++.

using namespace std;

double fun(int n){
    /*int n: number of terms of the series, upto which the sum has to be computed, the series is of the form

        Tn = (-1)^(n-1)*1/(n^n), n starting from 1.

        Sn = sum upto n terms = Tn + Sn-1, thus one could use recursion, where the base case is S1 = 1.

    */

    if(n == 1 ){
        return 1;
    }
    else{
        return pow(-1,n-1)/(pow(n,n)) + fun(n-1);
    }


}

int main(){

    int n;
    cout<<"enter an integer: "<<endl;
    cin >> n;

    double s = fun(n);
    cout<<"sum of this series is: "<<s<<endl;

    return 0;
}