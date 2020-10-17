#ifndef FIBONACCI_HEAP_FIBONACCI_HEAP_HPP_
#define FIBONACCI_HEAP_FIBONACCI_HEAP_HPP_

#include <vector>

#include "node.hpp"
#include "base_fibonacci_heap.hpp"

namespace eda {

namespace fibonacci_heap {

template <typename T>
class FibonacciHeap : public BaseFibonacciHeap<T, Node<T> > { };

} // namespace fibonacci_heap

} // namespace eda

#endif // FIBONACCI_HEAP_FIBONACCI_HEAP_HPP_
