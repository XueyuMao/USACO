/*
ID: Rainow
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("numtri.in");
    ofstream out("numtri.out");

    int n ;
    in>>n;
    int num[n][n];
    int i , j;

    for(i=0;i<n;++i)
    {
        for(j=0;j<=i;++j)
        {
            in>>num[i][j];
        }
    }

    for(i=n-2;i>=0;--i)
    {
        for(j=0;j<=i;++j)
        {
            if(num[i+1][j]>=num[i+1][j+1])
                num[i][j] += num[i+1][j];
            else
                num[i][j] += num[i+1][j+1];
        }
        cout<<endl;
    }

    out<<num[0][0]<<endl;


    return 0;
}
