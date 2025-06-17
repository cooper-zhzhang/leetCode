#ifndef UTIL_H
#define UTIL_H

#include <climits>
#include <iostream>
#include <list>
#include <vector>
struct Node {
    Node(int value) {
        this->value = value;
        this->l = nullptr;
        this->r = nullptr;
    }
    Node *l;
    Node *r;
    int value;
};

void displayTree(Node *root) {
    std::list<Node *> nodeList;
    nodeList.push_back(root);

    while(!nodeList.empty()) {
        Node *temp = nodeList.front();
        nodeList.pop_front();
        if(temp == nullptr) {
            return;
        }

        std::cout << temp->value << " ";

        if(temp->l != nullptr) {
            nodeList.push_back(temp->l);
        }

        if(temp->r != nullptr) {
            nodeList.push_back(temp->r);
        }
    }
}

Node *createTree(const std::vector<int> &vec) {
    if(vec.size() == 0) {
        return nullptr;
    }

    Node *root;
    int i = 0;
    std::list<Node *> nodeList;
    Node *temp = new Node(vec[0]);
    nodeList.push_back(temp);
    root = temp;
    for(; i < vec.size(); ++i) {
        Node *curNode = nodeList.front();
        nodeList.pop_front();
        if(curNode == nullptr) {
            continue;
        }
        int lIndex = i * 2 + 1;
        int rIndex = i * 2 + 2;

        if(lIndex < vec.size()) {
            Node *lNode = nullptr;
            if(vec[lIndex] != INT_MAX) {
                lNode = new Node(vec[lIndex]);
                curNode->l = lNode;
            }
            nodeList.push_back(lNode);
        }

        if(rIndex < vec.size()) {
            Node *rNode = nullptr;
            if(vec[rIndex] != INT_MAX) {
                rNode = new Node(vec[rIndex]);
                curNode->r = rNode;
            }
            nodeList.push_back(rNode);
        }

        if(lIndex >= vec.size() || rIndex >= vec.size()) {
            break;
        }
    }

    return root;
}
// 主模板
template <size_t N> struct Fibonacci {
    static constexpr unsigned long long value =
        Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

// 特化模板 - 基本情况
template <> struct Fibonacci<0> {
    static constexpr unsigned long long value = 0;
};

template <> struct Fibonacci<1> {
    static constexpr unsigned long long value = 1;
};

// 生成斐波那契查询表的辅助模板
template <size_t... Is>
constexpr auto make_fibonacci_table(std::index_sequence<Is...>) {
    return std::array<unsigned long long, sizeof...(Is)>{
        Fibonacci<Is>::value...};
}

// 生成斐波那契查询表
template <size_t N> constexpr auto generate_fibonacci_table() {
    return make_fibonacci_table(std::make_index_sequence<N>{});
}

constexpr auto fib_table = generate_fibonacci_table<50>();
#endif //
