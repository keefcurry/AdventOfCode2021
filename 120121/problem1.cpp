#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

  vector<int> array;
  fstream newFile;
  newFile.open("input1.txt",ios::in);
  if(newFile.is_open()){
    string tp = "";
    while(getline(newFile, tp)){
      cout << tp << "\n";
      array.push_back(stoi(tp));
    }
  }

  int count = 0, curr = 0, prev = 0;
  printf("argc = %d\n", argc);

  for(int i=0; i<array.size(); i++){
    if(curr != 0) // this is just for the first set of numbers
      prev = curr;
    curr = array.at(i);
    if(prev != 0 && curr > prev){
      cout << "curr, prev" << curr << "," << prev << endl;
      count++;
    }
    //cout << argv[i] << endl;
  }
  cout << count << endl;

  return count;
}