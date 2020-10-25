#ifndef DISJOINT_SET_BASE_DISJOINT_SET_HPP_
#define DISJOINT_SET_BASE_DISJOINT_SET_HPP_

#include <map>

#include "base_node.hpp"

namespace eda {

namespace disjoint_set {

template <typename T, class Compare, class Node>
class BaseDisjointSet {
protected:
	std::map<T, Node *, Compare> nodes_;
	Compare comp_;

public:
	void insert(T);
	void combine(T, T);
	bool same_set(T, T);

protected:
	Node *node(T);
	Node *find(Node *);
	void combine(Node *, Node *);
};

} // disjoint_set

} // eda

#include "impl/base_disjoint_set.ipp"

#endif // DISJOINT_SET_BASE_DISJOINT_SET_HPP_
