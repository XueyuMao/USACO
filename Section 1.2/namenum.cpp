/*
ID: Rainow
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include "string.h"

using namespace std;

    void dictchange(long long diction[], ifstream &fin, long long input, ofstream &out)
    {
        bool flag=false;
        int i;
        long long num;
        int cnt = 0;
        char dic[12];
        fin.seekg(0);
        while(!fin.eof())
        {
            fin>>dic;
            num=0;
            for(i=0;i<strlen(dic);i++)
            {
                if(dic[i]=='A' || dic[i]=='B' || dic[i]=='C' )
                    num = num*10 + 2;
                    else if(dic[i]=='D' || dic[i]=='E' || dic[i]=='F' )
                        num = num*10 + 3;
                            else if(dic[i]=='G' || dic[i]=='H' || dic[i]=='I' )
                            num = num*10 + 4;
                                else if(dic[i]=='J' || dic[i]=='K' || dic[i]=='L' )
                                num = num*10 + 5;
                                    else if(dic[i]=='M' || dic[i]=='N' || dic[i]=='O' )
                                    num = num*10 + 6;
                                        else if(dic[i]=='P' || dic[i]=='R' || dic[i]=='S' )
                                        num = num*10 + 7;
                                            else if(dic[i]=='T' || dic[i]=='U' || dic[i]=='V' )
                                            num = num*10 + 8;
                                                else if(dic[i]=='W' || dic[i]=='X' || dic[i]=='Y' )
                                                num = num*10 + 9;
            }
            diction[cnt]=num;

            if(input==diction[cnt])
            {
                out<<dic<<endl;
                flag=true;
            }

            cnt++;
        }
        if(flag == false)
            out<<"NONE"<<endl;
    }


int main()
{
    ifstream in("namenum.in");
    ofstream out("namenum.out");
    ifstream fin("dict.txt");
    long long diction[5000];
    long long  input;

    in>>input;

    dictchange(diction,fin,input,out);

    return 0;
}
