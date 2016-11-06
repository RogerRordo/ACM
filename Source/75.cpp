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
#include<iomanip>
#define ll long long
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define oo 0x7F7F7F7F
#define maxn 105
int n,k,a[maxn],b[maxn][maxn],m,i,j,t,s;
using namespace std;
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
    n=read(); k=read();
    tr(i,1,n) a[i]=read();
    m=int(ceil(double(n)/double(k)));
    tr(j,1,k) tr(i,1,m)
    {
        b[i][j]=a[++s];
        if (s==n) break;
    }
    tr(i,1,m)
    {
        tr(j,1,k-1) cout<<setw(4)<<right<<b[i][j];
        if ((k-1)*m+i<=n) cout<<setw(4)<<right<<b[i][k];
        cout<<endl;
    }
    return 0;
}
