/*
ID: Rainow
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int divide(int a[] , int low ,int high)
{
    int k = a[low];
    do
    {
        while(low<high && a[high] >= k )
            --high;
        if(low < high)
        {
            a[low] = a[high];
            ++low;
        }
        while(low<high && a[low] <= k )
            ++low;
        if(low < high)
        {
            a[high] = a[low];
            --high;
        }
    } while(low != high);

    a[low]=k;
    return low;
}

void quicksort(int a[],int low,int high)
{
    int mid;
    if(low>=high) return;
    mid = divide(a,low,high);
    quicksort(a,low,mid-1);
    quicksort(a,mid+1,high);
}

int main()
{
    ifstream in("ariprog.in");
    ofstream out("ariprog.out");

    int N,M;
    int i,j,k;
    int tmp;
    in>>N>>M;
    int num[125001];
    bool flag[125001]={false};
    int dif;
    int cnt=0;
    int cntab=0;

    for(i=0;i<=M;++i)
    {
        for(j=0;j<=M;++j)
        {
            tmp = i*i+j*j;
            if(flag[tmp]) continue;
            num[cnt]=tmp;
            flag[num[cnt]]=true;
            ++cnt;
        }
    }

    --cnt;
    dif = (num[cnt]-num[0])/(N-1);
    quicksort(num,0,cnt);

    for(i=1;i<=dif;++i)
    {
        for(j=0;j<=cnt;++j)
        {
            if((num[j]+(N-1)*i)>num[cnt]) break;
            for(k=0;k<N;++k)
            {
                if(!flag[num[j]+k*i])
                    break;
            }
            if(k==N)
            {
                if(cntab==10000)
                {
                    out<<"too much"<<endl;
                    return 0;
                }
                out<<num[j]<<' '<<i<<endl;
                ++cntab;
            }
        }
    }

    if(cntab==0)
        out<<"NONE"<<endl;

    /*for(i=0;i<=cnt;++i)
    {
        out<<num[i]<<endl;
    }*/

    return 0;
}
