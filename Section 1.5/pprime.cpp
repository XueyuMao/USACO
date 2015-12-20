/*
ID: Rainow
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

bool isPrime(int a)
{
    int i;
    for(i=3;i*i<=a;i+=2)
    {
        if(a%i==0) return false;
    }
    return true;
}

int main()
{
    ifstream in("pprime.in");
    ofstream out("pprime.out");

    int a,b;
    in>>a>>b;
    int i , j , k, n=3;
    int d1,d2,d3,d4;
    int num[10000]={5,7,11};


    for(d1=1;d1<10;d1=d1+2)
    {
        for(d2=0;d2<10;++d2)
        {
            num[n] = d1*100 + d2*10 +d1;
            ++n;
        }
    }

    for(d1=1;d1<10;d1=d1+2)
    {
        for(d2=0;d2<10;++d2)
        {
            for(d3=0;d3<10;++d3)
            {
                num[n] = d1*10000 + d2*1000 + d3*100 + d2*10 + d1;
                ++n;
            }

        }
    }

    for(d1=1;d1<10;d1=d1+2)
    {
        for(d2=0;d2<10;++d2)
        {
            for(d3=0;d3<10;++d3)
            {
                for(d4=0;d4<10;++d4)
                {
                    num[n] = d1*1000000 + d2*100000 + d3*10000 + d4*1000 +d3*100 + d2*10 + d1;
                    ++n;
                }
            }
        }
    }

    if( a<5 || b>100000000 ) return 0;

    for(j=0;j<n && num[j]<a;++j);
    for(k=n-1;j>=0 && num[k]>b;--k);

    for(i=j;i<=k;++i)
    {
        if( isPrime(num[i]) )
        {
            out<<num[i]<<endl;
        }
    }

    return 0;
}
