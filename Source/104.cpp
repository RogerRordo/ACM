/*
ans=\frac{2}{n (n+1)}\left(\frac{1}{4} \sum _{i=1}^n i (n-i) (-i+n+1)+\frac{1}{2} (n (n+1)) F(n)-\sum _{1\leq i<j\leq n,\text{Null}a_i>a_j} i (-j+n+1)\right)
*/
/*
	Time: 161220
	Prob: CF749E
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
#define maxn 200005
using namespace std;
int n,f[maxn],c[maxn],re[maxn],ren;
vector<int> a[maxn];
bool p[maxn];
priority_queue<pair<int,int> > b;
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
void writeb(int x){write(x); putchar(' ');}
void init()
{
    int i,x;
    n=read();
    tr(i,1,n)
    {
        x=read(); f[x]=read();
        a[x].push_back(f[x]);
    }
}
void work()
{
    int q,i,j,s,t;
    tr(i,1,n) if (f[i]) b.push(make_pair(f[i],i));
    q=read();
    tr(i,1,q)
    {
        s=read();
        tr(j,1,s) p[c[j]=read()]=1;
        while (!b.empty())
        {
            if (!p[b.top().second]) break;
            re[++ren]=b.top().second;
            b.pop();
        }
        if (b.empty()) printf("0 0\n");
        else {
            writeb(t=re[++ren]=b.top().second);
            b.pop();
            while (!b.empty())
            {
                if (!p[b.top().second]) break;
                re[++ren]=b.top().second;
                b.pop();
            }
            if (!b.empty()) writeln(*lower_bound(a[t].begin(),a[t].end(),b.top().first));
            else writeln(a[t].front());
        }
        tr(j,1,ren) b.push(make_pair(f[re[j]],re[j]));
        ren=0;
        tr(j,1,s) p[c[j]]=0;
    }
}
int main()
{
    init();
    work();
    return 0;
}
