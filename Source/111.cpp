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
#define maxn 1000005
using namespace std;
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
int n,b[maxn],c[maxn];
string a[maxn];
vector<string> ans[maxn];
void init()
{
	char ch;
	n=1;
	while ((ch=getchar())!=EOF) 
	{
		if (ch==',') 
		{
			scanf("%d",&b[n]);
			if (scanf(",")==EOF) break;
			n++;	
		} else a[n]+=ch;
	}
}
void work()
{
	int i,ss=1,s=1;
	c[1]=oo;
	tr(i,1,n)
	{
		ans[s].push_back(a[i]);
		c[s]--;
		if (b[i])
		{
			s++; c[s]=b[i];
			ss=max(ss,s);
		}
		while (c[s]==0) s--;
	}
	writeln(ss);
	tr(i,1,ss)
	{
		vector<string>::iterator it=ans[i].begin();
		cout<<*it;
		for(it++;it!=ans[i].end();it++) cout<<' '<<*it;
		cout<<endl;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
    init();
    work();
    return 0;
}