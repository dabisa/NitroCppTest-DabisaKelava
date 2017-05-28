#ifndef _INTERSECTION_TREE_H_
#define _INTERSECTION_TREE_H_

#include <functional>
#include <list>

#include "rectangle.h"


/**
 * \brief This class is used to calculate all possible intersections of given set of rectangles
 */
class IntersectionTree {

public:
    using NodeVisitor = std::function<void (const std::vector<unsigned>& ids, const Rectangle& rect)>;

    /**
     * \brief Generates IntersectionTree object from a given vector of rectangles
     */
    static IntersectionTree generate(const std::vector<Rectangle>& rectangles);

    /**
     * \brief Visits every node in a tree using level order traversal.
     */
    void visitInLevelOrder(const NodeVisitor&) const;

private:
    /**
     * \brief This class represents node in a tree.
     */
    class Node {

    public:
        /**
         * \brief Creates dummy root node. Rectangle in this node is not used.
         */
        Node() : id_(0), rect_(Rectangle(0,0,1,1)) {}

        Node(unsigned id, const Rectangle& rect) : id_(id), rect_(rect) {}

        unsigned getId() const {
            return id_;
        }

        bool canCreateChild(const Rectangle& rect) {
            return getId() == 0 || Rectangle::canIntersect(rect_, rect);
        }

        Node& createChild(unsigned id, const Rectangle& rect) {
            children_.push_back(Node(id, generateIntersection(rect)));
            return children_.back();
        }

        unsigned depth() const {
            return children_.size() > 0 ? children_.front().depth() + 1 : 1;
        }

        /**
         * \brief visits all nodes ant given depth
         */
        void visitDepth(unsigned depth, std::vector<unsigned>& ids, const NodeVisitor& visitor) const;

    private:
        Rectangle generateIntersection(const Rectangle& rect) const {
            // Node with id == 0 is dummy node. We do not compute intersection
            return (getId() == 0) ? rect : Rectangle::createIntersection(rect_, rect);
        }

        unsigned id_;
        Rectangle rect_;
        std::list<Node> children_;
    };

    IntersectionTree(Node&& root) : root_(root) {}

    const Node root_;
};

#endif // _INTERSECTION_TREE_H_