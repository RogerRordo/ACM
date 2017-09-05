/*
	Time: 160718
	Prob: POJ1611
	By RogerRo
*/
#include<iostream>
#define oo 2147483647
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 30005
#define maxm 505
using namespace std;
int n,m,fa[maxn],i,j,k,tx,ty;
int gfa(int x){return(fa[x]==x?x:fa[x]=gfa(fa[x]));}
int main()
{
	cin>>n>>m;
	while (n>0)
	{
		tr(i,1,n) fa[i]=i;
		tr(i,1,m)
		{
			cin>>k;
			if (k>0) cin>>tx; tx++;
			tr(j,2,k)
			{
				cin>>ty; ty++;
				fa[gfa(ty)]=gfa(tx);
			}
		}
		k=0;
		tr(i,1,n) if(gfa(i)==gfa(1)) k++;
		cout<<k<<endl;
		cin>>n>>m;
	}
	return 0;
}
