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
#define mod 314159
#define maxn 300005
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
ll p[mod],a[maxn];
int n,i,j;
priority_queue<ll,vector<ll>,greater<ll> >b;
bool hash(ll x)
{
	ll t=x%mod;
	while (p[t]!=0 && p[t]!=x) t=(t+1)%mod;
	if (p[t]==0)
	{
		p[t]=x;
		return 0;
	}
	return 1;
}
int main()
{
	n=3; cin>>a[1]>>a[2]>>a[3];
	b.push(abs(a[1]-a[2]));
	b.push(abs(a[2]-a[3]));
	b.push(abs(a[1]-a[3]));
	hash(a[1]);
	hash(a[2]);
	hash(a[3]);
	while (1)
	{
		i++;
		a[i+3]=b.top();
		if (hash(a[i+3]))
		{
			cout<<i+1<<endl;
			return 0;
		}
		tr(j,1,i+2) b.push(abs(a[j]-a[i+3]));
	}
	return 0;
}
