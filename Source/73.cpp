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
#define maxn 1005
using namespace std;
int n;
bool a[maxn],b[maxn];
pair<int,int> f[maxn][maxn];
void init()
{
    int i;
    scanf("%d",&n);
    getchar();
    tr(i,1,n) a[i]=getchar()=='1';
    getchar();
    tr(i,1,n) b[i]=getchar()=='1';
}
void dp()
{
    int i,j;
    f[1][1]=make_pair(1,1);
    tr(i,1,n+1) tr(j,1,n+1)
        if (f[i][j].first)
        {
            if (i<=n-1)
            {
                if (!(a[i]&&a[i+1])&&(a[i]||a[i+1]))
                    f[i+2][j]=make_pair(i,j);
            }
            if (j<=n-1)
            {
                if (!(b[j]&&b[j+1])&&(b[j]||b[j+1]))
                    f[i][j+2]=make_pair(i,j);
            }
            if (i<=n&&j<=n)
            {
                if (!(a[i]&&b[j])&&(a[i]||b[j]))
                    f[i+1][j+1]=make_pair(i,j);
            }
        }
}
void print()
{
    int x,y,tx,ty;
    string s="";
    if (!f[n+1][n+1].first) {printf("Impossible\n"); return;}
    x=n+1; y=n+1;
    while (!(x==1&&y==1))
    {
        tx=f[x][y].first; ty=f[x][y].second;
        if (tx==x-2) s="11"+s;
        else if (ty==y-2) s="22"+s;
        else s="12"+s;
        x=tx; y=ty;
    }
    cout<<s<<endl;
}
int main()
{
    init();
    dp();
    print();
    return 0;
}
