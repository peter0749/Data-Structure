#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void honai(const int lev, const char src, const char buffer, const char des)
{
    if(lev>0)
    {
        honai(lev-1, src, des, buffer);
        cout<<"Move disk "<<lev<<" from "<<src<<" to "<<des<<'\n';
        honai(lev-1, buffer, src, des);
    }
}

int main(void)
{
    char A='A',B='B',C='C';
    int n;
    while(cin>>n)
        honai(n,A,B,C);
    return 0;
}
