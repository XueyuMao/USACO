/*
ID: Rainow
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("milk.in");
    ofstream out("milk.out");

    struct farmer
    {
        int P;
        int A;
    };
    int N, M;
    int payment = 0;
    int i , j;
    in>>N>>M;
    bool flag;
    farmer tmp;

    farmer getmilk[M];

    for(i=0;i<M;++i)
    {
        in>>getmilk[i].P>>getmilk[i].A;
    }

    for(i=1;i<M;++i)
    {
        flag = false ;
        for(j=0;j<M-i;++j)
            if(getmilk[j+1].P<getmilk[j].P)
            {
                tmp.A=getmilk[j].A;
                tmp.P=getmilk[j].P;
                getmilk[j].A=getmilk[j+1].A;
                getmilk[j].P=getmilk[j+1].P;
                getmilk[j+1].A=tmp.A;
                getmilk[j+1].P=tmp.P;
                flag = true;
            }
        if(!flag) break;
    }

    i=0;

    while(i<M)
    {
        if(N>getmilk[i].A)
        {
            payment += getmilk[i].A * getmilk[i].P;
            N = N - getmilk[i].A;
        }
        else
        {
            payment += N * getmilk[i].P;
            N = 0;
        }

        if(N==0) break;

        ++i;
    }

    out<<payment<<endl;

    in.close();
    out.close();

    return 0;
}
