#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdint.h>


//program startup


using namespace std;

int main()
{
    ;
    ifstream fin;
    string saveLocation = "charbits.txt";
    int size = 0;
    char a[2028];

    fin.open(saveLocation.c_str());
    if(!fin)
    {
        cout << "Failure trying to read file: ";
        cout << saveLocation.c_str() << endl;
        system("PAUSE");
        exit(0);
    }
    fin.ignore(0); //ignores the first endl
    while(!fin.eof())
    {
        fin >> a[size];
        size++;
    }
    fin.close();
    cout << a;
}
