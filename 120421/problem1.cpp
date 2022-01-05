#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <bitset>
#include <sstream>
using namespace std;

int CalculateFinalScore(vector<int>numbers, int winningNum, vector<vector<int>> boards){
    int total = 0;
    // for(int i=0;i<numbers.size();i++){
    //     total += numbers.at(i);
    // }
    // total *= winningNum;


    cout << numbers.size() << endl;
    vector<int> unmarked;
    vector<vector<int>> board = boards;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){ 
            bool notInList = true;
            for(int p=0;p<numbers.size();p++){                
                if(board.at(i)[j] == numbers.at(p)){
                    notInList = false;
                }
            }
            if(notInList) {
                cout << board.at(i)[j] << " == " << endl;
                unmarked.push_back(board.at(i)[j]);
                notInList = true;
            }
        }
        cout << endl;
    }

    for(int i=0;i<unmarked.size();i++){
        total += unmarked.at(i);
    }
    
    total *= winningNum;
    return total;
}

bool CheckIfArrayMatches(vector<int> numbers, vector<int> boardList, vector<vector<int>> board){
    bool allMatch = false;
    int count = 0;
    int winningNum = 0;

    for(int i=0;i<numbers.size();i++){
        for(int j=0;j<boardList.size();j++){
            bool match = false;
            //cout << numbers.at(i) << " = " << boardList.at(j) << endl;
            if(numbers.at(i) == boardList.at(j)) {
                match = true;
                count++;

                if(count == 5)
                    winningNum = numbers.at(i);
            }
            if(match)
                break;
        }       
    }
    if(count == 5)
        allMatch = true;
    if(allMatch) {
        cout << "Winning Board" << endl;
        for(int i=0;i<5;i++){
            cout << boardList.at(i) << endl;
        }
        cout << "Final Score: " << CalculateFinalScore(numbers, winningNum, board);
        //exit(0);
    }
    return allMatch;
}


bool CheckHorizontal(vector<vector<int>> board, vector<int> numbers) {
    bool row = false;
    int j=0,i;

    for(i=0;i<board.size();i++) {
        vector<int> rowList;
        //cout << "###########" << endl;
        while(j<5) {
            //cout << board.at(i)[j] << endl;
            rowList.push_back(board.at(i)[j]);
            j++;
        }
        CheckIfArrayMatches(numbers, rowList, board);
        j=0;
    }
    return row;
}

bool CheckVertical(vector<vector<int>> board, vector<int> numbers) {
    bool col = false;
    int j=0,i;
    for(i=0;i<board.size();i++){
        vector<int> colList;
        //cout << "###########" << endl;
        while(j<5) {
            //cout << board.at(j)[0] << endl;
            colList.push_back(board.at(j)[i]);
            j++;
        }
        CheckIfArrayMatches(numbers, colList, board);
        j=0;
    }
    return col;
}


vector<int> getListFromString(string values, char separator = ','){
    string temp;
    vector<int> array;
    for(int i=0;i<values.length();i++){
        //cout << "value[i]: " << values[i] << " | temp: " << temp << endl;
        if(values[i] == separator) {
            i++;
            array.push_back(stoi(temp));
            temp = "";
        }
        if(values[i] != separator) 
            temp += values[i];
        if(values.length()-1 == i && values[i-1] == separator)
            array.push_back(stoi(temp)); 
    }
    return array;
}

void printBoards(vector<vector<int>> board) {
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            //cout << board.at(i)[j] << " ";
        }
        //cout << endl;
    }
    //out << "**********" << endl;
}

int main(int argc, char* argv[]) {
    vector<string> array;
    fstream newFile;
    newFile.open("test.txt",ios::in);
    if(newFile.is_open()){
        string tp = "";
        while(getline(newFile, tp)){
        //cout << tp << "\n";
        array.push_back(tp);
        }
    }

    vector<int> numbers = getListFromString(array.at(0), ',');
    for(int i=0;i<numbers.size();i++){
        //cout << numbers.at(i) << endl;
    } 

    // for(int i=1;i<array.size();i++){
    //     cout << array.at(i) << endl;
    // }
    vector<string> temp;
    for(int i=1;i<array.size();i++){
        temp.push_back(array.at(i));
        //cout << temp.at(i) << endl;
    }
    //string test = "test sesf fesfe fesfe";
    vector<vector<vector<int>>> boards;
    vector<vector<int>> board;
    //vector<int> test;

    for(int i=1,row=1;i<temp.size();i++){ //row
        vector<int> row_nums;

        //cout << temp.at(i) << endl;
        //vector<int> list = getListFromString(temp.at(i), ' ');
        stringstream s_stream(temp.at(i));
        while(s_stream.good()) {
            string substr;
            getline(s_stream, substr, ' ');
            
            if(substr != " ") {
                if(substr.size() != 0) {
                    //cout <<':' << substr << ':' << substr.size() << endl;
                    //test.push_back(stoi(substr));
                    row_nums.push_back(stoi(substr));
                }
            }                
        }
        if(row_nums.size() != 0)
            board.push_back(row_nums);
        
        //cout << board.size() << endl;

        if(board.size() % 5 == 0) {
            if(board.size() != 0)
                boards.push_back(board); 
            //row = 1;
            vector<vector<int>> swap;
            board = swap;
        } else {
            //cout << "**********" << endl;
        }row++;

    }

    //cout << boards.size() << endl;

    //cout << boards.at(0).size() << endl;


    printBoards(boards.at(0));
    printBoards(boards.at(1));
    printBoards(boards.at(2));

    int pointer = 1;
    vector<int> tempList;
    tempList.push_back(numbers.at(0));

    
    while(pointer < numbers.size())
    {
        tempList.push_back(numbers.at(pointer));
        for(int i=0;i<pointer;i++){
            for(int j=0;j<boards.size();j++){
                CheckHorizontal(boards.at(j), tempList);
                    //cout << j << endl;
                CheckVertical(boards.at(j), tempList);
                    //cout << j << endl;
            }
        }
        pointer++;
        cout << "__________" << pointer << "_________" << endl;
    }

    return 0;
}