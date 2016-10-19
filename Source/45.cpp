//一开始用multiset TLE，还以为死循环，结果改成map就过了，证明multiset效率太低
#include<cstdio>
#include<string>
#include<map>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
int n,i,j;
string t;
bool p;
char buff[105],ch;
int to[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9};
map<string,int> a;
char read()
{
    char ch=getchar();
    while (!((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Y'))) ch=getchar();
    if (ch>='A'&&ch<='Y') return to[ch-'A']+'0';
    return ch;
}
int main()
{
    scanf("%d",&n);
    tr(i,1,n)
    {
        t="";
        tr(j,1,3) t+=read();
        t+='-';
        tr(j,1,4) t+=read();
        a[t]++;
    }
    for(map<string,int>::iterator it=a.begin();it!=a.end();it++)
        if (it->second>1)
        {
            printf("%s %d\n",it->first.c_str(),it->second);
            p=1;
        }
    if (!p) printf("No duplicates.\n");
    return 0;
}
