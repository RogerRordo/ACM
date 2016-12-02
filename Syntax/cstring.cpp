//-----------------------------------修改-----------------------------------
void * memset ( void * ptr, int value, size_t num );
void * memcpy ( void * destination, const void * source, size_t num );
char * strcpy ( char * destination, const char * source );
char * strncpy ( char * destination, const char * source, size_t num );
char * strcat ( char * destination, const char * source );
char * strncat ( char * destination, const char * source, size_t num );
//  1.  以上在后面一定有'\0'的有strcpy，strcat和strncat，注意strncpy不自动加！
//-----------------------------------比较-----------------------------------
int memcmp ( const void * ptr1, const void * ptr2, size_t num );
int strcmp ( const char * str1, const char * str2 );
int strncmp ( const char * str1, const char * str2, size_t num );
//-----------------------------------查找-----------------------------------
const void * memchr ( const void * ptr, int value, size_t num );
      void * memchr (       void * ptr, int value, size_t num );
const char * strchr ( const char * str, int character );
      char * strchr (       char * str, int character );
const char * strrchr ( const char * str, int character );
      char * strrchr (       char * str, int character );
const char * strstr ( const char * str1, const char * str2 );
      char * strstr (       char * str1, const char * str2 );
size_t strspn ( const char * str1, const char * str2 );
size_t strcspn ( const char * str1, const char * str2 );
const char * strpbrk ( const char * str1, const char * str2 );
      char * strpbrk (       char * str1, const char * str2 );
char * strtok ( char * str, const char * delimiters );
//  1.  strrchr的搜索包括\0，所以strrchr(s,0)返回末尾指针
//  2.  strspn返回str1开头最长连续多少个字符都在str2中出现，strcspn相反意义
//  3.  strpbrk返回str1中最先出现在str2中的字符的指针
//  4.  strtok通过delimitters字符集分割str（不包含那些字符），每次取一个分割出的子串用p=strtok(NULL,delimiters)，直到p为NULL
//-----------------------------------其它-----------------------------------
size_t strlen ( const char * str );
