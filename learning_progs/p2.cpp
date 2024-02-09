#include <iostream>
using namespace std;


int main(){

	int n{}; // default initialization to 0 , {} -> 0. https://learn.microsoft.com/en-us/cpp/cpp/initializers?view=msvc-170

	/*
	cout << "Enter any integer greater than 0 : " << endl;
	cin >> n;

	cout << n;

	printf("%d",n );
	*/


    int myArr1[]{ 1, 2, 3, 4 };
    int myArr2[3] = { 5, 6, 7 };
    int myArr3[5] = { 8, 9, 10 };

    cout << "myArr1: ";
    for (int i : myArr1){
        cout << i << " ";
    }
    cout << endl;

    cout << "Adding 1 to each element of myArr3";
    for (auto &i : myArr3) {
    	i++;
    }

    cout << endl <<"Modified Arr3:- " << endl;

    for (auto const i : myArr3) {
        cout << i << " ";
    }

	return 0;
}