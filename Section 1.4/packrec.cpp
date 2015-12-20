/*
ID: Rainow
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int total, MIN=10000;
int a[5][3];
int Ans[100][3];
int a1, a2, a3, a4, b1, b2, b3, b4;

int divide(int low,int high)
{
    int k = Ans[low][1];
    int m = Ans[low][2];
    do
    {
        while(low<high && Ans[high][1]>=k) --high;
        if(low<high)
        {
            Ans[low][1]=Ans[high][1];
            Ans[low][2]=Ans[high][2];
            ++low;
        }
        while(low<high && Ans[low][1]<=k) ++low;
        if(low<high)
        {
            Ans[high][1]=Ans[low][1];
            Ans[high][2]=Ans[low][2];
            --high;
        }
    }while(low!=high);
    Ans[low][1]=k;
    Ans[low][2]=m;
    return low;
}

void quicksort(int low,int high)
{
    int mid;
    if(low>=high) return;
    mid = divide(low,high);
    quicksort(low,mid-1);
    quicksort(mid+1,high);
}

int max(int a, int b)
{
    if( a > b )
        return a;
    else
        return b;
}

void update(int x, int y)            //更新最小值
{
    if(x*y>MIN) return;
    if(x*y<MIN)
    {
        MIN = x*y;
        total = 0;
    }

    if(x>y) swap(x,y);

    int i;
    for(i=1;i<=total;++i)
        if(x==Ans[i][1]&&y==Ans[i][2])
            return;

    ++total;
    Ans[total][1]=x;
    Ans[total][2]=y;

}

void putrec()
{
    int h1=a[a1][b1], h2=a[a2][b2], h3=a[a3][b3], h4=a[a4][b4];
    int w1=a[a1][3-b1], w2=a[a2][3-b2], w3=a[a3][3-b3], w4=a[a4][3-b4];
    int height, width;

    width = w1 + w2 + w3 + w4;
    height = max(max(max(h1,h2),h3),h4);
    update(width,height);

    width = max(w1 + w2 + w3 , w4);//第二次
    height = max(max(h1,h2),h3)+h4;
    update(width,height);

    width = max(w1+w2,w3)+w4;//第三次
    height = max(max(h1,h2)+h3,h4);
    update(width,height);

    width = w1+w2+max(w3,w4);//第四次
    height = max(max(h1,h2),h3+h4);
    update(width,height);

    height = max(h1+h2,h3+h4);
    if( (h2 >= h4) && (w1>w2 || w3<w4))
        width = max(w1+w3,w2+w4);
    else
        width = max(w1,w2) + max(w3,w4);
    update(width,height);
}

void findmin()
{
    for(a1=1;a1<5;++a1)
        for(a2=1;a2<5;++a2)
        {
            if(a1 != a2)
            {
                for(a3=1;a3<5;++a3)
                {
                    if(a3 != a2 && a3 != a1)
                    {
                        a4=10-a1-a2-a3;                     //第一个四重循环枚举每个矩形的摆放位置
                        for(b1=1;b1<3;++b1)
                            for(b2=1;b2<3;++b2)
                                for(b3=1;b3<3;++b3)
                                    for(b4=1;b4<3;++b4)
                                        putrec();           //第二个四重循环枚举每个矩形的摆放形式（横放或者竖放）
                    }
                }
            }
        }
}

int main()
{
    ifstream in("packrec.in");
    ofstream out("packrec.out");

    int i,j;
    for(i=1;i<5;++i)
    {
        in>>a[i][1]>>a[i][2];
    }

    findmin();

    /*
    for(i=1;i<total;++i)
        for(j=i+1;j<=total;++j)
        {
            if(Ans[i][1]>Ans[j][1])
            {
                swap(Ans[i][1],Ans[j][1]);
                swap(Ans[i][2],Ans[j][2]);
            }
        }
    */

    quicksort(1,total);
    out<<MIN<<endl;
    for(i=1;i<=total;++i)
    {
        out<<Ans[i][1]<<' '<<Ans[i][2]<<endl;
    }


    return 0;
}
