#include<bits/stdc++.h>
#define tr(i,l,r) for(i=(l);i<=(r);i++)
#define maxn 505
using namespace std;
int T,n,m,i,a[maxn],b[maxn];
deque<int> q1,q2;
bool work()
{
	int t1,t2;
	while (!q1.empty()&&!q2.empty())
	{
		t1=q1.front(); q1.pop_front();
		t2=q2.front(); q2.pop_front();
		if (t1==t2) continue;
		if (t1>t2) {q1.push_back(t2); q1.push_back(t1);}
		else {q2.push_back(t1); q2.push_back(t2);}
	}
	return(q1.empty()&&!q2.empty());
}
int main()
{
	srand(time(0));
	scanf("%d",&n);
	tr(i,1,n) scanf("%d",&a[i]);
	memcpy(b,a,sizeof(a));
	T=100000;
	m=min(n,5);
	while (T--) 
	{
		q1.clear(); q2.clear();
		swap(b[rand()%m+1],b[rand()%m+1]);
		tr(i,1,m) q1.push_back(a[i]);
		tr(i,1,m) q2.push_back(b[i]);
		if (work())
		{
			printf("YES\n");
			tr(i,1,n) printf("%d ",b[i]);
			printf("\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
