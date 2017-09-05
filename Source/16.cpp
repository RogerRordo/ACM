#include<iostream>
#include<cmath>
#define maxn 10100
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
int n,m,i,j,s,a[maxn];
double slo;
int main()
{
	cin>>n>>m;
	tr(i,1,n+m-1) cin>>a[i];
	tr(i,1,n)
	{
		slo=double(-0x7FFFFFFE);
		tr(j,0,m-1) slo=max(slo,double(a[i+j]-s)/(j+1)); 
		cout<<int(ceil(slo)); if (i<n) cout<<' ';
		s+=int(ceil(slo));
	}
	cout<<endl;
	return 0;
}