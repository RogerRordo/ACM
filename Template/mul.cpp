//快速乘法
ll mul(ll x,ll y,ll mod)
{
	ll res=0;
	for(;y;y>>=1)
	{
		if (y&1) res=(res+x)%mod;
		x=(x+x)%mod;
	}
	return res;
}

//int128法
ll mul(__int128 x,__int128 y,__int128 mod)   //同理存在__float128
{
    return x*y%mod;
}

//汇编法
ll mul(ll x,ll y,ll mod) //注意！必须保证x，y都比mod小；可long，不可int
{
    ll ans=0;
    __asm__
    (
        "movq %1,%%rax\n imulq %2\n idivq %3\n"
        :"=d"(ans):"m"(x),"m"(y),"m"(mod):"%rax"
    );
    return ans;
}
