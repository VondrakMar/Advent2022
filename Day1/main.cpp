#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream myFile;
    string line;
    int biggest = 0;
    int biggest2 = 0;
    int biggest3 = 0;
    int current = 0;
    int addition;
    myFile.open ("input");
    
    while ( getline (myFile,line))
    {
        if (line == "")
        {
            if (biggest < current)
            {
                biggest3 = biggest2;
                biggest2 = biggest;
                biggest = current;
            }
            else if (biggest2 < current)
            {
                biggest3 = biggest2;
                biggest2 = current;
            }
            else if (biggest3 < current)
            {
                biggest3 = current;
            }
            
            
            current = 0;
            
        }
        else
        {  
            addition = stoi(line);
            current += addition;
        }
    }
    cout << "First answer:\n";
    cout << biggest << "\n";
    cout << "Second answer:\n";
    cout << biggest+biggest2+biggest3 << "\n";
    myFile.close();
    return 0;
}