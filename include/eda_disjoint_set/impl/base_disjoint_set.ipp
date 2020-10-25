#ifndef DISJOINT_SET_BASE_DISJOINT_SET_IPP_
#define DISJOINT_SET_BASE_DISJOINT_SET_IPP_

#include "base_disjoint_set.hpp"

#include "base_node.hpp"

namespace eda {

namespace disjoint_set {

template <typename T, class Compare, class Node>
void BaseDisjointSet<T, Compare, Node>::insert(T value) {
	if (this->node(value) != nullptr) return;

	Node *node = new Node(value);
	this->nodes_[value] = node;
}

template <typename T, class Compare, class Node>
void BaseDisjointSet<T, Compare, Node>::combine(T value1, T value2) {
	this->combine(this->node(value1), this->node(value2));
}

template <typename T, class Compare, class Node>
bool BaseDisjointSet<T, Compare, Node>::same_set(T value1, T value2) {
	return this->find(this->node(value1)) == this->find(this->node(value2));
}

template <typename T, class Compare, class Node>
Node *BaseDisjointSet<T, Compare, Node>::node(T value) {
	auto elem = this->nodes_.find(value);

	if (elem == this->nodes_.end()) return nullptr;

	return elem->second;
}

template <typename T, class Compare, class Node>
Node *BaseDisjointSet<T, Compare, Node>::find(Node *node) {
	if (node->set_ == node) return node;
	
	return node->set_ = this->find(node->set_);
}

template <typename T, class Compare, class Node>
void BaseDisjointSet<T, Compare, Node>::combine(Node *node1, Node *node2) {
	Node *set1, *set2;

	set1 = this->find(node1);
	set2 = this->find(node2);

	if (set1 == set2) return;

	set1->set_ = set2;
}

} // disjoint_set

} // eda

#endif // DISJOINT_SET_BASE_DISJOINT_SET_IPP_
