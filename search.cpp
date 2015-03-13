//////////////////////////////////////////////////////
//                                                  //
//                     CPTR142                      //
//                     Group 4                      //
//                  Search Function                 //
//                                                  //
//                     Credits:                     //
//                                                  //
//            Algorithm - Matt, Andrew, Justin      //
//         Optimization - Whole Group               //
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

//Input and Initializations Start

clock_t t1, t2;

ifstream fin;
string saveLocation = "charbits.txt"; //The file name used to read in data

int i=0; //I is a counter variable used in various situations
int k; //K likewise, is a counter variable used in various situations
int z=0; //Z likewise, is a counter variable used in various situations
int q=0;// Q likewise, is a counter variable used in various situations
int y=0;//Y likewise, is a counter variable used in various situations
int size = 0; //Size is a counter variable used during file in

char a[2028] //A is the array holding the charbits data
int b[28]; //B is an array holding the search key
int c[71]; //C is an array holding the start positions of matches

    for(y=0; y<=70; y++) //Sets the C array to zero for error checking in the end
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


// Activity to be timed

t1=clock();

for (int w=0; w<=1000000; w++)
{
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

}

    //Finds the first instance of a repeated start position, and stores this as variable end
    int end=1;
    while(c[end]!=c[0])
    {
        end++;
    }

    end = end-1;

    //Outputs from C position 0 to the end variable, printing no repeats
    for(i=0; i<=end; i++)
    {
        cout << "Pattern found at position: " << c[i];
        cout << endl;
    }

t2=clock();

//End clock and print time used

cout << "Time difference is " << (t2-t1)/CLK_TCK << " microseconds." << endl;

    return 0;
}
