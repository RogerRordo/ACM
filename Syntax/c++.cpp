//----------------------------------函数重载----------------------------------
//  以sort举例
struct t{int a;...} ar[n];
//重载operator<
bool operator<(const t&x,const t&y){return x.a<y.a;}
sort(a,a+n);
//比较函数
bool cmp(const t&x,const t&y){return x.a<y.a;}
sort(a,a+n,cmp);
//仿函数1（重载operator()）
struct cmp(){bool operator()(const t&x,const t&y){return x.a<y.a;}}
sort(a,a+n,cmp());
//仿函数2（重载operator()）
struct cmp(){bool operator()(const t&x,const t&y){return x.a<y.a;}} p;
sort(a,a+n,p);
