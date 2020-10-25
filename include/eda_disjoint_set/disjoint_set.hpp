#ifndef DISJOINT_SET_DISJOINT_SET_HPP_
#define DISJOINT_SET_DISJOINT_SET_HPP_

#include "base_disjoint_set.hpp"
#include "node.hpp"

namespace eda {

namespace disjoint_set {

template <typename T, class Compare = std::greater<T> >
class DisjointSet : public BaseDisjointSet<T, Compare, Node<T> > {

};

} // disjoint_set

} // eda

#endif // DISJOINT_SET_DISJOINT_SET_HPP_
