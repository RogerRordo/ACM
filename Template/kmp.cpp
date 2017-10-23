char s[maxn];
int n,nxt[maxn];
void kmp()
{
	int i,j=0;
	nxt[1]=0;
	tr(i,2,n)
	{
		while(j&&s[j+1]!=s[i]) j=nxt[j];
		if (s[j+1]==s[i]) j++;
		nxt[i]=j;
	}
}
