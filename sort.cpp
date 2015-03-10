#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    clock_t t1, t2;

    ifstream fin;
    string saveLocation = "marbles.txt";
    int size = 0;
    char a[1999];

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

    int temp1=0;
    int temp2=0;

    t1 = clock();

    for(long int i=1; i<=1000000; i++)
    {
        if(a[temp1]=='R')
        {
            temp1++;
        }

        if(a[temp2]=='R')
        {
            temp2=temp1;
        }

        while(temp1!=1999)
        {
            if(a[temp1]=='R')
            {
                swap(a[temp1],a[temp2]);
                temp2++;
                temp1++;
            }
            else
            {
                temp1++;
            }
        }

        temp1=0;
        temp2=0;

        while((a[temp2]=='R')||(a[temp2]=='W'))
        {
            temp2++;
        }

        while((a[temp1]=='R')||(a[temp1]=='W'))
        {
            temp1=temp2;
        }

        while(temp1!=1999)
        {
            if(a[temp1]=='W')
            {
                swap(a[temp1],a[temp2]);
                temp2++;
                temp1++;
            }
            else
            {
                temp1++;
            }
        }
    }

    cout << a;
    cout << '\b' << '\b';

    t2 = clock();

    cout << "Time difference is " << (t2-t1)/CLK_TCK << " microseconds.";

    return 0;
}
