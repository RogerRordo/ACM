//注意很多时候iterator表区间首末时为左闭右开区间
//---------------------------------vector---------------------------------
iterator begin();
iterator end();
size_type size() const;
reference operator[] (size_type n);
reference front();
reference back();
void push_back (const value_type& val);
void pop_back();
iterator erase (iterator position);
iterator erase (iterator first, iterator last);
void clear();
//sort(v.begin(),v.end());可以实现排序
//----------------------------------queue----------------------------------
size_type size() const;
value_type& front();
void push (const value_type& val);
void pop();
//----------------------------------deque----------------------------------
size_type size() const;
reference front();
reference back();
void push_front (const value_type& val);
void push_back (const value_type& val);
void pop_front();
void pop_back();
void clear();
priority_queue
template <class T, class Container = vector<T>, class Compare = less<typename Container::value_type> > class priority_queue;
//默认Compare=less，即为大根堆
size_type size() const;
const value_type& top() const;
void push (const value_type& val);
void pop();
//-----------------------------------set-----------------------------------
// /multiset/map/multimap 类似
template < class T, class Compare = less<T>, class Alloc = allocator<T> > class set;
iterator begin();
iterator end();
//end是最后元素的下一个，即空
size_type size() const;
iterator find (const value_type& val) const;
//找不到返回end()
size_type count (const value_type& val) const;
//0/1，除非是 multiset/multimap
iterator lower_bound (const value_type& val) const;
//大于等于val的最小一个
iterator upper_bound (const value_type& val) const;
pair insert (const value_type& val);
void erase (iterator position);
size_type erase (const value_type& val);
void erase (iterator first, iterator last);
void clear();
//在 map/multimap里，at()只定义在 C++11，但operator[]任用
//------------------------------unordered_set------------------------------
// 仅C++11! iterator被认为无太大意义而舍去 template < class Key, class Hash = hash<Key>, class Pred = equal_to<Key>, class Alloc = allocator<Key> > class unordered_set;
size_type size() const noexcept;
iterator find ( const key_type& k );
size_type count ( const key_type& k ) const;
//0/1
pair insert ( const value_type& val );
size_type erase ( const key_type& k );
void clear() noexcept;
size_type bucket_count() const noexcept;
float load_factor() const noexcept;
float max_load_factor() const noexcept;
void max_load_factor ( float z );
void rehash ( size_type n );
