#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int main()
{

	clock_t t1, t2, t3, t4;
	double time=0;
	double stopwatch=0;
	double finaltime=0;

    ifstream fin;
    string saveLocation = "marbles.txt";
    int size = 0;
    char a[2000];

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
//cout << "Clock initialized" << endl;

for(int i=1; i<=100000; i++)
{
  {
    t3=clock();
    //cout << "Stopwatch Initialized" << endl;
    for(int t=0; t<=1999; t++)
    {
        a[t]=0;
    }
    //cout << "Array Reset" << endl;
    cout << a;
    size =0;

    fin.open(saveLocation.c_str());
    //cout << "File Opened" << endl;
    while(!fin.eof())
    {
        fin >> a[size];
        size++;
    }
    //cout << "Array Set" << endl;
    fin.close();
    //cout << a;
    //cout << "File Closed" << endl;
     temp1=0;
     temp2=0;

    t4=clock();
    stopwatch = stopwatch + ((t4-t3));
    //cout << "Stopwatch Stopped with " << stopwatch*1000000 << " microseconds." << endl;

  }

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
    //cout << "Reds Sorted" << endl;
    //cout << a;
    //cout << endl;
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

    t2 = clock();
    time = (t2-t1)/CLK_TCK;
    stopwatch = stopwatch/CLK_TCK;
    finaltime = time - stopwatch;

    for (int y=0; y<=1999; y++)
        cout << a[y];
    //cout << '\b' << '\b';

cout << "Total time used is " << time << endl;
cout << "Outside of loop reset time is " << stopwatch << endl;
cout << "Actual sorting time is " << finaltime << endl;

    return 0;
}
