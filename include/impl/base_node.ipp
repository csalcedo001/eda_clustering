#ifndef FIBONACCI_HEAP_BASE_NODE_IPP_
#define FIBONACCI_HEAP_BASE_NODE_IPP_

#include "base_node.hpp"

namespace eda {

namespace fibonacci_heap {

template <typename T, typename Node>
BaseNode<T, Node>::BaseNode() :
	children_(),
	parent_(nullptr)
{ }

template <typename T, typename Node>
BaseNode<T, Node>::BaseNode(T value) :
	children_(),
	parent_(nullptr),
	value_(value)
{ }

template <typename T, typename Node>
int BaseNode<T, Node>::rank() {
	return this->children_.size();
}

} // namespace fibonacci_heap

} // namespace eda

#endif // FIBONACCI_HEAP_BASE_NODE_IPP_
