//支持[]和位运算，第0位对应数字最低位/字符串最右
bitset (unsigned long val);
bitset (char *str, size_type pos = 0, size_type n = npos);
bitset (string str, size_type pos = 0, size_type n = npos);
size_t size() const;
size_t count() const;	//1的个数
bitset& reset();	//清0
unsigned long to_ulong() const;
