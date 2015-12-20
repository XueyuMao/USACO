/*
ID: Rainow
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("friday.in");
    ofstream out("friday.out");

    int N;
    in>>N;
    if(N<=0 || N>400) return 0;

    int thirtns[7]={0};

    int theDate = 13 , leap , i , j , year=1900 ;


    for(j=1; j<=N; j++)
    {
        if( ( year%4 == 0 && year%100 != 0 ) || year%400 ==0 ) leap = 1;
        else leap = 0;

        for(i = 1; i<=12 ; i++ )
        {
            thirtns[theDate%7]++;
            if(i==2)
            {
                if(leap == 0) theDate += 28;
                else theDate +=29;
            }
            else if(i==1 || i==3 || i==5 || i==7 || i==8 || i ==10 || i==12) theDate += 31;
            else theDate += 30;
        }
        year++;
        if(i==13) i=0;
    }

    out<<thirtns[6]<<" "<<thirtns[0]<<" ";
    for( i = 1; i<5 ; i++ )
    {
        out<<thirtns[i]<<" ";
    }
    out<<thirtns[5]<<endl;

    in.close();
    out.close();

    return 0;

}

