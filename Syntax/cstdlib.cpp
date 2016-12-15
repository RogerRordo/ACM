//-----------------------------------转换-----------------------------------
double atof (const char* str);
int atoi (const char * str);
char *  itoa ( int value, char * str, int base );
//  1.  atof，atoi和itoa的十进制支持符号，itoa支持科学计数
//  2.  itoa非标！Linux下没有！
//-----------------------------------内存-----------------------------------
void* malloc (size_t size);
void free (void* ptr);
//  1.  e.g.    int *p=(int*)malloc(100*sizeof(int));
//              ...
//              free(p);
//  2.  退出函数不自动释放
//-----------------------------------其它-----------------------------------
int abs (int n);
void srand (unsigned int seed);
int rand (void);
void qsort (void* base, size_t num, size_t size,
            int (*compar)(const void*,const void*));
void* bsearch (const void* key, const void* base,
               size_t num, size_t size,
               int (*compar)(const void*,const void*));
//  1.  rand产生最大的数是RAND_MAX，Linux下是2^31-1，Win下是32767
//  2.  qsort中compar返回负，则前一个变量排在前，0和正类此
//  3.  bsearch为二分，只能找base有没有key，基本废的
