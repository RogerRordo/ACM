#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define oo 0x7F7F7F7F
#define maxn 100005
#define maxm 100005
using namespace std;
int n,m,a[maxn],b[maxm],last[maxm];
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
    if (x<0) {putchar('-'); x=-x;}
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeln(int x){write(x); putchar('\n');}
void init()
{
	int i;
	n=read(); m=read();	
	tr(i,1,n) a[i]=read();
	tr(i,1,m) b[i]=read();
}
bool check(int x)
{
	int i,tof=0,s=0;
	memset(last,0,sizeof(int)*(m+1));
	for(i=x;i;i--)
		if (a[i]&&!last[a[i]])	
		{
			s++;
			last[a[i]]=i;
			tof+=b[a[i]];
		} 
		else tof=max(tof-1,0);
	if (s<m||tof) return 0;
	return 1;
}
int ef()
{
	int l,r,mid;
	l=0; r=n+1;
	while (l+1<r)
	{
		mid=(l+r)>>1;
		if (check(mid))	r=mid; else l=mid;
	}
	if (r>n) return -1; else return r;
}
int main()
{
    init();
    writeln(ef());
    return 0;
}
