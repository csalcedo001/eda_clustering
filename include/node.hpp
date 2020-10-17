#ifndef FIBONACCI_HEAP_NODE_HPP_
#define FIBONACCI_HEAP_NODE_HPP_

#include <vector>

#include "base_node.hpp"

namespace eda {

namespace fibonacci_heap {

template <typename T>
class Node : public BaseNode<T, Node<T> > {
public:
	Node();
	Node(T);
};

} // namespace fibonacci_heap

} // namespace eda

#include "impl/node.hpp"

#endif // FIBONACCI_HEAP_NODE_HPP_
