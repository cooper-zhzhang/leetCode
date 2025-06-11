/*240. 搜索二维矩阵 II - 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。

 

示例 1：

[https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/11/25/searchgrid2.jpg]


输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
输出：true


示例 2：

[https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/11/25/searchgrid.jpg]


输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
输出：false


 

提示：

 * m == matrix.length
 * n == matrix[i].length
 * 1 <= n, m <= 300
 * -109 <= matrix[i][j] <= 109
 * 每行的所有元素从左到右升序排列
 * 每列的所有元素从上到下升序排列
 * -109 <= target <= 109
https://leetcode.cn/problems/search-a-2d-matrix-ii
*/
/*
 *240. 搜索二维矩阵 II
中等
相关标签
相关企业

编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target
。该矩阵具有以下特性：

    每行的元素从左到右升序排列。
    每列的元素从上到下升序排列。
示例 1：

输入：matrix =
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
target = 5 输出：true

示例 2：

输入：matrix =
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
target = 20 输出：false
 * */

#include <csignal>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target, int lowRow,
                      int lowCol, int higRow, int higCol) {

        return false;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target, int row,
                      int col) {
        // choose new row col index
        int newRow = row - 1; // TODO:
        if(newRow < 0) {
            newRow = 0;
        }
        int newCol = col - 1;
        if(newCol < 0) {
            newCol = 0;
        }
        if(matrix[newRow][newCol] == target) {
            return true;
        }
        // if(newRow == 0 && newCol == 0) {
        //     return false;
        // }
        //
        // if((newCol == 0 || newRow == 0) && (col == 0 || row == 0)) {
        // }

        if(matrix[newRow][newCol] > target) {
            if(newRow == 0 && newCol == 0) {
                return false;
            }
            return searchMatrix(matrix, target, newRow, newCol);
        }

        for(int i = 0; i <= row; ++i) {
            if(matrix[i][col] == target) {
                return true;
            }
        }

        for(int i = 0; i <= col; ++i) {
            if(matrix[row][i] == target) {
                return true;
            }
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target) {

        int row = matrix.size();
        if(row == 0) {
            return false;
        }
        int col = matrix[0].size();
        if(col == 0) {
            return false;
        }
        if(matrix[row - 1][col - 1] == target) {
            return true;
        }
        if(matrix[row - 1][col - 1] < target) {
            return false;
        }
        return searchMatrix(matrix, target, row - 1, col - 1);
    }
};
int main() {

    // vector<vector<int>> nums{{1, 4, 7, 11, 15},
    //                          {2, 5, 8, 12, 19},
    //                          {3, 6, 9, 16, 22},
    //                          {10, 13, 14, 17, 24},
    //                          {18, 21, 23, 26, 30}};
    vector<vector<int>> nums{{1, 4}, {2, 5}};
    int target = 2;
    std::cout << Solution().searchMatrix(nums, target) << std::endl;

    return 0;
}
