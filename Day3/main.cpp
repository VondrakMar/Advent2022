#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string znaky = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int convertToInt(char a)
{
    int i;
    i = znaky.find(a);
    return i+1;
}

int main(){
    // this code is super bad, I was really tired and wanted to have it done... Sorry
    ifstream myFile;
    string line;
    myFile.open ("input");
    int leng;
    string first, second;
    int f;
    int count = 0;
    string res = "";
    bool found = false;
    string elves[3];
    int elcount =0;
    int countsecond = 0;
    while ( getline (myFile,line))
    {
        elves[elcount] = line;
        elcount += 1;
        if (elcount == 3){
            for (int a = 0; a < 53 ; a++){
                int a1 = elves[0].find(znaky[a]);
                int l1 = elves[0].length();
                int a2 = elves[1].find(znaky[a]);
                int l2 = elves[1].length();
                int a3 = elves[2].find(znaky[a]);
                int l3 = elves[2].length();
                if (a1 <= l1 && a1 >= 0 && a2 <= l2 && a2 >= 0 && a3 <= l3 && a3 >= 0)
                {
                    countsecond += convertToInt(znaky[a]);    
                }
            }
            elcount = 0 ;
            }

        found = false;
        res = "";
        leng = line.length();
        first = line.substr(0,leng/2);
        second = line.substr(leng/2,leng);
        for (int a=0 ; a <= leng/2; a++)
        {
            f = second.find(first[a]);
            if (f < leng && f >= 0){
                if (first[a] == second[f])
                {
                    res = second[f];
                    found = true;
                }
            }
        }
        if (found == true) {
            count = count + convertToInt(res[0]);
            }
        
    }
    cout << "First answer:\n";
    cout << count << "\n";
    cout << "Second answer:\n";
    cout << countsecond << "\n";
    myFile.close();
    return 0;
}