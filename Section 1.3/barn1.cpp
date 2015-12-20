/*
ID: Rainow
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("barn1.in");
    ofstream out("barn1.out");

    int M, S ,C;
    int first, end;
    int i , j;
    int  total;
    struct stall
    {
        int num;
        int sect;
    };

    in>>M>>S>>C;

    if(C==0)
    {
        out<<0<<endl;
        return 0;
    }

    stall barn[C];
    barn[0].sect = 0;

    for(i=0;i<C;i++)
    {
        in>>barn[i].num;
    }

    stall tmp;
    bool flag;

    for(i=1;i<C;++i)
    {
        flag = false;
        for(j=0;j<C-i;++j)
            if(barn[j+1].num<barn[j].num)
            {
                tmp.num = barn[j].num;
                barn[j].num = barn[j+1].num;
                barn[j+1].num = tmp.num;
                flag = true;
            }
        if(!flag) break;
    }

    for(i=1;i<C;++i)
        barn[i].sect = barn[i].num - barn[i-1].num - 1 ;

    first = barn[0].num;
    end = barn[C-1].num;
    total = end - first + 1 ;

    for(i=1;i<C;++i)
    {
        flag = false;
        for(j=0;j<C-i;++j)
            if(barn[j+1].sect<barn[j].sect)
            {
                tmp.num = barn[j].num;
                tmp.sect = barn[j].sect;
                barn[j].num = barn[j+1].num;
                barn[j].sect = barn[j+1].sect;
                barn[j+1].num = tmp.num;
                barn[j+1].sect = tmp.sect;
                flag = true;
            }
        if(!flag) break;
    }

    if(M<=C)
        for(i=0;i<M-1;++i)
        {
            total = total - barn[C-1-i].sect;
        }
    else
        total = C;


    out<<total<<endl;

    in.close();
    out.close();

    return 0;
}
