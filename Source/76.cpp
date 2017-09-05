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
#define maxn 52
using namespace std;
struct mat{ll a[maxn][maxn];} a;
int n;
mat operator*(mat x,mat y)
{
    int i,j,k;
    mat res;
    tr(i,1,n) tr(j,1,n)
    {
        res.a[i][j]=0;
        tr(k,1,n) res.a[i][j]+=x.a[i][k]*y.a[k][j];
        if (res.a[i][j]>0) res.a[i][j]=1;
        else res.a[i][j]=0;
    }
    return res;
}
mat operator^(mat x,int y)
{
    mat res;
    if (y==1) return x;
    res=x^(y/2);
    res=res*res;
    if (y&1) res=res*x;
    return res;
}
mat operator+(mat x,mat y)
{
    mat res;
    int i,j;
    tr(i,1,n) tr(j,1,n)
        if (x.a[i][j]+y.a[i][j]>0) res.a[i][j]=1;
        else res.a[i][j]=0;
    return res;
}
ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void init()
{
    int i,j;
    n=read();
    tr(i,1,n) tr(j,1,n) if (read()>0) a.a[i][j]=1;
}
void print(mat x)
{
    int i,j;
    tr(i,1,n)
    {
        tr(j,1,n)
            if (x.a[i][j]) printf("1 ");
            else printf("0 ");
        printf("\n");
    }
}
void work()
{
    mat t,tt;
    int i,j;
    tt=t=a^(n*(n-1));
    tr(i,n*(n-1)+1,n*(n+1))
    {
        t=t*a;
        tt=tt+t;
        //print(t);
    }
    tr(i,1,n) tr(j,1,n)
        if (tt.a[i][j]==0)
        {
            printf("No\n");
            return ;
        }
    printf("Yes\n");
}
int main()
{
    init();
    work();
    return 0;
}
