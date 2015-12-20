/*
ID: Rainow
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

ifstream in("checker.in");
ofstream out("checker.out");

int row[14];
bool a[14] , b[27] , c[27];
int N,cnt=0;

void queen_all(int k)
{
    int i,j;

    for(i=1;i<N+1;++i)
    {
        if(a[i] && b[k+i-1] && c[N+i-k])
        {
            row[k] = i;
            a[i] = b[k+i-1] = c[N+i-k] =false;
            if(k==N)
            {
                if(cnt<3)
                {
                    for(j=1;j<N;++j)
                        out<<row[j]<<' ';
                    out<<row[j]<<endl;
                }

                ++cnt;
            }
            else queen_all(k+1);

            a[i] = b[k+i-1] = c[N+i-k] = true;
        }
    }
}

int main()
{
    in>>N;
    if(N<6 || N>13) return 0;

    int i,j;

    for(i=0;i<=N;++i) a[i] = true;
    for(i=0;i<=N*2;++i) b[i] = c[i] = true;
    queen_all(1);

    out<<cnt<<endl;
    return 0;
}
