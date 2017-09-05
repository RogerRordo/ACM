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
#define maxas 10005
using namespace std;
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

ll n,l,r,p,q,i,ans,a[maxas],lp,rp,lq,rq;

ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int main()
{
    #ifdef DEBUG
    	freopen("in.txt","r",stdin);
    #endif
	n=read(); l=read(); r=read();
	if (n==1) {writeln(r-l+1); return 0;}
	if (n==2) {writeln((r-l+1)*(r-l)); return 0;}
	a[1]=1;
	tr(q,2,r)
	{
		a[q]=1;
		tr(i,1,n-1)
		{
			a[q]=a[q]*q;
			if (a[q]>r) break;
		}
		if (a[q]>r) break;
		lq=l/a[q]+(l%a[q]>0); rq=r/a[q];
		if (lq>rq) continue;
		tr(p,1,q-1) if (gcd(p,q)==1)
		{
			lp=l/a[p]+(l%a[p]>0); rp=r/a[p];
			if (lp>rp||lp>rq) continue;
			//cout<<lp<<' '<<rp<<' '<<lq<<' '<<rq<<' ';
			lp=max(lp,lq); rp=min(rp,rq);
			ans+=(rp-lp+1);
		}
	}
	writeln(ans*2);
    return 0;
}
