/*
	Time:
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
#define oo 0x7F7F7F7F
#define maxn 105
#define maxm 20005
using namespace std;
int n,m,ii,ss,i,ah[maxn];
struct edge{int x,y,d,pre;} a[maxm];
bool p[maxn];
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void write(int x)
{
    char a[20],s=0;
    if (x==0){putchar('0'); return ;}
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeln(int x){write(x); putchar('\n');}
void newedge(int x,int y,int z)
{
    m++;
    a[m].x=x; a[m].y=y; a[m].d=z;
    a[m].pre=ah[x]; ah[x]=m;
}
void init()
{
    int i,x,y,z,mm;
    n=read(); mm=read(); ss=read();
    tr(i,1,n) ah[i]=-1; m=-1;
    tr(i,1,mm)
    {
        x=read(); y=read(); z=read();
        newedge(x,y,z); newedge(y,x,z);
    }
}
bool dfs(int x,int s,int last)
{
    int tmp,y;
    p[x]=1;
    if (s>=ss) return 1;
    for(tmp=ah[x];tmp>-1;tmp=a[tmp].pre)
        if ((tmp^last)!=1)
    {
        y=a[tmp].y;
        if (p[y]) return 1;
        if (dfs(y,s+a[tmp].d,tmp)) return 1;
    }
    p[x]=0;
    return 0;
}
int main()
{
    init();
    tr(ii,1,n) if (dfs(ii,0,oo)) {printf("YES\n"); return 0;}
    printf("NO\n");
    return 0;
}
