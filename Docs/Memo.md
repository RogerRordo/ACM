#Memo For ACM
***By Roger***

@(其他)

[TOC]

----------
##C++ Syntax
###Containers
####vector
iterator `begin()`;
iterator `end()`;
size_type `size()` const;
reference `operator[]` (size_type n);
reference `front()`;
reference `back()`;
void `push_back (const value_type& val)`;
void `pop_back()`;
iterator `erase (iterator position)`;
iterator `erase (iterator first, iterator last)`;
 *\\\\ [ first, last )*
void `clear()`;
####deque
size_type `size()` const;
reference `front()`;
reference `back()`;
void `push_front (const value_type& val)`;
void `push_back (const value_type& val)`;
void `pop_front()`;
void `pop_back()`;
void `clear()`;
####priority_queue
template &lt;class T, class Container = vector&lt;T&gt;,
  class Compare = less&lt;typename Container::value_type&gt; &gt; class priority_queue;
size_type `size()` const;
const value_type& `top()` const;
void `push (const value_type& val)`;
void `pop()`;
####set
**(similarly in multiset/map/multimap)**
template &lt; class T, class Compare = less&lt;T&gt;, class Alloc = allocator&lt;T&gt; &gt; class set;
iterator `begin()`;
iterator `end()`;
*\\\\The next of the last*
size_type `size()` const;
iterator `find (const value_type& val)` const;
*\\\\Not found->End*
size_type `count (const value_type& val)` const;
*\\\\0 or 1 but in a **multiset/multimap***
iterator `lower_bound (const value_type& val)` const;
iterator `upper_bound (const value_type& val)` const;
*\\\\The least larger than val*
pair<iterator,bool> `insert (const value_type& val)`;
void `erase (iterator position)`;
size_type `erase (const value_type& val)`;
 void `erase (iterator first, iterator last)`;
 *\\\\ [ first, last )*
 void `clear()`;

*\\\\In a **map/multimap**,  at() is only declared in **C++11**, but operator[] can be used in any version.*
###&lt;cstring&gt;
