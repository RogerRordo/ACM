#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<bitset>
#define ll long long
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define rtr(i,r,l) for((i)=(r);(i)>=(l);--i)
#define oo 0x7F7F7F7F
#define maxn 100005
using namespace std;
ll a[maxn],s[maxn];
int n;
int read()
{
    int x=0; bool f=0;
    char ch=getchar();
    while (ch<'0'||ch>'9') {f|=ch=='-'; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0'; ch=getchar();}
    return (x^-f)+f;
}
void write(int x)
{
    char a[20],s=0;
    if (x==0){putchar('0'); return ;}
    if (x<0) {putchar('-'); x=-x;}
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeln(int x){write(x); putchar('\n');}
void init()
{
    int m,i,l,r,x;
    n=read(); m=read();
    tr(i,1,m)
    {
        l=read(); r=read(); x=read();
        a[l]+=x; a[r+1]-=x;
    }
}
void work()
{
    int ans=0,q,i,x; ll y,t=0;
    q=read();
    tr(i,1,n)
    {
        t+=a[i]; s[i]=s[i-1]+t;
    }
    tr(i,1,q)
    {
        scanf("%lld",&y); x=read();
        ans+=s[n]-s[x-1]<y;
    }
    writeln(ans);
}
int main()
{
    init();
    work();
    return 0;
}
