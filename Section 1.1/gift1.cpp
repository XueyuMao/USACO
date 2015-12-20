/*
ID: Rainow
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

class friendgive
{
public:
    string name;
    int money;
    int save;
    int give;

    friendgive(string na, int x, int y )
    {
        name = na;
        money = x;
        give = y;
        save = 0;
    };
    friendgive():save(0) {};
    ~friendgive() {};

    int givegifts()
    {
		int m;
        if(give != 0)
		{
			m = money/give;
            save += money - m*give;
			return m;
		}
		else return 0;

    }
    void receive(int x)
    {
        save += x;
    }
};

int main()
{
    friendgive *friends;
    ifstream in("gift1.in");
    ofstream out("gift1.out");

    int NP, NoG, mon, i,j,m,value;
    string name, receiver;

    in>>NP;

    friends = new friendgive[NP];

    for( i = 0 ; i < NP ; i++)
    {
        in>>name;
        friends[i].name = name;
    }

    for(i = 0 ; i < NP ; i++)
    {
        in>>name;
        in>>mon>>NoG;

        for(m = 0; m<NP;m++)
        {
            if(friends[m].name==name)
            {
                friends[m].money = mon;
                friends[m].give = NoG;
                value=friends[m].givegifts();
                break;
            }
        }
        for( j = 0 ; j < NoG ; j++)
        {
            in>>name;
            for(m = 0; m<NP;m++)
            {
                if(friends[m].name==name)
                {
                    friends[m].receive(value);
                    break;
                }
            }
        }
    }

    for(i = 0 ;i<NP;i++)
    {
        out<<friends[i].name<<" "<<friends[i].save-friends[i].money<<'\n';
    }

    in.close();
    out.close();


    return 0;
}
