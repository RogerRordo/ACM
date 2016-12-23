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
#define maxn 257
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
int n,a[maxn],s[5];
char c[5]={'?','A','C','G','T'};
char fr[maxn];
int get(char c)
{
	if (c=='?') return 0;
	if (c=='A') return 1;
	if (c=='C') return 2;
	if (c=='G') return 3;
	return 4;	
}
void init()
{
	int i;
	n=read();
	gets(fr);
	tr(i,0,n-1) s[a[i+1]=get(fr[i])]++;
}
void work()
{
	int i;
	if (n%4>0||max(max(s[1],s[2]),max(s[3],s[4]))>n/4)
	{
		printf("===\n"); return;
	}
	tr(i,1,n) if (!a[i])
	{
		if (s[1]<n/4) {a[i]=1; s[1]++;}
		else if (s[2]<n/4) {a[i]=2; s[2]++;}
		else if (s[3]<n/4) {a[i]=3; s[3]++;}
		else {a[i]=4; s[4]++;}
	}
	tr(i,1,n) putchar(c[a[i]]);
	putchar('\n');
}
int main()
{
    init();
    work();
    return 0;
}