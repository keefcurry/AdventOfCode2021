#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

int main(int argc, char* argv[]) {

    vector<string> array;
    fstream newFile;
    newFile.open("input1.txt",ios::in);
    if(newFile.is_open()){
        string tp = "";
        while(getline(newFile, tp)){
        cout << tp << "\n";
        array.push_back(tp);
        }
    }

    int horizontal = 0, vertical = 0; 

    for(int i=0; i<array.size();i++){
        int j=0;
        string direction = "", move = "";
        int move_amount = 0;
        bool order = false;
        while(j < array.at(i).length()){
            if(order == false)
                direction += array.at(i)[j];
            if(array.at(i)[j] == ' ') {
                j++;
                order = true;
            }
            if(order == true)
                move += array.at(i)[j];
            j++;
        }
        move_amount = stoi(move);
        cout << direction << ", " << move_amount << endl;

        if(direction == "forward ")
            horizontal += move_amount;
        if(direction == "down ")
            vertical += move_amount;
        if(direction == "up ")
            vertical -= move_amount;
        }

        cout << "Horizontal: " << horizontal << ", Vertical: " << vertical << endl;
        return 0;
    }

