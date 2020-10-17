#ifndef FIBONACCI_HEAP_BASE_FIBONACCI_HEAP_HPP_
#define FIBONACCI_HEAP_BASE_FIBONACCI_HEAP_HPP_

#include "base_node.hpp"

#include <vector>

namespace eda {

namespace fibonacci_heap {

template <typename T, typename Node>
class BaseFibonacciHeap {
protected:
	int size_;
	std::vector<Node *> nodes_;
	Node *min_;

public:
	BaseFibonacciHeap();

	int size();
	bool empty();
	Node *insert(T);
	T get_min();
	void delete_min();
	void decrease_key(Node *, T);
	void print();
	void graph_print();

protected:
	void print(Node *, int);
	void graph_print(Node *, std::string);
	void insert(Node *);
	Node *merge(Node *, Node *);
};

} // namespace fibonacci_heap

} // namespace eda

#include "impl/base_fibonacci_heap.ipp"

#endif // FIBONACCI_HEAP_BASE_FIBONACCI_HEAP_HPP_
