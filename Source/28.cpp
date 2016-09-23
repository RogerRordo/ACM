#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<queue>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#define ll long long
#define oo 0x7F7F7F7F
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
int dats,i,n,a,d;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while (!(ch>='0' && ch<='9')) {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

int main()
{
	cin>>dats;
	tr(i,1,dats)
	{
		cin>>n>>a>>d;
		cout<<(a+(a+d*(n-1)))*n/2<<endl;
	}
	return 0;
}

