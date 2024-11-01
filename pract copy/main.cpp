#include <iostream>
#include <vector>

void moveVec(std::vector<int> &vec, int k) {

    int count = vec.size();
    if(count == 0 || count == 1) {
        return;
    }

    if(k == 0) {
        return;
    }

    k = k % count;
    std::vector<int> tempVec(count, 0);

    for(int i = 0; i < vec.size(); ++i) {
        tempVec[(i + k) % count] = vec[i];
    }

    vec = tempVec;
}

int main() {

    std::vector<int> vec{1, 2, 3, 4, 5};
    int k = 2;
    k = 6;
    moveVec(vec, k);
    for(auto i : vec) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    return 0;
}