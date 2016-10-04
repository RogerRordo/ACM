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
#define maxm 20
using namespace std;
int dats,dat,a[maxm],m,b[maxm];
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
int rch()
{
    char ch=' ';
    while (!((ch=='*')||(ch>='1'&&ch<='4'))) ch=getchar();
    if (ch=='*') return 0;
    return ch-'0';
}
void init()
{
    int i;
    m=0;
    tr(i,1,16)
    {
        a[i]=rch();
        if (a[i]==0) b[++m]=i;
    }
}
bool get(int b,int c,int d,int f)
{
    return (a[b]+a[c]+a[d]+a[f]==10)&&(a[b]*a[c]*a[d]*a[f]==24);
}
bool pd()
{
    if (!get(1,2,3,4)) return false;
    if (!get(5,6,7,8)) return false;
    if (!get(9,10,11,12)) return false;
    if (!get(13,14,15,16)) return false;
    if (!get(1,5,9,13)) return false;
    if (!get(2,6,10,14)) return false;
    if (!get(3,7,11,15)) return false;
    if (!get(4,8,12,16)) return false;
    if (!get(1,2,5,6)) return false;
    if (!get(3,4,7,8)) return false;
    if (!get(9,10,13,14)) return false;
    if (!get(11,12,15,16)) return false;
    return true;
}
bool pd2()
{
    if (!get(1,2,3,4)) return false;
    if (!get(5,6,7,8)) return false;
    if (!get(1,2,5,6)) return false;
    if (!get(3,4,7,8)) return false;
    return true;
}
void print()
{
    int i,j;
    tr(i,0,3)
    {
        tr(j,1,4) printf("%d",a[4*i+j]);
        printf("\n");
    }
}
bool dfs(int x)
{
    if (x>m)
    {
        if (pd())
        {
            print();
            return true;
        }
        return false;
    }
    if (b[x-1]<=8 && b[x]>8) if (!pd2()) return false;
    a[b[x]]=1; if (dfs(x+1)) return true;
    a[b[x]]=2; if (dfs(x+1)) return true;
    a[b[x]]=3; if (dfs(x+1)) return true;
    a[b[x]]=4; if (dfs(x+1)) return true;
    return false;
}
int main()
{
    dats=read();
    tr(dat,1,dats)
    {
        init();
        printf("Case #%d:\n",dat);
        dfs(1);
    }
    return 0;
}
