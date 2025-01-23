#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_LEN 10
struct Tire {
    int num;
    Tire *nextList[MAX_LEN];
    bool endNode;
    Tire() { endNode = false; }

    ~Tire() {
        for(int i = 0; i < MAX_LEN; ++i) {
            if(nextList[i]) {
                delete nextList[i];
            }
        }
    }

    Tire *CreateNext(int num) {
        Tire *ptr = new Tire();
        ptr->num = num;
        return ptr;
    }

    void insert(vector<int> &nums, int index) {
        if(index >= nums.size()) {
            this->endNode = true;
            return;
        }
        int num = nums[index];
        auto ptr = nextList[num];
        if(ptr == nullptr) {
            ptr = CreateNext(num);
            nextList[num] = ptr;
        }
        ptr->insert(nums, index + 1);
    }
    void display(string str) {
        // deep search
        if(this->endNode) {
            std::cout << str << std::endl;
        }
        bool isNull = true;
        for(size_t i = 0; i < MAX_LEN; i++) {
            auto ptr = nextList[i];
            if(ptr != nullptr) {
                isNull = false;
                ptr->display(str + to_string(ptr->num));
            }
        }

        if(isNull && !endNode) {
            std::cout << str << std::endl;
        }
    }
};

int main() {
    auto root = new Tire();
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    root->insert(nums, 0);
    vector<int> nums1{1, 2, 3, 5, 5, 6, 7};
    root->insert(nums1, 0);
    vector<int> nums2{1, 2, 3, 5};
    root->insert(nums2, 0);
    root->display("");

    return 0;
}
