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
