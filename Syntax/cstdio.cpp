//-------------------------------开关文件（流）-------------------------------
FILE * fopen ( const char * filename, const char * mode );
FILE * freopen ( const char * filename, const char * mode, FILE * stream );
int fclose ( FILE * stream );
//  1.  fopen是载入流；freopen是流的重定向，将filename的文件载至stream
//  2.  mode可选"r"(read),"w"(write),"a"(append)...后可加"b"(binary),"+"(update)或"b+"
//----------------------------------读写流----------------------------------
int printf ( const char * format, ... );
int scanf ( const char * format, ... );
int fprintf ( FILE * stream, const char * format, ... );
int fscanf ( FILE * stream, const char * format, ... );
int sprintf ( char * str, const char * format, ... );
int sscanf ( const char * s, const char * format, ...);
size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
//  1.  f~针对文件，s~针对cstring
//  2.  返回成功读入（输出）元素个数
//  3.  判断读入末尾：while (~scanf()), while (scanf()!=EOF)
//  4.  scanf一个元素[前]，忽略满足<cctype>isspace()的字符，注意读元素[后]的未读入！
//  5.  scanf：%[*][width][length]specifier. *表读指定类型但不保存，width表读入最大字符数；%[ABC]仅读ABC三种字符，%[A-Z]只读大写字母，%[^ABC]表过滤ABC
//  6.  printf：%[flags][width][.precision][length]specifier.
//      [flags]：-左对齐；+数字符号强制显示；0数前补0至列宽；(空格)正数前加空格负数前加负号；#类型o/x/X前加0/0x/0X，类型e/E/f/g/G强制输出小数点，类型g/G保留尾部0
//      specifier：d有符号十进制整；u无符号10进制整；o无符号8进制整；x/X无符号十六进制整（小/大写）；e/E科学计数法double（e小/大写）
//  7.  printf时，百分号%%，单引号\'，双引号\"，反斜杠\\
//  8.  输入特别难搞时，开大小为bufsize的数组buf，然后fread(buf,1,bufsize,stdin)
//--------------------------------逐字符读写--------------------------------
int getc ( FILE * stream );
int getchar ( void );
char * gets ( char * str );
int putc ( int character, FILE * stream );
int putchar ( int character );
int puts ( const char * str );
int ungetc ( int character, FILE * stream );
//  1.  ungetc退回字符到输入流中
//  2.  getchar读进'\n'，gets不读进'\n'
//  3.  注意以上对于文件末尾int返回值为EOF而非0
