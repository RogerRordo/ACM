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
#include<bitset>
#define ll long long
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
struct h
{
    int a,b,c,d;
    bool operator ==(h t)
    {
        return a==t.a && b==t.b && c==t.c && d==t.d;
    }
} x,y,t;
int dats,dat,ii;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
int main()
{
    dats=read();
    tr(dat,1,dats)
    {
        x.a=read(); x.b=read(); x.c=read(); x.d=read();
        y.a=read(); y.b=read(); y.c=read(); y.d=read();
        printf("Case #%d: ",dat);
        tr(ii,1,4)
        {
            if (x==y) {puts("POSSIBLE"); break;}
            t=x; x.a=t.c; x.b=t.a; x.c=t.d; x.d=t.b;
        }
        if (ii==5) puts("IMPOSSIBLE");
    }
    return 0;
}
