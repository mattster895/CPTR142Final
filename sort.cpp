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
	uint64_t t1, t2;
	double time;

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

    t1 = rdtsc();

    for(int i=1; i<=1000000; i++)

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

    t2 = rdtsc();
    time = (t2-t1)/1000000;

    cout << a;
    cout << '\b' << '\b';

    cout << "Time difference is " << time << " microseconds.";

    return 0;
}
