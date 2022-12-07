#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int lengOfCrates(string nameFile){
    ifstream myFile;
    int leng;
    int count = 0;
    string last, line;
    myFile.open (nameFile);
    while ( getline (myFile,line))
    {
        if (line == "")
        {
            break;
        }
        last = line;
    } 
    
    leng = last.length(); 
    for (int a = 0; a <= leng - 1;a++)
    {
        
        if (last[a] != ' ')
        {
            // cout << last[a] << " " << count << endl; 
            count++;
        } 
    }
    return count;
}

int main(){
    ifstream myFile;
    string line, name;
    int leng;
    name = "inputall";
    // myFile.open (name);
    leng = lengOfCrates(name);
    // cout << leng;
    
    while ( getline (myFile,line))
    {
        cout << line;    
        
    }
    cout << "First answer:\n";
    cout << "" << "\n";
    cout << "Second answer:\n";
    cout << "" << "\n";
    myFile.close();
    return 0;
}