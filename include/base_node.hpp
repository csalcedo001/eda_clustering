#ifndef FIBONACCI_HEAP_BASE_NODE_HPP_
#define FIBONACCI_HEAP_BASE_NODE_HPP_

namespace eda {

namespace fibonacci_heap {

template <typename T, typename Node>
class BaseNode {
public:
	std::vector<Node *> children_;
	T value_;
	Node *parent_;
	bool black_; 

public:
	BaseNode();
	BaseNode(T);

	int rank();
};

} // namespace fibonacci_heap

} // namespace eda

#include "impl/base_node.ipp"

#endif // FIBONACCI_HEAP_BASE_NODE_HPP_
