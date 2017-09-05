#include<iostream>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
int n,i,j;
int main()
{
	cin>>n;
	if (n%2==0) n=(n-2)/2;else n=(n-1)/2;
	cout<<(1+n)*n/2<<endl;
	tr(i,1,n)
		for (j=n+1;j<=2*n+1-i;j++) cout<<i<<' '<<j<<endl;
	return 0;
}
