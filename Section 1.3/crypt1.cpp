/*
ID: Rainow
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("crypt1.in");
    ofstream out("crypt1.out");

    int N;
    int i , j,m,n,h;
    int a,b,c,d,e;
    int multi1,multi2;
    int cnt=0;
    int ans;
    int sta3,sta4;
    bool flag[10]={false};

    in>>N;
    int num[N];

    for(i=0;i<N;++i)
    {
        in>>num[i];
        flag[num[i]]=true;
    }

    for(i=0;i<N;++i)
    {
        a=num[i];
        for(j=0;j<N;++j)
        {
            d=num[j];
            for(m=0;m<N;++m)
            {
                e=num[m];
                if(a*d>=10 || a*e>=10) continue;
                for(n=0;n<N;++n)
                {
                    b=num[n];
                    for(h=0;h<N;++h)
                    {
                        c = num[h];

                        multi1 = a*100 + b*10 + c;
                        multi2 = d*10 + e;
                        sta3 = d*multi1;
                        sta4 = e*multi1;
                        ans = multi1*multi2;

                        if(!(sta3<1000 && sta3>110 && sta4<1000 &&sta4>110 && ans<10000 && ans>1110))
                            continue;
                        if(!(flag[sta3/100] && flag[(sta3-(sta3/100)*100)/10] && flag[sta3-(sta3/10)*10]))
                            continue;
                        if(!(flag[sta4/100] && flag[(sta4-(sta4/100)*100)/10] && flag[sta4-(sta4/10)*10]))
                            continue;
                        if(!(flag[ans/1000] && flag[(ans-(ans/1000)*1000)/100] && flag[(ans-(ans/100)*100)/10] &&flag[ans-(ans/10)*10]))
                            continue;

                        ++cnt;
                    }
                }
            }
        }
    }

    out<<cnt<<endl;

    return 0;
}
