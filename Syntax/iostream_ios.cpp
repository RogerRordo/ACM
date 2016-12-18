//----------------------------------输入----------------------------------
istream& get (char& c);
istream& get (char* s, streamsize n);
istream& get (char* s, streamsize n, char delim);
istream& getline (char* s, streamsize n );
istream& getline (char* s, streamsize n, char delim );
istream& read (char* s, streamsize n);
istream& ignore (streamsize n = 1, int delim = EOF);
int peek();
istream& putback (char c);
streampos tellg();
istream& seekg (streampos pos);
bool eof() const;
//  1.  get保留'/0'，而getline不保留
//  2.  ignore一直忽略字符，直到够n个或遇到delim停止
//  3.  peek偷窥下一个字符
//  4.  streampos要用ll存，e.g.: t=cin.tellg(); ...; cin.seekg(t);
//  5.  while (!cin.eof(...))
//----------------------------------输出----------------------------------
fmtflags setf (fmtflags fmtfl);
void unsetf (fmtflags mask);
streamsize precision (streamsize prec);
//  cout.precision(...); cout<<...;
//  此处为精度，若设置fixed，则为小数点后保留位数
//  对于以下，e.g. cout<<dec<<...;
//  以下三个取消效果为函数名前加no
ios_base& uppercase (ios_base& str);
ios_base& showpos (ios_base& str);
ios_base& showpoint (ios_base& str);
//  以下两个的取消效果，应用cout.unsetf(ios_base::floatfield);
ios_base& scientific (ios_base& str);
ios_base& fixed (ios_base& str);
ios_base& dec (ios_base& str);
ios_base& hex (ios_base& str);
ios_base& oct (ios_base& str);
