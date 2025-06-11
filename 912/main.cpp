/*912. 排序数组 - 给你一个整数数组 nums，请你将该数组升序排列。

你必须在 不使用任何内置函数 的情况下解决问题，时间复杂度为 O(nlog(n))，并且空间复杂度尽可能小。

 

示例 1：


输入：nums = [5,2,3,1]
输出：[1,2,3,5]


示例 2：


输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]


 

提示：

 * 1 <= nums.length <= 5 * 104
 * -5 * 104 <= nums[i] <= 5 * 104
https://leetcode.cn/problems/sort-an-array
*/
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> sortArray(vector<int> &nums) {
        QuickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    int Partition(vector<int> &arr, int left, int right) {

        if(arr.size() > 100) {
            int index = rand() % (right - left + 1) + left;
            swap(arr[index], arr[right]);
        }

        int temp = arr[right];
        int i = left - 1;

        for(int j = left; j <= right - 1; j++) {
            if(arr[j] < temp) {
                i++;
                // i 标记大的数字
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[right], arr[i + 1]); //!!!note: can't use temp:local variable
        return i + 1;
    }

    void QuickSort(vector<int> &arr, int left, int right) {
        if(left < right) {
            int mid = Partition(arr, left, right);
            QuickSort(arr, left, mid - 1);
            QuickSort(arr, mid + 1, right);
        }
    }
};

class Solution1 {
  public:
    vector<int> sortArray(vector<int> &nums) {
        QuickSortBase(nums, 0, nums.size() - 1);

        return nums;
    }

    void Swap(int &v1, int &v2) {
        int tmp = v1;
        v1 = v2;
        v2 = tmp;
    }

    int PartitionBase(vector<int> &arr, int left, int right) {

        int temp = arr[right];
        int i = left - 1;

        for(int j = left; j <= right - 1; j++) {
            if(arr[j] <= temp) { //有大量重复的数据时 会造成不必要的移动
                                 //优化方向是写成三段
                // 小于temp的 等于 temp的 和大于temp的
                i++;
                // i 标记大的数字
                Swap(arr[i], arr[j]);
            }
        }

        Swap(arr[right], arr[i + 1]); //!!!note: can't use temp:local variable
        return i + 1;
    }

    void QuickSortBase(vector<int> &arr, int left, int right) {
        if(left < right) {
            int mid = PartitionBase(arr, left, right);
            QuickSortBase(arr, left, mid - 1);
            QuickSortBase(arr, mid + 1, right);
        }
    }

    // 添加随机选取
    /*
    如果有大量的重复数据 会造成n^2
    */
    int PartitionRand(vector<int> &arr, int left, int right) {
        int index = rand() % (right - left + 1) + left;
        Swap(arr[index], arr[right]);

        int temp = arr[right];
        int i = left - 1;

        for(int j = left; j <= right - 1; j++) {
            if(arr[j] <= temp) { //有大量重复的数据时 会造成不必要的移动
                                 //优化方向是写成三段
                // 小于temp的 等于 temp的 和大于temp的
                i++;
                // i 标记大的数字
                Swap(arr[i], arr[j]);
            }
        }

        Swap(arr[right], arr[i + 1]); //!!!note: can't use temp:local variable
        return i + 1;
    }

    void quicksortThreePartition(int *nums, int left, int right) {
        if(left >= right)
            return;

        // int j = new Random().nextInt(right - left + 1) + left;
        int j = right;
        int pivot = nums[j];
        int less = left, great = right, i = left;
        // 需要保证
        // 1、[left,less-1] < pivot
        // 2、[less,i] == pivot
        // 3、[i,great] 未处理区域
        // 4、[great+1,right] > pivot
        while(i <= great) {
            if(nums[i] < pivot) {
                std::swap(nums[i], nums[less]);
                less++;
                i++;
            } else if(nums[i] > pivot) {
                std::swap(nums[i], nums[great]);
                great--;
            } else {
                i++;
            }
        }
        quicksortThreePartition(nums, left, less - 1);
        quicksortThreePartition(nums, great + 1, right);
    }

    void swap_(int nums[], int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void PartitionThree(vector<int> &arr, int left, int right) {
        // 最佳
        // best

        if(left >= right) {
            return;
        }

        int pivot = arr[rand() % (right - left + 1) + left];

        // i：当前操作的元素下标
        // arr[0, j)：存储小于 pivot 的元素
        // arr[k, len)：存储大于 pivot 的元素
        int i = left, j = left, k = right + 1;
        // 完成一趟三路快排，将序列分为：
        // 小于 pivot 的元素 arr[j]==pivot | 等于 pivot 的元素 | 大于 pivot
        // 的元素
        // [i, k) 需要处理的元素
        while(i < k) {
            if(arr[i] < pivot) {
                swap(arr[i], arr[j]);
                i++;
                j++;
            } else if(arr[i] > pivot) {
                --k;
                swap(arr[i], arr[k]);
            } else
                i++;
        }
        // 递归完成对于两个子序列的快速排序
        PartitionThree(arr, left, j - 1);
        PartitionThree(arr, k, right);
    }
};

int main() {
    // vector<int> vec{2, 6, 57, 88,
    // 60, 42, 83, 73, 85, 48};
    // Solution().sortArray(vec);

    vector<int> vec{5, 2, 3, 1};

    // Solution().QuickSort(vec, 0, vec.size() - 1);
    // Solution1().quicksort111(vec.data(), 0, vec.size() - 1);
    Solution1().PartitionThree(vec, 0, vec.size() - 1);

    for(auto &i : vec) {
        std::cout << i << " " << std::endl;
    }

    return 0;
}
