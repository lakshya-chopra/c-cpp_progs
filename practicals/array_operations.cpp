#include <iostream>
// #include <typeinfo>
#include <cmath>

class Array
{

public:
    int len;
    int curIndex{}; // initially set to 0
    int *arr;

    Array(int len)
    {

        this->len = len;

        arr = new int[len];
    }

    void insertElement(auto value)
    {

        // string type = typeid(value).name();
        // // https://stackoverflow.com/a/81886

        if (curIndex != len)
        {
            arr[curIndex++] = value;
            return;
        }
        else
        {
            std::cout << "array completely filled";
            return;
        }
    }

    void sortArr()
    {
        int i, j;

        for (i = 0; i < len - 1; i++)
        {
            //after each iteration, the (len - 1 - i)^th element is at it's correct position.

            for (j = 0; j < len - i - 1; j++){
                if (arr[j] > arr[j + 1])
                    std::swap(arr[j], arr[j + 1]);
                    //bubble sort
            }
        }
        return;
    }

    void removeDuplicates()
    {

        // we need to ensure that the arr is sorted.

        sortArr();

        int temp[len];

        int j{};
        for (int i = 0; i < len - 1; i++)
        {
            if (arr[i] != arr[i + 1])
            {
                temp[j++] = arr[i];
            }
        }
        temp[j++] = arr[len - 1];

        for (int i = 0; i < len; i++)
        {
            arr[i] = temp[i];
        }

        this->len = j;
    }

    int binSearch(int val,int low,int high){

        /*we compute the mid value and first check if the mid value (i.e. arr[mid_idx]) == val, if not then check if it is greater or lower and proceed as follows, ensure that the array is already sorted.*/


        sortArr(); //just for confirmation.
        int mid_idx = floor((high + low)/2);


        if (low >= high){
            return -1; //not found
        }

        if(val == arr[mid_idx]){
            return mid_idx;
        }
        else if (val < arr[mid_idx]){
            return binSearch(val,low,mid_idx - 1);
        }
        else{
            return binSearch(val,mid_idx+1,high);
        }

    }
    static int* mergeTwoArrays(Array * arr1, Array * arr2){

        int len2 = (*arr1).len + (*arr2).len;

        int *arr3 = new int[len2];

        int j{};
        
        //first add elements of arr1, and then start at the next index for adding ELemENTS of arr2.
        for(int i = 0;i<(*arr1).len;i++){
            arr3[j++] = (*arr1).arr[i];
        }

        for(int i = 0;i<(*arr2).len;i++){
            arr3[j++] = (*arr2).arr[i];
        }

        return arr3; //returning an address to an integer, hence, int*
    }
    void printArr(){
        std::cout<<"\nArray overview:"<<std::endl;
        for(int i = 0;i<curIndex;i++){

            std::cout<<arr[i]<<" ";

        }
        std::cout<<"\n";
    }
};

int main()
{

    Array *arr = new Array(10); // arr: reference to the object that has been dynamically created.

    for(int i = 1;i<11;i++){
        arr->insertElement(i);
    }
    arr->printArr();

    Array *arr2 = new Array(5);
    arr2->insertElement(10);
    arr2->insertElement(20);
    arr2->insertElement(15);
    arr2->insertElement(5);
    arr2->insertElement(8);

    arr2->printArr();
    arr2->sortArr();

    std::cout<<"\ncheck if 5 exists in the arr2"<< std::endl;
    int val = arr2->binSearch(5,0,5);
    if(val != -1){
        std::cout<<"Yes, it does! "<<std::endl;
    }
    else{
        std::cout<<"No, it doesnt"<<std::endl;
    }

    std::cout<<"array after sorting"<<std::endl;
    arr2->printArr();

    std::cout<<"\nMergIng arr and arr2"<<std::endl;
    int *arr_new = Array::mergeTwoArrays(arr,arr2);

    for(int i = 0;i<(arr->len + arr2->len);i++){
        std::cout<<arr_new[i]<<" ";
    }


    delete arr;
}
