#include<ext/rope>  
using namespace __gnu_cxx;
//+ = += [] < > == !=都可用，cout输出
rope(const charT* s)
rope(const charT* s, size_t n)
void swap(rope& x)
size_type size() const
size_type length() const
bool empty() const
void push_back(charT)
void insert(size_t i, const rope& x)	//BEFORE the ith element
void insert(size_t i, charT c)
void insert(size_t i, const charT* s)
void erase(const iterator& p)
void erase(size_t i, size_t n)	//[i,i+n-1]
void replace(size_t i, size_t n, const rope& x)
void replace(size_t i, charT c)
void replace(size_t i, size_t n, const charT* s)
rope substr(size_t i, size_t n = 1) const
const charT* c_str() const
