#ifndef DISJOINT_SET_BASE_NODE_HPP_
#define DISJOINT_SET_BASE_NODE_HPP_

namespace eda {

namespace disjoint_set {

template <typename T, class Node>
class BaseNode {
public:
	T value_;
	Node *set_;

public:
	BaseNode(T &, Node *);
};

} // disjoint_set

} // eda

#include "impl/base_node.ipp"

#endif // DISJOINT_SET_BASE_NODE_HPP_
