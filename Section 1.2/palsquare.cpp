/*
ID: Rainow
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("palsquare.in");
    ofstream out("palsquare.out");

    int Base , n ,n1, n2 , i , cnt ,l ,l1,  m , cnt1;
    in>>Base;
    bool flag, equal , origin;
    char n2n[90000];
    char output[90000];
    char n1n[9000];
    char nn[9000];

    if( Base<2 || Base>20) return 0;
    for( n=1 ; n<=300 ; n++)
    {
        flag = false;
        origin = false;
        equal = true;

        cnt = 0;
        cnt1 = 0;
        l = 0;
        l1 = 0;
        n1 = n;
        n2 = n*n;
        while(flag != true)
        {
            if(n2%Base<10 )
                n2n[cnt] = n2%Base + '0';
            else n2n[cnt] = n2%Base -10 + 'A';

            ++l;

            n2 = n2/Base;

            if(n2==0)
                flag = true;

            ++cnt;
        }

        while(origin != true)
        {
            if(n1%Base<10 )
                n1n[cnt1] = n1%Base + '0';
            else n1n[cnt1] = n1%Base -10 + 'A';

            ++l1;

            n1 = n1/Base;

            if(n1==0)
                origin = true;

            ++cnt1;
        }

        for(i=0;i<l;i++)
        {
            output[i] = n2n[l-1-i];
        }

        for(i=0;i<l1;i++)
        {
            nn[i] = n1n[l1-1-i];
        }

        for(m=0;m<l;m++)
        {
            if(output[m] != n2n[m])
            {
                equal = false;
                break;
            }
        }

        if( equal == true )
            out<<nn<<" "<<output<<endl;
    }

    in.close();
    out.close();

    return 0;
}
