#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdint.h>

using namespace std;

extern "C"
{
	__inline__ uint64_t rdtsc()
	{
		uint32_t lo, hi;
		/* We cannot use "=A", since this would use %rax on x86_64 */
		__asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));

		return (uint64_t)hi << 32 | lo;
	}
}

int main()
{
    uint64_t t0, t1, delta;
    t0 = rdtsc();

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
    char holder;

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
            holder = a[temp2];
            a[temp2] = 'R';
            a[temp1] = holder;
            temp2++;
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
            holder = a[temp2];
            a[temp2] = 'W';
            a[temp1] = holder;
            temp2++;
        }
        else
        {
            temp1++;
        }
    }

    cout << a;
    cout << '\b' << '\b';

    t1 = rdtsc();
    delta = t1-t0;
    cout << "Clock Cycles: " << delta;

    return 0;
}
