#ifndef DISJOINT_SET_NODE_IPP_
#define DISJOINT_SET_NODE_IPP_

#include "base_node.hpp"

namespace eda {

namespace disjoint_set {

template <typename T>
Node<T>::Node(T &value) :
	BaseNode<T, Node<T> >(value, this)
{ }

} // disjoint_set

} // eda

#endif // DISJOINT_SET_NODE_IPP_
