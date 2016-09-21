/*
	Time: 160720
	Prob: POJ1258
	By RogerRo
*/
#include<iostream>
#include<cstring>
#include<queue>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 105
using namespace std;
typedef pair<int,int> pa;
priority_queue<pa,vector<pa>,greater<pa> >d;
int n,i,j,a[maxn][maxn];
bool p[maxn];
void prim()
{
	int s;
	pa t;
	while (d.size()) d.pop();
	tr(i,2,n) d.push(make_pair(a[1][i],i));
	memset(p,0,sizeof(p));
	p[1]=true;
	s=0;
	tr(i,2,n)
	{
		while (d.size() && p[d.top().second]) d.pop();
		t=d.top();
		s+=t.first;
		p[t.second]=true;
		tr(j,1,n) if (!p[j]) d.push(make_pair(a[t.second][j],j));
	}
	cout<<s<<endl;
}
int main()
{
	while (cin>>n)
	{
		tr(i,1,n) tr(j,1,n) cin>>a[i][j];
		prim();
	}
	return 0;
}
