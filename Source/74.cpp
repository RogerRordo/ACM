#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
ll n;
ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
int main()
{
    n=read();
    printf("%lld\n",n*(n+1)*(n+2)/2);
    return 0;
}
