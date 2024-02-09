#include <iostream>
using namespace std;

int insertElement(const int elem, int pos,int arr[],int length ){ // [] -> length will be automatically determined

	for(int i = length; i>= pos; i--){

		arr[i] = arr[i-1];
	}
	arr[pos] = elem;

	return 0;
}

//driver code
int main(){

	const int length = 10;
	int arr1[length] = {0};

	
	insertElement(10,7,arr1,length);
	for(int i: arr1){
		cout << i << endl;
	}
	



}