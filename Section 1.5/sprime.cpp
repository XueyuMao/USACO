/*
ID: Rainow
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>


using namespace std;

bool isPrime(int a)
{
    int i;
    for(i=3;i*i<=a;i=i+2)
    {
        if(a%i==0) return false;
    }
    return true;
}

int main()
{
    ifstream in("sprime.in");
    ofstream out("sprime.out");

    int N;
    in>>N;

    int i , j , k;

    if( N<1 || N>8 ) return 0;

    int g[8][1000] ;
    int size[8]={0};
    int tmp;

    g[0][0]=2;
    g[0][1]=3;
    g[0][2]=5;
    g[0][3]=7;
    size[0]=4;

    for(i=1;i<8;++i)
    {
        for(k=0;k<size[i-1];++k)
        {
            for(j=1;j<10;j=j+2)
            {
                tmp = g[i-1][k] * 10+ j;
                if(isPrime(tmp))
                {
                    g[i][size[i]]=tmp;
                    ++size[i];
                }
            }
        }
    }

    for(i=0;i<size[N-1];++i)
        out<<g[N-1][i]<<endl;

    return 0;
}
