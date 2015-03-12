#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <windows.h>
#include <winbase.h>



using namespace std;


int main()
{

ifstream fin;
    string saveLocation = "charbits.txt";
    int i=0;
    int k;
    int size = 0;
    int c[71];
    int z=0;
    int q=0;
    int y=0; //i is an all purpose counter variable, k is used for tracking solutions, size prevents overflow, c stores solutions, z and y do something
    char a[2028], b[28];
    for(y=0; y<=70; y++)
    {
        c[y] = 0;
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

LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
LARGE_INTEGER Frequency;

QueryPerformanceFrequency(&Frequency);
QueryPerformanceCounter(&StartingTime);

// Activity to be timed

for (i =0; i<=27; i++) //Defines the search key by taking the first 28 digits into a separate array.
        {
            b[i] = a[i];
        }
        k = 28; //Defines the start position for the search, beginning one digit after the search key.
        while (k<=2000) //New results will not appear after position 2000, as 28 digits are required for a complete sequence.
        {
            for(i=0; i<=27; i++) //The data and key arrays are incremented and compared. If the data matches the key, the next key digit is checked, and so on until a match is confirmed.
                                //Otherwise, the data array is implemented, the key array is put back to the beginning, and the search continues
            {
                if(b[i] != a[k+i])
                {
                    i=28;
                    k++;
                }
                else if(i==27) //When a match is found, it is added to a third array, and the data array is positioned at the end of the match, and the search continues.
                {
                    c[z] = k;
                    z++;
                    k = k + 28;
                }
            }
        }


    while(c[q]!=0) //The C array is checked element by element, and while the contents are not 0, the contents are output. These contents are the array positions for matches.
    {
        cout << "Pattern found at position: " << c[q];
        cout << endl;
        q++;
    }

QueryPerformanceCounter(&EndingTime);
ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;


//
// We now have the elapsed number of ticks, along with the
// number of ticks-per-second. We use these values
// to convert to the number of elapsed microseconds.
// To guard against loss-of-precision, we convert
// to microseconds *before* dividing by ticks-per-second.
//

ElapsedMicroseconds.QuadPart *= 1000000;
ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;




cout << ElapsedMicroseconds.QuadPart << endl;


    return 0;
}
