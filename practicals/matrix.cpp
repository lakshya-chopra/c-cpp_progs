#include<iostream>
#include<cmath>

using namespace std;

class Matrix
{
    //a matrix is 2 dimensional array.
    int r; //rows
    int c; //columns
    int *mat;

    public:
    Matrix(int rows, int columns){
        r = rows;
        c = columns;


        mat = new int[r*c];

    }

    void insert(int val,int i, int j){

        *(mat + i*c + j) = val;

    }


    void traverse(){
        int i,j;

        for(int i = 0;i<r;i++){

            for(int j = 0;j<c;j++){
                int elem = *(mat + i*c + j);
                cout<<elem<<" ";
            }
            cout<<"\n"; //newline after each row.
        }
    }
//     void transpose(){
//     int i, j; 
//     int new_mat[r][c];
//     for (i = 0; i < r; i++) {
//         for (j = 0; j < c; j++) 
//             new_mat[i][j] = mat[j][i]; 
// } 
  
//     }

};

int main(){

    Matrix *mat = new Matrix(3,3);

    int i,j;
    int c{};

    for(int i = 0; i<3;i++){

        for(int j = 0;j<3;j++){
            mat->insert(c++,i,j);
        }

    }

    mat->traverse();

    return 0;
}
