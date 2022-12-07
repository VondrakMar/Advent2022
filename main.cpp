#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){
    ifstream myFile;
    string line;
    myFile.open ("input");
    while ( getline (myFile,line))
    {
        cout << line << endl;
        // cout << line[2] << "\n";
    }
    cout << "First answer:\n";
    cout << "" << "\n";
    cout << "Second answer:\n";
    cout << "" << "\n";
    myFile.close();
    return 0;
}