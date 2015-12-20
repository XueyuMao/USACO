/*
ID: Rainow
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("milk2.in");
    ofstream out("milk2.out");

    int N, min=1000000 , max=0, i, j ;
    int *b , *e;
    int milk=0 , idle=0 , milkl=0 , idlel=0;
    bool *flag;

    in>>N;
    b = new int[N];
    e = new int[N];

    for(i=0; i<N ; ++i)
    {
        in>>b[i]>>e[i];
        if(b[i]<min) min = b[i];
        if(e[i]>max) max = e[i];
    }

    flag = new bool[max-min];

    for(i=0 ; i<max-min ; i++)
    {
        flag[i] = false;
    }

    for(i=0 ; i<N ; i++)
    {
        for(j=b[i]-min;j<e[i]-min;j++)
        {
            flag[j] = true;
        }
    }

    for(i=min;i<max;i++)
    {
        if(flag[i-min] == true) milkl++;
        else
        {
            if(milkl>milk) milk = milkl;
            milkl = 0;
        }
    }

    if(milkl>milk) milk = milkl;

    for(i=min;i<max;i++)
    {
        if(flag[i-min] == false) idlel++;
        else
        {
            if(idlel>idle) idle = idlel;
            idlel = 0;
        }
    }

    out<<milk<<" "<<idle<<endl;

    in.close();
    out.close();

    return 0;
}
