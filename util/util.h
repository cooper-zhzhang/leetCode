#ifndef UTIL_H
#define UTIL_H

#include <climits>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
#include <set>
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





int main_reverse() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::reverse(vec.begin(), vec.end());

    for(int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

int main_sort() {

    struct Person {
        int no;
        int age;
        bool operator<(const Person &p) { return age < p.age; }

        bool operator>(const Person& other) const {
            return age > other.age; // 按年龄降序排序
        }
    };


    std::vector<Person> people = {{1, 30}, {2, 25}, {3, 35}, {4, 20}};

    std::sort(people.begin(), people.end(), [](const Person &l, const Person &r){
        return l.age < r.age;
    });

    std::sort(people.begin(), people.end(), std::greater<Person>());

    for(Person &i : people) {
        std::cout << i.no << " " << i.age << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> vec = {5, 2, 9, 1, 5, 6};
    std::sort(vec.begin(), vec.end());

    std::sort(vec.begin(), vec.end(), std::greater<int>());

    for(int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

int reverse_copy_main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> reversed_vec(vec.size());

    std::reverse_copy(vec.begin(), vec.end(), reversed_vec.begin());

    for(int i : reversed_vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::reverse_copy(vec.begin(), vec.end(), reversed_vec.rbegin());

    for(int i : reversed_vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

int unique_main() {
    std::vector<int> vec = {1, 2, 2, 3, 3, 3, 4, 5, 5};
    auto last = std::unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());

    for(int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

int remove_if_main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    auto last = std::remove_if(vec.begin(), vec.end(),
                               [](int x) { return x % 2 == 0; });
    vec.erase(last, vec.end());

    for(int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

int copy_main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> copied_vec(vec.size());
    std::set<int> mySet;

    std::copy(vec.begin(), vec.end(), std::inserter(mySet, mySet.begin()));
    std::copy(vec.begin(), vec.end(), copied_vec.begin());

    for(int i : copied_vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for(int i : mySet) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

int transform_main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> transformed_vec(vec.size());

    std::transform(vec.begin(), vec.end(), transformed_vec.begin(),
                   [](int x) { return x * x; });

    for(int i : transformed_vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

int find_if_main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = std::find_if(vec.begin(), vec.end(), [](int x) { return x > 3; });

    if(it != vec.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}

int count_if_main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    int count =
        std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });

    std::cout << "Count of even numbers: " << count << std::endl;

    return 0;
}

int for_each_main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::for_each(vec.begin(), vec.end(), [](int &x) {
        std::cout << x << " ";
        x++;
    });
    std::cout << std::endl;

    std::for_each(vec.begin(), vec.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;

    return 0;
}

#endif //
