/*
ID: Rainow
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

void move(int a[],int n)
{
    switch (n)
    {
        case 1:
            a[0]+=3;
            a[1]+=3;
            a[3]+=3;
            a[4]+=3;
            break;
        case 2:
            a[0]+=3;
            a[1]+=3;
            a[2]+=3;
            break;
        case 3:
            a[1]+=3;
            a[2]+=3;
            a[4]+=3;
            a[5]+=3;
            break;
        case 4:
            a[0]+=3;
            a[3]+=3;
            a[6]+=3;
            break;
        case 5:
            a[1]+=3;
            a[3]+=3;
            a[4]+=3;
            a[5]+=3;
            a[7]+=3;
            break;
        case 6:
            a[2]+=3;
            a[5]+=3;
            a[8]+=3;
            break;
        case 7:
            a[3]+=3;
            a[4]+=3;
            a[6]+=3;
            a[7]+=3;
            break;
        case 8:
            a[6]+=3;
            a[7]+=3;
            a[8]+=3;
            break;
        case 9:
            a[4]+=3;
            a[5]+=3;
            a[7]+=3;
            a[8]+=3;
            break;
    }
}

bool isEnd(int a[])
{
    if(a[0]%12==0 && a[1]%12==0 && a[2]%12==0 && a[3]%12==0 && a[4]%12==0 &&
       a[5]%12==0 && a[6]%12==0 && a[7]%12==0 && a[8]%12==0 )
        return true;
    else
        return false;
}

int main()
{
    ifstream in("clocks.in");
    ofstream out("clocks.out");

    int clk[9];
    int i,j,k,l;
    int moveit[9];
    int mov[9];
    int tmp[9];
    int min=1000;
    int step=0;
    int minst=1000;
    int endcnt;

    for(i=0;i<9;++i)
        in>>clk[i];

    for(moveit[0]=0;moveit[0]<4;++moveit[0])
    {
        for(moveit[1]=0;moveit[1]<4;++moveit[1])
        {
            for(moveit[2]=0;moveit[2]<4;++moveit[2])
            {
                for(moveit[3]=0;moveit[3]<4;++moveit[3])
                {
                    for(moveit[4]=0;moveit[4]<4;++moveit[4])
                    {
                        for(moveit[5]=0;moveit[5]<4;++moveit[5])
                        {
                            for(moveit[6]=0;moveit[6]<4;++moveit[6])
                            {
                                for(moveit[7]=0;moveit[7]<4;++moveit[7])
                                {
                                    for(moveit[8]=0;moveit[8]<4;++moveit[8])
                                    {
                                        for(i=0;i<9;++i)
                                            tmp[i]=clk[i];
                                        step=0;

                                        for(i=0;i<9;++i)
                                        {
                                            for(j=0;j<moveit[i];++j)
                                            {
                                                move(tmp,i+1);
                                                ++step;
                                            }
                                        }

                                        if(isEnd(tmp))
                                        {
                                            if(step<=minst)
                                            {
                                                minst = step;
                                                if(moveit[0]+moveit[1]+moveit[2]+moveit[3]+moveit[4]+moveit[5]+moveit[6]+moveit[7]+moveit[8] < min)
                                                {
                                                    min = moveit[0]+moveit[1]+moveit[2]+moveit[3]+moveit[4]+moveit[5]+moveit[6]+moveit[7]+moveit[8];
                                                    mov[0]=moveit[0];
                                                    mov[1]=moveit[1];
                                                    mov[2]=moveit[2];
                                                    mov[3]=moveit[3];
                                                    mov[4]=moveit[4];
                                                    mov[5]=moveit[5];
                                                    mov[6]=moveit[6];
                                                    mov[7]=moveit[7];
                                                    mov[8]=moveit[8];
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    j = 0;
    for(endcnt=0;endcnt<9;++endcnt)
    {
        if(mov[endcnt]!=0)
            j=endcnt;
    }

    for(endcnt=0;endcnt<j;++endcnt)
    {
        if(mov[endcnt]!=0)
        {
            for(l=0;l<mov[endcnt];++l)
                out<<endcnt+1<<' ';
        }
    }

    for(k=0;k<mov[j]-1;++k)
        out<<j+1<<' ';
    out<<j+1<<endl;

    return 0;
}
