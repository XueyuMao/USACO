/*
ID: Rainow
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

bool check(int N, char **square, char **after)
{
    int i , j;
    for( i=0; i < N ;i++)
    {
        for( j=0 ; j<N ; j++)
        {
            if(square[i][j] != after[i][j])
                return false;
        }
    }
    return true;
}

void change1(int N , char **square ,char **&tmp)
{
    int i , j;
    for( i=0; i < N ;i++)
    {
        for( j=0 ; j<N ; j++)
            tmp[i][j] = square[N-1-j][i];
    }
}

void change2(int N , char **square ,char **&tmp)
{
    int i , j;
    for( i=0; i < N ;i++)
    {
        for( j=0 ; j<N ; j++)
            tmp[i][j] = square[N-1-i][N-1-j];
    }
}

void change3(int N , char **square ,char **&tmp)
{
    int i , j;
    for( i=0; i < N ;i++)
    {
        for( j=0 ; j<N ; j++)
            tmp[i][j] = square[j][N-1-i];
    }
}

void change4(int N , char **square ,char **&tmp)
{
    int i , j;
    for( i=0; i < N ;i++)
    {
        for( j=0 ; j<N ; j++)
            tmp[i][j] = square[i][N-1-j];
    }
}

int main()
{
    ifstream in("transform.in");
    ofstream out("transform.out");

    int N , i , j;
    bool flag = false;
    char **square, **after , **tmp , **tmp1;
    in>>N;

	square = new char*[N];
    for(i=0;i<N;i++)
        square[i] = new char[N];
	after = new char*[N];
    for(i=0;i<N;i++)
        after[i] = new char[N];
    tmp = new char*[N];
    for(i=0;i<N;i++)
        tmp[i] = new char[N];
    tmp1 = new char*[N];
    for(i=0;i<N;i++)
        tmp1[i] = new char[N];


    for( i=0; i < N ;i++)
    {
        for( j=0 ; j<N ; j++)
            in>>square[i][j];
    }
    for( i=0; i < N ;i++)
    {
        for( j=0 ; j<N ; j++)
            in>>after[i][j];
    }


///////////////////////////////////////////////////
    change1(N,square,tmp);
    flag = check(N,after,tmp);
    if(flag==true)
    {
        out<<'1'<<endl;
        return 0;
    }
///////////////////////////////////////////////////
    change2(N,square,tmp);
    flag = check(N,after,tmp);
    if(flag==true)
    {
        out<<'2'<<endl;
        return 0;
    }
///////////////////////////////////////////////////
    change3(N,square,tmp);
    flag = check(N,after,tmp);
    if(flag==true)
    {
        out<<'3'<<endl;
        return 0;
    }
///////////////////////////////////////////////////
    change4(N,square,tmp);
    flag = check(N,after,tmp);
    if(flag==true)
    {
        out<<'4'<<endl;
        return 0;
    }
///////////////////////////////////////////////////
    change4(N,square,tmp1);
    change1(N,tmp1,tmp);
    flag = check(N,after,tmp);
    if(flag==true)
    {
        out<<'5'<<endl;
        return 0;
    }

    change4(N,square,tmp1);
    change2(N,tmp1,tmp);
    flag = check(N,after,tmp);
    if(flag==true)
    {
        out<<'5'<<endl;
        return 0;
    }

    change4(N,square,tmp1);
    change3(N,tmp1,tmp);
    flag = check(N,after,tmp);
    if(flag==true)
    {
        out<<'5'<<endl;
        return 0;
    }
///////////////////////////////////////////////////
    flag = check(N,square,after);
    if(flag==true)
    {
        out<<'6'<<endl;
        return 0;
    }
    else
    {
        out<<'7'<<endl;
        return 0;
    }
    return 0;
}
