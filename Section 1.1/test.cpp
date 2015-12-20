/*
ID: Rainow
PROG: test
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("test.in");
    ofstream out("test.out");

    int a , b ;

    in>>a>>b;

    out<<a + b<<'\n';

    in.close();
    out.close();

    return 0;
}
