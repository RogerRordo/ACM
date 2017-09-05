//  string的+, =, +=, ==, !=, <, <=, >, >=都对cstring, char, string支持
//----------------------------------迭代器----------------------------------
      iterator begin();
const_iterator begin() const;
      iterator end();
const_iterator end() const;
      reverse_iterator rbegin();
const_reverse_iterator rbegin() const;
      reverse_iterator rend() noexcept;
const_reverse_iterator rend() const noexcept;
//  1.  get保留'/0'，而getline不保留
//-----------------------------------长度-----------------------------------
size_t size() const;
bool empty() const;
void resize (size_t n);
void resize (size_t n, char c);
void clear();
//  1.  resize时若n大于原长，c指定则用c填充尾部至n，否则填充'\0'
//-----------------------------------修改-----------------------------------
string& append (const string& str);
string& append (const string& str, size_t subpos, size_t sublen);
string& append (const char* s);
string& append (const char* s, size_t n);
string& append (size_t n, char c);
template <class InputIterator>
    string& append (InputIterator first, InputIterator last);

string& assign (const string& str);
string& assign (const string& str, size_t subpos, size_t sublen);
string& assign (const char* s);
string& assign (const char* s, size_t n);
string& assign (size_t n, char c);
template <class InputIterator>
   string& assign (InputIterator first, InputIterator last);

string& insert (size_t pos, const string& str);
string& insert (size_t pos, const string& str, size_t subpos, size_t sublen);
string& insert (size_t pos, const char* s);
string& insert (size_t pos, const char* s, size_t n);
string& insert (size_t pos, size_t n, char c);
void insert (iterator p, size_t n, char c);
iterator insert (iterator p, char c);
template <class InputIterator>
   void insert (iterator p, InputIterator first, InputIterator last);

string& erase (size_t pos = 0, size_t len = npos);
iterator erase (iterator p);
iterator erase (iterator first, iterator last);

string& replace (size_t pos,  size_t len,  const string& str);
string& replace (iterator i1, iterator i2, const string& str);
string& replace (size_t pos,  size_t len,  const string& str,
                 size_t subpos, size_t sublen);
string& replace (size_t pos,  size_t len,  const char* s);
string& replace (iterator i1, iterator i2, const char* s);
string& replace (size_t pos,  size_t len,  const char* s, size_t n);
string& replace (iterator i1, iterator i2, const char* s, size_t n);
string& replace (size_t pos,  size_t len,  size_t n, char c);
string& replace (iterator i1, iterator i2, size_t n, char c);
template <class InputIterator>
  string& replace (iterator i1, iterator i2,
                   InputIterator first, InputIterator last);

void swap (string& str);
//-----------------------------------查询-----------------------------------
const char* c_str() const;
const char* data() const;
//c_str()后有'\0'而data()没有，但data()效率更高
//以下找不到返回string::npos
size_t find (const string& str, size_t pos = 0) const;
size_t find (const char* s, size_t pos = 0) const;
size_t find (const char* s, size_t pos, size_t n) const;
size_t find (char c, size_t pos = 0) const;
//rfind只找pos开始或pos之前开始的
size_t rfind (const string& str, size_t pos = npos) const;
size_t rfind (const char* s, size_t pos = npos) const;
size_t rfind (const char* s, size_t pos, size_t n) const;
size_t rfind (char c, size_t pos = npos) const;
size_t find_first_of (const string& str, size_t pos = 0) const;
size_t find_first_of (const char* s, size_t pos = 0) const;
size_t find_first_of (const char* s, size_t pos, size_t n) const;
size_t find_first_of (char c, size_t pos = 0) const;
size_t find_last_of (const string& str, size_t pos = npos) const;
size_t find_last_of (const char* s, size_t pos = npos) const;
size_t find_last_of (const char* s, size_t pos, size_t n) const;
size_t find_last_of (char c, size_t pos = npos) const;
size_t copy (char* s, size_t len, size_t pos = 0) const;
string substr (size_t pos = 0, size_t len = npos) const;
