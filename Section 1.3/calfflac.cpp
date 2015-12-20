/*
ID: Rainow
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("calfflac.in");
    ofstream out("calfflac.out");

    struct thetext
    {
        char m;
        int num;
    };

    char fulltext[21000];
    thetext text[21000];

    char *p ;
    thetext *q;
    int maxlen = 0;
    int i = 0 , n = 0;
    int begin ,end;
    p = fulltext;
    q = text;

    while(!in.eof())
    {
        *p = in.get();
        if(*p>='A' &&*p<='Z')
        {
            q->m = *p + 32;
            q->num = i;
            ++n;
            ++q;
        }
        else if(*p>='a' && *p<='z')
            {
                q->m = *p;
                q->num = i;
                ++n;
                ++q;
            }

        ++i;
        ++p;

    }

    for(i=0;i<n;++i)
    {
        int j , k , s;
        j=i-1; k=i+1; s=1;                                      //奇数情况
        while( j>=0 && k<n && text[j].m == text[k].m)
        {
            --j;
            ++k;
            s+=2;
        }
        if(s>maxlen)
        {
            maxlen = s;
            begin = j+1;
            end = k-1;

        }

        j=i; k=i+1; s=0;                                        //偶数情况
        while( j>=0 && k<n && text[j].m == text[k].m)
        {
            --j;
            ++k;
            s+=2;
        }
        if(s>maxlen)
        {
            maxlen = s;
            begin = j+1;
            end = k-1;
        }
    }

    out<<maxlen<<endl;
    for(i=text[begin].num;i<=text[end].num;++i)
    {
        out<<fulltext[i];
    }

    out<<endl;

    return 0;
}
