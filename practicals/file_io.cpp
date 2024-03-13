#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int main(){

    fstream f;
    f.open("test2.txt",fstream::in|fstream::out);

    fstream f2;
    f2.open("file_clean.txt",fstream::in|fstream::out | fstream::trunc);

    string line;

    while(!f.eof()){

        getline(f,line);
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end()); //need to include <algorithm>
        //https://stackoverflow.com/a/83538

        f2 << line;


    }
    f.close();
    f2.close() ;


    return 0;

}