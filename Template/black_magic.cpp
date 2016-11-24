//=====================万能头文件=====================
#include<bits/stdc++.h>
//=====================强制O2优化=====================
#pragma GCC optimize(2)
//========================开栈========================
//g++开栈 放在main开头
int __size__=256<<20;//256MB
char *__p__=(char*)malloc(__size__)+__size__;
__asm__ __volatile__("movq %0,%%rsp\n"::"r"(__p__));
//c++开栈
#pragma comment(linker,"/STACK:102400000,102400000")
//=====================C++IO加速=====================
#include <iomanip>
ios_base::sync_with_stdio(false);
//=====================大数mulmod=====================
//int128法
ll mulmod(__int128 x,__int128 y,__int128 mod)   //同理存在__float128
{
    return x*y%mod;
}

//快速乘法
ll mulmod(ll x,ll y,ll mod)
{
	ll ret = 0;
	for(;y;y>>=1)
	{
		if (y&1) ret=(ret+x)%mod;
		x=(x+x)%mod;
	}
	return ret;
}

//汇编法
ll mulmod(ll x,ll y,ll mod) //注意！必须保证x，y都比mod小；可long，不可int
{
    ll ans=0;
    __asm__
    (
        "movq %1,%%rax\n imulq %2\n idivq %3\n"
        :"=d"(ans):"m"(x),"m"(y),"m"(mod):"%rax"
    );
    return ans;
}
//======================其它小东西======================
int __gcd(int x,int y)  //<algorithm>且g++才能用
