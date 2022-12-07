#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){
    ifstream myFile;
    string line, seg,first,second;
    int fb,fe,sb,se,fl,sl;
    int leng, brk;
    int countfirst = 0;
    int countsec = 0;
    myFile.open ("input");
    while ( getline (myFile,line))
    {
        leng = line.length();

        for (int a = 0; a <= leng; a++)
        {
            if (line[a] == ',')
            { 
                brk = a;
                break;
            }
        
        }       
        first = line.substr(0,brk );
        second = line.substr(brk + 1,leng);
        // cout << "line: " << line << "first: " << first <<"second: " << second << endl;
        fl = first.length();

        for (int a = 0; a <= fl; a++)
        {
            if (first[a] == '-')
            { 
                brk = a;
                break;
            }
        }
        fb = stoi(first.substr(0,brk ));
        fe = stoi(first.substr(brk + 1,fl));
        
        sl = first.length();

        for (int a = 0; a <= sl; a++)
        {
            if (second[a] == '-')
            { 
                brk = a;
                break;
            }
        }
        sb = stoi(second.substr(0,brk ));
        se = stoi(second.substr(brk + 1,sl));
        if (fb <= sb && fe >= se){
            // cout << first << " " << second << endl;
            countfirst += 1;
        }  
        else if (fb >= sb && fe <= se){
            // cout << first << " " << second << endl;
            countfirst += 1;
        }
        if (fb <= sb && fe >= sb)
       {
            countsec += 1;
       } 
       else if (sb <= fb && se >= fb)
       {
            countsec += 1;
       }

    }
    cout << "First answer:\n";
    cout << countfirst << "\n";
    cout << "Second answer:\n";
    cout << countsec << "\n";
    myFile.close();
    return 0;
}