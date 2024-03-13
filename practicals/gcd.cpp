#include<iostream>

using namespace std;

int gcd_recur(int a, int b){

    int c = min(a,b);

    int d = (c == a)? b : a; //if c==a -> b else a; //max element

    if(c == 0){ //remainder is 0.
        return d;
    }
    else{
        return gcd_recur(c,d%c);
    }

}


int gcd(int a,int b){

    //again choose the smaller element of the two:
    int c = min(a,b);
    int d = (c == a)? b : a;

    int gcd = 1;

    for(int i = 2;i<=c;i++){
        if (d%i == 0){
            gcd = i;
        }
    }
    return gcd;

}

int main(){

    int res = gcd_recur(25,100);
    cout<<"GCD: "<<res<<endl;

    int res2 = gcd(25,100);
    cout<<"GCD: "<<res2<<endl;

}