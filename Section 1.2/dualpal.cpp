/*
ID: Rainow
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("dualpal.in");
    ofstream out("dualpal.out");

    int N , S;
    int Base , n , n2 , i , cnt ,l ,  m ;
    int dual=0;
    int moreN=0;
    in>>N>>S;
    bool flag, equal;
    char n2n[90000];
    char output[90000];


    n = S+1;


    if( N<1 || N>15) return 0;

    while( true )
    {
        for(Base=10;Base>=2;--Base)
        {
            flag = false;
            equal = true;

            cnt = 0;

            l = 0;

            n2 = n;
            while(flag != true)
            {
                n2n[cnt] = n2%Base + '0';

                ++l;

                n2 = n2/Base;

                if(n2==0)
                    flag = true;

                ++cnt;
            }

            for(i=0;i<l;i++)
            {
                output[i] = n2n[l-1-i];
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
                ++dual;

            if(dual==2)
            {
                out<<n<<endl;
                ++moreN;
                break;
            }
        }

        if(moreN==N)
            break;

        ++n;
        dual = 0;
    }

    in.close();
    out.close();

    return 0;
}
