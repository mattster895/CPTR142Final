#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdint.h>


//program startup


using namespace std;

int main()
{
    ifstream fin;
    string saveLocation = "charbits.txt";
    int i=0, k, size = 0, c[71], z=0, y=0;
    char a[2028], b[28];
    for(y=0; y<=70; y++)
    {
        c[y] = 0;
    }
    fin.open(saveLocation.c_str());
    if(!fin)
    {
        cout << "Failure trying to read file: ";
        cout << saveLocation.c_str() << endl;
        system("PAUSE");
        exit(0);
    }
    while(!fin.eof())
    {
        fin >> a[size];
        size++;
    }
    fin.close();
    for (i =0; i<=27; i++)
    {

        b[i] = a[i];
    }
    k = i;
    while (k<= 1971)
    {
       for(i=0; i<=27; i++)
       {
           if(b[i] != a[k+i])
           {
               i=28;
               k++;
           }
            else if(i==27)
            {
                c[z] = k;
                z++;
                k = k + 28;
            }
       }
    }
       for(i=0; i<= 70; i++)
       {
         if(c[i] == 0)
        {
           i==71;
        }
         else
        {
           cout << "Pattern found at position: " << c[i] << endl;
        }
       }
}
