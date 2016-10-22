/*
	Time: 161022
	Prob: POJ3468
	By RogerRo
 */
#include<cstdio>
#include<algorithm>
#define ll long long
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 100005
using namespace std;
struct node{ll s,tag;} a[4*maxn];
int n,q,i,tx,ty;
char tc;
ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void write(ll x)
{
    char a[20],s=0;
    if (x==0){putchar('0'); return ;}
    if (x<0) {putchar('-'); x=-x;}
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeln(ll x){write(x); putchar('\n');}
void update(int t,int l,int r)
{
    if (l!=r)
    {
        a[t<<1].tag+=a[t].tag;
        a[t<<1|1].tag+=a[t].tag;
    }
    a[t].s+=(ll)(r-l+1)*a[t].tag;
    a[t].tag=0;
}
void add(int t,int l,int r,int x,int y,ll z)
{
    if (x<=l&&r<=y) {a[t].tag+=z; return ;}
    a[t].s+=(ll)(min(r,y)-max(l,x)+1)*z;
    update(t,l,r);
    int mid=(l+r)>>1;
    if (x<=mid) add(t<<1,l,mid,x,y,z);
    if (y>mid) add(t<<1|1,mid+1,r,x,y,z);
}
ll sum(int t,int l,int r,int x,int y)
{
    ll res=0;
    update(t,l,r);
    if (x<=l&&r<=y) return a[t].s;
    int mid=(l+r)>>1;
    if (x<=mid) res+=sum(t<<1,l,mid,x,y);
    if (y>mid) res+=sum(t<<1|1,mid+1,r,x,y);
    return res;
}
int main()
{
    n=read(); q=read();
    tr(i,1,n) add(1,1,n,i,i,read());
    tr(i,1,q)
    {
        tc=getchar(); tx=read(); ty=read();
        if (tc=='C') add(1,1,n,tx,ty,read());
        else writeln(sum(1,1,n,tx,ty));
    }
    return 0;
}
