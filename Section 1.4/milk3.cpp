/*
ID: Rainow
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

bool found[21][21][21];
int size[4],x,y;

void pour(int k)
{
    if(x+y>=size[k])
    {
        x -= size[k]-y;
        y = size[k];
    }
    else
    {
        y += x;
        x = 0;
    }
}

void dfs(int a, int b, int c)
{
    if(found[a][b][c]) return;
    found[a][b][c] = true;

    x=a;y=b;
    pour(2); dfs(x,y,c);

    x=a;y=c;
    pour(3); dfs(x,b,y);

    x=b;y=c;
    pour(3); dfs(a,x,y);

    x=c;y=a;
    pour(1); dfs(y,b,x);

    x=c;y=b;
    pour(2); dfs(a,y,x);

    x=b;y=a;
    pour(1); dfs(y,x,c);

}

int main()
{
    ifstream in("milk3.in");
    ofstream out("milk3.out");

    int i,j,k;
    bool flag = true;

    size[0] = 0;
    in>>size[1]>>size[2]>>size[3];

    for(i=0;i<21;++i)
        for(j=0;j<21;++j)
            for(k=0;k<21;++k)
                found[i][j][k] =false;

    dfs(0,0,size[3]);

    for(i=0;i<=size[3];++i)
    {
        for(j=0;j<=size[2];++j)
        {
            if(found[0][j][i])
            {
                if(flag)
                {
                    out<<i;
                    flag = false;
                }
                else
                    out<<' '<<i;
            }

        }
    }
    out<<endl;

    return 0;
}
