/*Minimum Number of Jumps */

#include <iostream>
// #include <vector>
#include <limits.h>
using namespace std;

int minJumps(int arr[],int c_idx,int length){
    
    //use recursive approach, for each index i , we'll check arr[i] possibilities.
    
    if (length == 1){
        return 0;
    }
    if (c_idx >= (length-1)){ //if the current index is ahead the last element
        
        return 0;        

    }
    if (arr[c_idx] == 0){
        return -1; // no jump possible.
    }
    int min_jumps = INT_MAX; //initially keep it INT_MAX, later we'll change it
    int i;
    
    for(i = c_idx + 1; i <= arr[c_idx] + c_idx && i <= (length-1); i++ )
    {
        int jumps = minJumps(arr,i,length);
        
        if (jumps + 1 < min_jumps){ //jumps + 1 because 0 to (i)th index accounts for an extra jump.
        
            min_jumps = jumps + 1;
            
        }
        
    }
    
    return min_jumps;
}

int main() {
    
    int arr[] = {1, 4, 3, 2, 6, 7,1};
    int length = sizeof(arr)/sizeof(arr[0]);
    
    
    cout << "Min number of jumps required to traverse the entire list are " << minJumps(arr,0,length) << endl;
    
    return 0;
}

