int prime[maxm],a[n];
bool pprime[n];
void EulerPrime()
{
	int i,j;
	tr(i,2,n) pprime[i]=1;
	tr(i,2,n)
	{
		if (pprime[i]) prime[++m]=i;
		tr(j,1,m)
		{
			if (i*prime[j]>n) break;
			pprime[i*prime[j]]=0;
			if (i%prime[j]==0) break;
		}
	}
}
