//===================枚举i的非空子集j===================
for(j=i;j;j=(j−1)&i);
//==================下一个1的个数相等的数==================
int snoob1(int x)
{
    int y=x&-x,z=x+y;
    return z|((x^z)>>2)/y;
}
int snoob2(int x)   //g++
{
    int t=x|(x-1);
    return (t+1)|(((~t&-~t)-1)>>(__builtin_ctz(x)+1));
}
//========================按位反转========================
int reverse(int x)
{
    x=((x&0x55555555)<<1)|((x&0xAAAAAAAA)>>1);
    x=((x&0x33333333)<<2)|((x&0xCCCCCCCC)>>2);
    x=((x&0x0F0F0F0F)<<4)|((x&0xF0F0F0F0)>>4);
    x=((x&0x00FF00FF)<<8)|((x&0xFF00FF00)>>8);
    x=((x&0x0000FFFF)<<16)|((x&0xFFFF0000)>>16);
    return x;
}
//========注意！！以下g++下才能用；ll则在函数名后加ll=========
int __builtin_popcount(unsigned int x); //1的个数
int __builtin_clz(unsigned int x);      //前缀0的个数
//x为int时，31-__builtin_clz(x) 等价于 int(log(x)/log(2))
int __builtin_ctz(unsigned int x);      //后缀0的个数
int __builtin_parity(unsigned int x);   //1的个数%2
