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
#define maxn 105
#define maxm 205
using namespace std;
struct edge
{
    int x,y,pre;
    double r,c;
} a[maxm];
int n,m,st,b[maxn],ah[maxn];
double s[maxn];
bool p[maxn];
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void init()
{
    int i,mm;
    n=read();
    mm=read();
    st=read();
    scanf("%lf",&s[st]);
    tr(i,1,mm)
    {
        m++;
        a[m].x=read(); a[m].y=read();
        scanf("%lf%lf",&a[m].r,&a[m].c);
        a[m].pre=ah[a[m].x]; ah[a[m].x]=m;
        m++;
        a[m].x=a[m-1].y; a[m].y=a[m-1].x;
        scanf("%lf%lf",&a[m].r,&a[m].c);
        a[m].pre=ah[a[m].x]; ah[a[m].x]=m;
    }
}
void spfa()
{
    int h,t,tmp,x,y;
    double dt;
    h=-1; t=0;
    b[0]=st;
    p[b[0]]=1;
    while (h!=t)
    {
        h=(h+1)%n;
        x=b[h];
        p[x]=0;
        for(tmp=ah[b[h]];tmp;tmp=a[tmp].pre)
        {
            y=a[tmp].y;
            dt=(s[x]-a[tmp].c)*a[tmp].r;
            if ((dt-s[y])>1E-7)
            {
                s[y]=dt;
                if (!p[y])
                {
                    if (y==st) {puts("YES"); return ;}
                    p[y]=1;
                    t=(t+1)%n;
                    b[t]=y;
                }
            }
        }
    }
    puts("NO");
}
int main()
{
    init();
    spfa();
    return 0;
}
