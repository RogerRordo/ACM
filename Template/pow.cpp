int pow(int x,int y,int mod)
{
    int res=1;
    while(y)
    {
        if (y&1) res=1LL*res*x%mod;
        x=1LL*x*x%mod;
        y>>=1;
    }
    return res;
}
