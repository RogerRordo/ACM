using namespace __gnu_pbds
//-----------------------------------堆-----------------------------------
#include<ext/pb_ds/priority_queue.hpp>
template<
    typename Value_Type,
    typename Cmp_Fn = std::less<Value_Type>,
    typename Tag = pairing_heap_tag,
    typename Allocator = std::allocator<char> >
class priority_queue;
size_type size () const
bool empty () const
void clear ()
point_iterator push (const_reference r_val)
void pop ()
const_reference top () const
void modify (point_iterator it, const_reference r_new_val)
void erase (point_iterator it)
template<class Pred> size_type erase_if (Pred prd)
void join (priority_queue &other)
template<class Pred> void split (Pred prd, priority_queue &other)
iterator begin ()
const_iterator begin () const
iterator end ()
const_iterator end () const
//  1.  Tag：pairing_heap_tag, binary_heap_tag, binomial_heap_tag, rc_binomial_heap_tag, thin_heap_tag五种。常用前两种，binary_heap只能代替queue里的priority_queue（只push，pop，top等，否则线性），更复杂则采用pairing_heap。
//  2.  注意一定要__gnu_pbds::priority_queue，不然会歧义报错
//  3.  erase_if返回删除个数
//  4.  关于Pred的用例：
//          bool p(int x){return x&1;}
//          a.erase_if(p);
//  5.  join的other会被清空
//-----------------------------------树-----------------------------------
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<
    typename Key,
    typename Mapped,
    typename Cmp_Fn = std::less<Key>,
    typename Tag = rb_tree_tag,
    template<
        typename Const_Node_Iterator,
        typename Node_Iterator,
        typename Cmp_Fn_,
        typename Allocator_>
    class Node_Update = null_tree_node_update,
    typename Allocator = std::allocator<char> >
class tree;
iterator lower_bound (const_key_reference r_key)
const_iterator lower_bound (const_key_reference r_key) const
iterator upper_bound (const_key_reference r_key)
const_iterator upper_bound (const_key_reference r_key) const
iterator erase (iterator it)
reverse_iterator erase (reverse_iterator it)
reverse_iterator rbegin ()
const_reverse_iterator rbegin () const
reverse_iterator rend ()
const_reverse_iterator rend () const
void join (basic_tree &other)
void split (const_key_reference r_key, basic_tree &other)
node_iterator node_begin ()
const_node_iterator node_begin () const
node_iterator node_end ()
const_node_iterator node_end () const
//  1.  Mapped设置为null_type（较旧版本为null_mapped_type）变set，即对iterator加星取值
//  2.  Tag：rb_tree_tag, splay_tree_tag, or ov_tree_tag三种，一般只用rb_tree
//  3.  Node_Update自带有////
//----------------------------------哈希----------------------------------
template<
    typename Key,
    typename Mapped,
    typename Hash_Fn = std::hash<Key>,
    typename Eq_Fn = std::equal_to<Key>,
    typename Comb_Hash_Fn = direct_mask_range_hashing<>
    typename Resize_Policy = default explained below.
     bool Store_Hash = false,
     typename Allocator = std::allocator<char> >
class cc_hash_table;
template<
    typename Key,
    typename Mapped,
    typename Hash_Fn = std::hash<Key>,
    typename Eq_Fn = std::equal_to<Key>,
    typename Comb_Probe_Fn = direct_mask_range_hashing<>
    typename Probe_Fn = default explained below.
    typename Resize_Policy = default explained below.
    bool Store_Hash = false,
    typename Allocator =  std::allocator<char> >
class gp_hash_table;
