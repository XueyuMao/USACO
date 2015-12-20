/*
ID: Rainow
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("ride.in");
    ofstream out("ride.out");

    char input1[7] , input2[7];

    in>>input1>>input2;
    int sum1 = 1 , sum2 = 1 , i;

    for( i = 0 ; input1[i] != '\0' ; ++i )
        sum1 *= input1[i] - 'A' + 1 ;
    for( i = 0 ; input2[i] != '\0' ; ++i )
        sum2 *= input2[i] - 'A' + 1 ;

    if(sum1 % 47 == sum2 % 47) out<<"GO"<<'\n';
        else out<<"STAY"<<'\n';

    in.close();
    out.close();

    return 0;
}
