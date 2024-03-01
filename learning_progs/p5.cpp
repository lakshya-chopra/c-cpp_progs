#include<iostream>

using namespace std;

//Program to remove duplicates from a SORTED array

int removeDuplicates(int arr[],int n){ 
	
	//imp: https://stackoverflow.com/a/6567846
	int i = 0;
	int j{}; //another way (j = 0)

	int temp[n];


	//we will add unique elements to temp and also check if arr[i] == arr[i+1], because if it is, then we won't add it and add it only when arr[i] != arr[i+1], else we risk adding the same elements more than once.

	for(i = 0;i<n-1;i++){

		//i < n-1, because if not, then we reach out of the array.
		if (arr[i] != arr[i+1]){
			temp[j++] = arr[i];
		}
	}
	//last element : (n-1)^th is still not stored, and we must store it separately.
	temp[j++] = arr[n - 1];
 
    for (int i = 0; i < j; i++) {//until we reach the last element of temp
        arr[i] = temp[i];
	//https://stackoverflow.com/questions/48730860/how-to-remove-unused-space-in-an-array
	}
	return j;
}



int main(){

	int arr[] = {1,2,3,4,4,5,5,6,6,6,7};
	int len = 11;

	int j = removeDuplicates(arr,len);
	for(int i=0;i<j;i++){
		cout<<arr[i]<<endl;
	}


}