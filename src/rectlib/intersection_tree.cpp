#include <functional>
#include <vector>

#include "intersection_tree.h"
#include "rectangle.h"


IntersectionTree IntersectionTree::generate(const std::vector<Rectangle>& rectangles) {

    std::function<void(Node&)> generate_recursive;
    generate_recursive = [&generate_recursive, &rectangles] (Node& node) {

        for(unsigned i = node.getId(); i < rectangles.size(); ++i) {
            if(node.canCreateChild(rectangles[i])) {
                Node& child_node = node.createChild(i+1, rectangles[i]);
                generate_recursive(child_node);
            }
        }
    };

    Node root; //dummy root node
    generate_recursive(root);
    return IntersectionTree(std::move(root));
}

void IntersectionTree::visitInLevelOrder(const NodeVisitor& visitor) const {

    unsigned tree_depth = root_.depth();
    std::vector<unsigned> id_set;
    for(unsigned level = 1; level <= tree_depth; ++level) {
        root_.visitDepth(level, id_set, visitor);
    }
}

void IntersectionTree::Node::visitDepth(unsigned depth, std::vector<unsigned>& ids, const NodeVisitor& visitor) const {

    if(depth == 0) {
        visitor(ids, rect_);
    } else {
        for(const Node& childNode : children_) {
            ids.push_back(childNode.getId() - 1);
            childNode.visitDepth(depth - 1, ids, visitor);
            ids.pop_back();
        }
    }
}
