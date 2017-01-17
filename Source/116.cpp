#include<bits/stdc++.h>
#define tr(i,l,r) for(i=(l);i<=(r);i++)
#define maxl 100005
using namespace std;
char a[maxl],b[maxl];
int i,la,lb,c[30];
long long s;
int main()
{
	freopen("concatenation.in","r",stdin);
	freopen("concatenation.out","w",stdout);
	scanf("%s%s",a,b);
	la=strlen(a); lb=strlen(b);
	tr(i,0,lb-2) c[b[i]-'a']++;
	s=lb;
	tr(i,1,la-1) s+=(long long)(lb-c[a[i]-'a']);
	printf("%lld\n",s);
	return 0;
}
