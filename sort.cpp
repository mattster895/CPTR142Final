//////////////////////////////////////////////////////
//                                                  //
//                     CPTR142                      //
//                     Group 4                      //
//                  Sort Function                   //
//                                                  //
//                     Credits:                     //
//                                                  //
//            Algorithm - Craig, Quillan            //
//         Optimization - Craig, Quillan, Mathew    //
//              Bug Fix - Whole Group               //
//                                                  //
//////////////////////////////////////////////////////


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    //input and initializations start

    clock_t t1,t2,t3,t4;
    int time1 = 0;
    int time2 = 0;
    int time3 = 0;

    ifstream fin;
    string saveLocation = "marbles.txt";
    int size = 0;
    char a[1999];
    char b[1999];

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

    for(int z=0;z<=1999;z++)    //creates a second array, b, that is the unsorted version of a
    {
        b[z] = a[z];
    }

    int temp1=0;
    int temp2=0;

    //input and initializations end

    t1 = clock();

    //sorting start

    for(long int i=1;i<=1000000;i++)
    {
        for(int z=0;z<=1999;z++)
        {
            a[z] = b[z];
        }

        temp1=0;
        temp2=0;

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

    //sorting end

    t2 = clock();

    for(int z=0;z<=1999;z++)    //easy for arrays to get junk in them,
    {                           //this just outputs the first 2000 characters
        cout << a[z];
    }

    t3 = clock();

    for(long int i=1;i<=1000000;i++)
    {
        for(int z=0;z<=1999;z++)
        {
            a[z] = b[z];
        }
    }

    t4 = clock();
    time2 = time2 + (double)(t4-t3);

    time1 = (t2-t1)/CLK_TCK;
    time2 = time2/CLK_TCK;
    time3 = time1 - time2;

    cout << "\n  Total time: " << time1 << " microseconds.";
    cout << "\n  Reset time: " << time2 << " microseconds.";
    cout << "\n Actual time: " << time3 << " microseconds.";
    cout << endl;

    return 0;
}
