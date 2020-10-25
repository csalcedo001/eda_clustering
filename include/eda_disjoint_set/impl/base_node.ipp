#ifndef DISJOINT_SET_BASE_NODE_IPP_
#define DISJOINT_SET_BASE_NODE_IPP_

#include "base_node.hpp"

namespace eda {

namespace disjoint_set {

template <typename T, class Node>
BaseNode<T, Node>::BaseNode(T &value, Node *set) :
	value_(value),
	set_(set)
{ }

} // disjoint_set

} // eda

#endif // DISJOINT_SET_BASE_NODE_IPP_
