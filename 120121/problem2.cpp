#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int main() {

    //reads data into the vector(array)
    vector<int> array;
    fstream newFile;
    newFile.open("input1.txt",ios::in);
    if(newFile.is_open()){
        string tp = "";
        while(getline(newFile, tp)){
        //cout << tp << "\n";
        array.push_back(stoi(tp));
        }
    }

    int A = 0, B = 0, C = 0; // firts window
    int F = 0, G = 0, H = 0; // second window

    //window A and B
    int arr1[3] {A,B,C}, arr2[3] {F,G,H};

    int total_1 = 0, total_2 = 0, count = 0;

    for(int i=0; i<array.size();i++){
        if(i+3 < array.size()){
            for(int l=0, p=l+1; l<3; l++,p++){
                arr1[l] = array.at(i+l);
                arr2[l] = array.at(i+p);
                if(l == 2) {
                    total_1 = accumulate(arr1, arr1+3, total_1);
                    total_2 = accumulate(arr2, arr2+3, total_2);
                    if(total_2 > total_1)
                        count++;
                    cout << total_1 << "\n" << total_2 << "\n";
            }
        }
        total_1 = 0;
        total_2 = 0;
        cout << " --- " << count << endl;
        }
    }
    cout << count << endl;

    return 0;
}