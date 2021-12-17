#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <bitset>
using namespace std;

int main(int argc, char* argv[]) {

    vector<string> array;
    fstream newFile;
    newFile.open("input1.txt",ios::in);
    if(newFile.is_open()){
        string tp = "";
        while(getline(newFile, tp)){
        //cout << tp << "\n";
        array.push_back(tp);
        }
    }

}