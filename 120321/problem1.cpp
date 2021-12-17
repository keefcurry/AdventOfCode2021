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

    //bitset<5> gamma_rate, epsilon_rate;
    
    //--example for setting a bitset
    //bitset<8> bs4(str[i]);

    //calculating the gamma_rate
    string gamma_rate_string, epsilon_rate_string;
    for(int i=0;i<12;i++){
        int zero_count = 0, one_count = 0;
        for(int j=0;j<array.size();j++) {
            if(array.at(j)[i] == '1')
                one_count++;
            if(array.at(j)[i] == '0')
                zero_count++;
            //cout << array.at(j)[i] << endl;
        }
        //cout << "zero_count: " << zero_count << " one_count: " << one_count << endl;
        if(zero_count > one_count) {
            gamma_rate_string += "0";
            epsilon_rate_string += "1";
        }
        else {
            gamma_rate_string += "1";
            epsilon_rate_string += "0";
        }

    }

    bitset<12> gamma_rate(gamma_rate_string);
    bitset<12> epsilon_rate(epsilon_rate_string);

    cout << gamma_rate << endl;
    cout << epsilon_rate << endl;
    int power_consumption = gamma_rate.to_ulong() * epsilon_rate.to_ulong();
    cout << power_consumption << endl;
    return 0;

}