//indexed tree
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using i_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
