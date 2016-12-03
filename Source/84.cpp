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
using namespace std;

ll gcd(ll x,ll y){return x%y?gcd(y,x%y):y;}
struct frac
{
	ll x,y;	//????x
	frac adjust()
	{
		if (!y) {x=0; return *this;}
		if (!x) {y=1; return *this;}
		ll sg=(x>0?1:-1)*(y>0?1:-1);
		ll t=gcd(x=abs(x),y=abs(y)); x=x/t*sg; y/=t;
		return *this;
	}
	frac(){}
	frac(ll a,ll b){x=a;y=b;this->adjust();}
	frac(char *a,bool improp=0) //improp???
	{
        ll t,sg=1;
        if (*a=='-') {sg=-1; a++;}
        if (improp&&strchr(a,' ')) {sscanf(a,"%lld %lld/%lld",&t,&x,&y); x+=t*y;}
        else if (strchr(a,'/')) sscanf(a,"%lld/%lld",&x,&y);
        else {sscanf(a,"%lld",&x); y=1;}
        x*=sg; this->adjust();
	}
	char* c_str(bool improp=0)
	{
		char *res=new char[100](),t[100];
		this->adjust();
		if (x==0) {res[0]='0'; return res;}
		if (x<0) {strcat(res,"-"); x=-x;}
		if (improp&&x/y&&x%y){sprintf(t,"%lld ",x/y); strcat(res,t); x%=y;}
		sprintf(t,"%lld",x); strcat(res,t);
		if (y!=1) {sprintf(t,"/%lld",y); strcat(res,t);}
		return res;
	}
	
    bool friend operator==(frac a,frac b){a.adjust();b.adjust();return a.x==b.x&&a.y==b.y;}
    bool friend operator!=(frac a,frac b){a.adjust();b.adjust();return !(a.x==b.x&&a.y==b.y);}
    bool friend operator>(frac a,frac b){if(a.x*b.x<=0)return a.x>b.x;return a.x*b.y>b.x*a.y;}
    bool friend operator<(frac a,frac b){if(a.x*b.x<=0)return a.x<b.x;return a.x*b.y<b.x*a.y;}
    frac friend operator+(frac a,frac b){return frac(a.x*b.y+a.y*b.x,a.y*b.y).adjust();}
    frac friend operator-(frac a,frac b){return frac(a.x*b.y-a.y*b.x,a.y*b.y).adjust();}
    frac friend operator*(frac a,frac b){return frac(a.x*b.x,a.y*b.y).adjust();}
    frac friend operator/(frac a,frac b){return frac(a.x*b.y,a.y*b.x).adjust();}
};

int main()
{
	frac a,b; char sa[100],sb[100],c;
    gets(sa); c=getchar(); getchar(); gets(sb);
    a=frac(sa,1); b=frac(sb,1);
    if (c=='+') printf("%s",(a+b).c_str(1));
    if (c=='-') printf("%s",(a-b).c_str(1));
    if (c=='*') printf("%s",(a*b).c_str(1));
    if (c=='/') printf("%s",(a/b).c_str(1));
	return 0;	
}