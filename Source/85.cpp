/*
	Time: 161204
	Prob: 
	By RogerRo
 */
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
using namespace std;
int n,m;
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
void writeb(int x){write(x); putchar(' ');}
void writeln(int x){write(x); putchar('\n');}
void print(int x)
{
    writeb(++m); writeln(x);
}
void solve()
{
    int k;
    bool first=1;
    if (n%6!=2&&n%6!=3)
    {
        for(int i=2;i<=n;i+=2) print(i);
        for (int i=1;i<=n;i+=2) print(i);
    } else {
        k=n/2;
        if(k%2==0)
        {
            for(int i=k;i<=n;i+=2) print(i);
            for(int i=2;i<=k-2;i+=2) print(i);
            for(int i=k+3;i<=n-1;i+=2) print(i);
            for(int i=1;i<=k+1;i+=2) print(i);
            if (n%2==1) print(n);
        } else {
            for(int i=k;i<=n-1;i+=2) print(i);
            for(int i=1;i<=k-2;i+=2) print(i);
            for(int i=k+3;i<=n;i+=2) print(i);
            for(int i=2;i<=k+1;i+=2) print(i);
            if (n%2==1) print(n);
        }
    }
}
int main()
{
    n=read();
    solve();
    return 0;
}