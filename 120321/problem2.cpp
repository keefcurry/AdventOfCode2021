#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <bitset>
using namespace std;

bitset<12> getOGR(vector<string>* array, int* count, int bitSize){
    int newCount = 0;
    int one = 0, zero = 0;
    string ogr_str;
    
    for(int j=0;j<bitSize;j++){
        vector<string>* tempArray;
        for(int* i=0;i<count;i++){
            if(array->at(j)[(int)i] == '0') {
                zero++;
            }
            if(array->at(j)[(int)i] == '1') {
                one++;
            }
        }
        if(zero > one) {
            for(int i=0;i<zero;i++){
                if(array->at(j)[i] == '0') {
                    tempArray->push_back(array->at(j));
                }
            }
        }
        if(one > zero) {
            for(int i=0;i<one;i++){
                if(array->at(j)[i] == '1') {
                    tempArray->push_back(array->at(j));
                }
            }
        }
        if(tempArray->size() == 1){
            ogr_str = tempArray->at(0);
        }
    }

    bitset<12> org(ogr_str);
    cout << org << endl;
    return org;
}

bitset<12> getCSR(vector<string>* array, int* count, int bitSize){
    int newCount = 0;
    int one = 0, zero = 0;
    string csr_str;

    for(int j=0;j<bitSize;j++){
        vector<string>* tempArray;
        for(int* i=0;i<count;i++){
            if(array->at(j)[(int)i] == '0') {
                zero++;
            }
            if(array->at(j)[(int)i] == '1') {
                one++;
            }
        }
        if(zero < one) {
            for(int i=0;i<zero;i++){
                if(array->at(j)[i] == '0') {
                    tempArray->push_back(array->at(j));
                }
            }
        }
        if(one < zero) {
            for(int i=0;i<one;i++){
                if(array->at(j)[i] == '1') {
                    tempArray->push_back(array->at(j));
                }
            }
        }
        if(tempArray->size() == 1){
            csr_str = tempArray->at(0);
        }
    }
    
    bitset<12> csr(csr_str);
    cout << csr << endl;
    return csr;
}

int main(int argc, char* argv[]) {

    vector<string>* array;
    fstream newFile;
    newFile.open("input1.txt",ios::in);
    if(newFile.is_open()){
        string tp = "";
        while(getline(newFile, tp)){
        //cout << tp << "\n";
        array->push_back(tp);
        }
    }
    //oxygen_gen_rating most common value (0 or 1)
    //once that is decided remove all other list items beginning with the lesser size
    //--ex if most bits start with 1 remove all the bitsets that start with 0

    //co2_scru_rating least common value (0 or 1)
    //once that is ddecided remove all other list items begginning with the greater size
    //--ex if least bits start with 1 remove all the bitsets starting with 0
    int bit_size = 12;
    int *one_count = 0, *zero_count = 0;
    int* total_count = 0;
    for(int i=0;i<bit_size;i++){
        for(int j=0;j<array->size();j++){
            if(array->at(j)[i] == '0') {
                zero_count++;
            }
            if(array->at(j)[i] == '1') {
                one_count++;
            }
            total_count++;
        }
    }
    
    //                                  zero_count                                       one_count        
    //shrinkList(array, ogr_arr, csr_arr, (zero_count > one_count)?zero_count : one_count, (zero_count < one_count)? zero_count : one_count, left, row);
    

    bitset<12> CSR = getCSR(array, total_count, bit_size);
    bitset<12> OGR = getOGR(array, total_count, bit_size);

    
    cout << CSR << ", " << OGR << endl;

    //int life_support_rating = oxygen_generator_rating * co2_scrubber_rating;
    return 0;
}