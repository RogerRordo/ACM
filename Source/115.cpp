#include<bits/stdc++.h>
#define tr(i,l,r) for(i=(l);i<=(r);i++)
using namespace std;
double x,y,s;
int main()
{
	freopen("alex.in","r",stdin);
	freopen("alex.out","w",stdout);
	scanf("%lf%lf",&x,&y);
	s=0;
	if (max(x,y)/3<=min(x,y)+1E-8) s=max(x,y)/3;
	else s=min(x,y);
	s=max(s,min(x,y)/2);
	printf("%.4lf\n",s);
	return 0;
}
