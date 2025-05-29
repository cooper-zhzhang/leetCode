#ifndef UTIL_H
#define UTIL_H

#include <climits>
#include <iostream>
#include <list>
#include <vector>
struct Node {
#include <vector>
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
#endif //
