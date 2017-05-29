#ifndef _INTERVAL_H_
#define _INTERVAL_H_

#include <stdexcept>


/**
 * \brief This class represents half-closed interval [first, last>
 */
class Interval {
public:
    Interval(int first, int size) : first_(first), size_(size) {
        if (size <= 0) {
            throw std::invalid_argument("interval size is not positive integer");
        }
    }

    bool operator==(const Interval& other) const {
        return (first_ == other.first_) && (size_ == other.size_);
    }

    static bool canIntersect(const Interval& interval1, const Interval& interval2) {
        return interval1.contains(interval2.getFirst()) || interval2.contains(interval1.getFirst());
    }

    static Interval createIntersection(const Interval& interval1, const Interval& interval2);

    int getFirst() const {
        return first_;
    }
    int getLast() const {
        return first_ + size_;
    }
    int getSize() const {
        return size_;
    }

    bool contains(int point) const {
        return (getFirst() <= point) && (point < getLast());
    }

private:
    const int first_;
    const int size_;
};

#endif // _INTERVAL_H_
