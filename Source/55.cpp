#include<cstdio>
#include<algorithm>
#include<cctype>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 260
using namespace std;
char a[maxn],t;
int n;
int main()
{
    while ((a[++n]=getchar())!=EOF)
        if (!isalpha(a[n]))
        {
            t=a[n--];
            while (n) putchar(a[n--]);
            putchar(t);
        }
    n--;
    while (n) putchar(a[n--]);
    return 0;
}
