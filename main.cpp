#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    char znak;
    string wynik;
    ifstream plik;
    plik.open("plyk.txt");
    enum STATES {mInside, Inside, mOutside, Outside, mmOutside } state = Outside;
    while(plik.good())
    {
        znak = plik.get();

        switch(state)
        {
        case Outside:
        if (znak == '/') state = mInside;
        else state = Outside;
        break;

        case mInside:
        if (znak == '*') state = Inside;
        else state = Outside; break;

        case Inside:
        if (znak == '*') state = mOutside;
        else state = Inside;
        break;

        case mOutside:
        if (znak == '/') state = mmOutside;
        else state = Inside; break;

        case mmOutside:
        state = Outside; break;

        }
    if(state == Outside) wynik += znak;
    }

    cout << wynik << endl;
    plik.close();
    return 0;
}
