#ifndef DISJOINT_SET_NODE_HPP_
#define DISJOINT_SET_NODE_HPP_

#include "node.hpp"

#include "base_node.hpp"

namespace eda {

namespace disjoint_set {

template <typename T>
class Node : public BaseNode<T, Node<T> > {
public:
	Node(T &);
};

} // disjoint_set

} // eda

#include "impl/node.ipp"

#endif // DISJOINT_SET_NODE_HPP_
