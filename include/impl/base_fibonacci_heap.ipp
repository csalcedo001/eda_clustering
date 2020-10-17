#ifndef FIBONACCI_HEAP_BASE_FIBONACCI_HEAP_IPP_
#define FIBONACCI_HEAP_BASE_FIBONACCI_HEAP_IPP_

#include "base_fibonacci_heap.hpp"

#include <list>
#include <iostream>
#include <string>

#include "base_node.hpp"

namespace eda {

namespace fibonacci_heap {

template <typename T, typename Node>
BaseFibonacciHeap<T, Node>::BaseFibonacciHeap() :
	size_(0),
	min_(nullptr)
{ }

template <typename T, typename Node>
int BaseFibonacciHeap<T, Node>::size() {
	return this->size_;
}

template <typename T, typename Node>
bool BaseFibonacciHeap<T, Node>::empty() {
	return this->size_ == 0;
}

template <typename T, typename Node>
Node *BaseFibonacciHeap<T, Node>::insert(T value) {
	Node *node = new Node(value);

	this->insert(node);
	this->size_++;

	if (this->min_ == nullptr || node->value_ < this->min_->value_) {
		this->min_ = node;
	}

	return node;
}

template <typename T, typename Node>
T BaseFibonacciHeap<T, Node>::get_min() {
	// TODO: Throw error when size == 0 
	if (this->size_ == 0) return -1;

	return this->min_->value_;
}

template <typename T, typename Node>
void BaseFibonacciHeap<T, Node>::delete_min() {
	// TODO: Throw error if size is 0
	if (this->size_ == 0) return;

	this->size_--;

	Node *node = this->min_;
	this->nodes_[this->min_->rank()] = nullptr;

	for (auto child : node->children_) {
		this->insert(child);
	}

	delete node;


	if (this->size_ == 0) {
		this->min_ = nullptr;
		return;
	}

	int i = 0;
	
	while (i < this->nodes_.size() && this->nodes_[i] == nullptr) {
		i++;
	}

	Node *min_node = this->nodes_[i];

	for ( ; i < this->nodes_.size(); i++) {
		if (this->nodes_[i] != nullptr && this->nodes_[i]->value_ < min_node->value_) {
			min_node = this->nodes_[i];
		}
	}

	this->min_ = min_node;
}

template <typename T, typename Node>
void BaseFibonacciHeap<T, Node>::decrease_key(Node *node, T value) {
	if (value > node->value_) return;

	node->value_ = value;

	while (node->parent_ != nullptr && node->value_ < node->parent_->value_) {
		std::swap(node->value_, node->parent_->value_);
		node = node->parent_;
	}

	if (value < this->min_->value_) {
		this->min_ = node;
	}
}

template <typename T, typename Node>
void BaseFibonacciHeap<T, Node>::print() {
	for (auto e : this->nodes_) {
		if (e != nullptr) {
			this->print(e, 0);
		}
	}
}

template <typename T, typename Node>
void BaseFibonacciHeap<T, Node>::graph_print() {
	long long name_index = 0;

	std::cout << "digraph D {" << std::endl;

	for (auto e : this->nodes_) {
		std::string name = "n";
		name.append(std::to_string(name_index));

		if (e != nullptr) {
			this->graph_print(e, name);
		}

		name_index++;
	}

	std::cout << "}" << std::endl;
}

template <typename T, typename Node>
void BaseFibonacciHeap<T, Node>::print(Node *node, int level) {
	int l = level;

	while (l--) {
		std::cout << "    ";
	}
	std::cout << node->value_ << std::endl;

	for (auto e : node->children_) {
		this->print(e, level + 1);
	}
}

template <typename T, typename Node>
void BaseFibonacciHeap<T, Node>::graph_print(Node *node, std::string name) {
	
	std::cout << "    " << name << " [label=" << node->value_ << "];" << std::endl;
	
	for (int i = 0; i < node->children_.size(); i++) {
		if (node->children_[i] != nullptr) {
			std::string child_name = name;

			child_name.append("_");
			child_name.append(std::to_string(i));

			std::cout << "    " << name << " -> " << child_name << ';' << std::endl;

			this->graph_print(node->children_[i], child_name);
		}
	}
}

template <typename T, typename Node>
void BaseFibonacciHeap<T, Node>::insert(Node *node) {
	node->parent_ = nullptr;

	if (node->rank() > this->nodes_.size()) {
		this->nodes_.resize(node->rank(), nullptr);
	}

	int i = node->rank();
	
	while (i < this->nodes_.size() && this->nodes_[i] != nullptr) {
		node = this->merge(this->nodes_[i], node);
		this->nodes_[i] = nullptr;

		i++;
	}

	if (i == this->nodes_.size()) {
		this->nodes_.push_back(node);
	}
	else {
		this->nodes_[i] = node;
	}
}

template <typename T, typename Node>
Node *BaseFibonacciHeap<T, Node>::merge(Node *node1, Node *node2) {
	if (node1->value_ < node2->value_) {
		node1->children_.push_back(node2);
		node2->parent_ = node1;

		return node1;
	}
	else {
		node2->children_.push_back(node1);
		node1->parent_ = node2;

		return node2;
	}
}

} // namespace fibonacci_heap

} // namespace eda

#endif // FIBONACCI_TREE_FIBONACCI_HEAP_IPP_
