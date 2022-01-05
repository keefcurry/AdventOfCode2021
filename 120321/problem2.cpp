#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <bitset>
using namespace std;

bitset<12> getOGR(vector<string> arr, int count, int bitSize){
    int one = 0, zero = 0;
    string ogr_str = "";
    vector<string> array = arr;
    for(int j=0;j<bitSize;j++){
        for(int i=0;i<array.size();i++){
            if(array.at(i)[(int)j] == '0') {
                zero++;
            }
            if(array.at(i)[(int)j] == '1') {
                one++;
            }
            cout << "column: " << j << ", row: " << i+1 << " - " << array.at(i)[(int)j] << ": " << zero << " " << one << endl;
        }
        if(zero > one) {
            vector<string> temp;
            for(int i=0;i<array.size();i++){
                if(array.at(i)[j] == '0') {
                    temp.push_back(array.at(i));
                }
            }
            array = temp;
        }
        if(one >= zero) {
            vector<string> temp;
            for(int i=0;i<array.size();i++){
                if(array.at(i)[j] == '1') {
                    temp.push_back(array.at(i));
                }
            }
            array = temp;
        }
        if(array.size() == 1) {
            ogr_str = array.at(0);
            bitset<12> ogr(ogr_str);
            return ogr;
        }
        if(array.size() <= 2){
            ogr_str = (array.at(0)[j+1] == '1') ? array.at(0) : array.at(1);
            // cout << array.at(0) << endl;
            // cout << ogr_str << endl;
            bitset<12> ogr(ogr_str);
            return ogr;
        }

        zero = 0;
        one = 0;
    }

    bitset<12> org(ogr_str);
    return org;
}

bitset<12> getCSR(vector<string> arr, int count, int bitSize){
    int one = 0, zero = 0;
    string csr_str = "";
    vector<string> array = arr;
    for(int j=0;j<bitSize;j++){  
        for(int i=0;i<array.size();i++){
            if(array.at(i)[(int)j] == '0') {
                zero++;
            }
            if(array.at(i)[(int)j] == '1') {
                one++;
            }
            cout << "column: " << j << ", row: " << i+1 << " - " << array.at(i)[(int)j] << ": " << zero << " " << one << endl;
        }
        //cout << j << ": "<< zero << ", " << one << endl;
        if(zero <= one) {
            vector<string> temp;
            for(int i=0;i<array.size();i++){
                if(array.at(i)[j] == '0') {
                    temp.push_back(array.at(i));
                }
            }
            array = temp;
        }
        if(one < zero) {
            vector<string> temp;
            for(int i=0;i<array.size();i++){
                if(array.at(i)[j] == '1') {
                    temp.push_back(array.at(i));
                }
            }
            array = temp;
        }
        if(array.size() == 1) {
            csr_str = array.at(0);
            bitset<12> csr(csr_str);
            return csr;
        }
        if(array.size() <= 2){
            csr_str = (array.at(0)[j+1] == '0') ? array.at(0) : array.at(1);
            bitset<12> csr(csr_str);
            return csr;
        }
        cout << "**********"<< array.size() << endl;
        zero = 0;
        one = 0;

        cout << csr_str << endl;
    }

    bitset<12> csr(csr_str);
    return csr;
}

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
    //oxygen_gen_rating most common value (0 or 1)
    //once that is decided remove all other list items beginning with the lesser size
    //--ex if most bits start with 1 remove all the bitsets that start with 0

    //co2_scru_rating least common value (0 or 1)
    //once that is ddecided remove all other list items begginning with the greater size
    //--ex if least bits start with 1 remove all the bitsets starting with 0
    int bit_size = 12;
    //int *one_count = 0, *zero_count = 0;
    int total_count = 0;
    for(int i=0;i<bit_size;i++){
        for(int j=0;j<array.size();j++){
            if(array.at(j)[i] == '0') {
                //zero_count++;
            }
            if(array.at(j)[i] == '1') {
                //one_count++;
            }
            total_count++;
        }
    }

    //cout << total_count << endl;
    
    bitset<12> CSR = getCSR(array, total_count, bit_size);
    cout << CSR << endl;
    bitset<12> OGR = getOGR(array, total_count, bit_size);
    cout << OGR << endl;

    
    cout << CSR.to_ulong() * OGR.to_ulong() << endl;

    //int life_support_rating = (int)OGR.to_ulong * (int)CSR.to_ulong;
    //cout << life_support_rating << endl;
    return 0;
}