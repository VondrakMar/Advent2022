#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int transform(char symb)
{
    int nsymb;
    if (symb == 'X' || symb == 'A' )
    {      
        nsymb = 1;
    }
    else if (symb == 'Y' || symb == 'B')
    {
        nsymb = 2;
    }
    else if (symb == 'Z' || symb == 'C' )
    {
        nsymb = 3;
    }
    return nsymb;
}
int score(char op, char me)
{
    int nop = transform(op);
    int nme = transform(me);
    if (nop == nme)
    {
        return 3 + nme;
    }
    else if (nop == 1 && nme == 3){
        return nme;
    }
    else if (nop == 3 && nme == 2){
        return nme;
    }
    else if (nop == 2 && nme == 1){
        return nme;
    }
    else return 6 + nme;
}

char secondJob(char op, char me)
{
    int whatToUse;
    int nop = transform(op);
    int nme;
    int points;
    if (me == 'X'){
        nme = nop - 1 ;
        points = 0;
    }
    else if (me == 'Y'){
        nme = nop ;
        points = 3;

    }
    else if (me == 'Z'){
        nme = nop + 1;
        points = 6;
    }
    if (nme == 4) nme = 1;
    if (nme == 0) nme = 3;
    cout << "sec Job: " << nme << " " << points << endl;
    return nme + points;
}

int main(){
    ifstream myFile;
    string line;
    int scorePoints = 0;
    int scorePoints2 = 0;
    int res;
    int secJob;
    myFile.open ("input");
    while ( getline (myFile,line))
    {
        res = score(line[0],line[2]);
        secJob = secondJob(line[0],line[2]);
        // cout << res << endl;
        cout << secJob << endl;
        scorePoints += res;
        scorePoints2 += secJob;
        cout << scorePoints2 << endl;
        // cout << line[2] << "\n";
    }
    cout << "First answer:\n";
    cout << scorePoints << "\n";
    cout << "Second answer:\n";
    cout << scorePoints2 << "\n";
    myFile.close();
    return 0;
}