/*
ID: Rainow
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("beads.in");
    ofstream out("beads.out");

    int N , i , length = 0 , max=0 , swith = 0 , tmp;
    char *necklace , first;
    in>>N;

    necklace = new char[N*2];

    for(i=0;i<N;i++) in>>necklace[i];
    for(i=N;i<N*2;i++) necklace[i]=necklace[i-N];

    for(i=1 ; i < N*2 ; i++)
    {
        if(necklace[i] != 'w')
        {
            first = necklace[i];
            break;
        }
    }

    for( i=0 ; i < N*2 ;i++)
    {
        if(necklace[i]==first || necklace[i] == 'w') length++;
        else if(swith != 2)
            {
                swith++;
                if(swith == 1)
                {
                    length++;
                    tmp = i;
                    first = necklace[i];
                }
            }

        if(swith == 2)
        {
            if(length > max)
                max = length;

            length = 1;
            if( i>N ) break;
            first = necklace[tmp];
            while(necklace[tmp-1]=='w') tmp = tmp - 1;
            i = tmp;
            swith = 0;
        }
    }
    if(length > max)
        max = length;
    if(max > N) max=N;

    out<<max<<endl;

    in.close();
    out.close();

    return 0;
}
