#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>


//program startup


using namespace std;

int main()
{
    clock_t t1, t2;
    ifstream fin;
    string saveLocation = "charbits.txt";
    int i=0, k, size = 0, c[71], d[71] z=0, y=0; //i is an all purpose counter variable, k is used for tracking solutions, size prevents overflow, c stores solutions, z and y do something
    char a[2028], b[28];
    for(y=0; y<=70; y++)
    {
        c[y] = 0;
    }
    for(y=0; y<=70; y++)
    {
        d[y] = 0;
    }
    fin.open(saveLocation.c_str()); //opens the file and displays an error message if unable to do so
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
    t1=clock();
    for(long int q=1; q<=1000000; q++)
    {
    for (i =0; i<=27; i++)
    {

        b[i] = a[i];
    }
    k = 27;
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
    }
    for(i=0; i<= 70; i++)
       {
        if(c[i] == 0)
       {
           i==71;
       }
       else
       {
           cout << "\n Pattern found at position: " << c[i]+1;
       }
       }
    t2=clock();
    cout << "\nTime difference is " << (t2-t1)/CLK_TCK << " milliseconds.";
    return 0;
}
