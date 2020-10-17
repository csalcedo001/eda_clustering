#ifndef FIBONACCI_HEAP_NODE_IPP_
#define FIBONACCI_HEAP_NODE_IPP_

#include "node.hpp"

#include "base_node.hpp"

namespace eda {

namespace fibonacci_heap {

template <typename T>
Node<T>::Node() : BaseNode<T, Node<T> >::BaseNode() { }

template <typename T>
Node<T>::Node(T value) : BaseNode<T, Node<T> >::BaseNode(value){ }

} // namespace fibonacci_heap

} // namespace eda

#endif // FIBONACCI_HEAP_NODE_IPP_
