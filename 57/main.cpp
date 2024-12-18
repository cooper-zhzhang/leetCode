// 712 625 847
// Tags
/*
Companies
给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，其中 intervals[i]
= [starti, endi] 表示第 i 个区间的开始和结束，并且 intervals 按照 starti
升序排列。同样给定一个区间 newInterval = [start, end]
表示另一个区间的开始和结束。

在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti
升序排列，且区间之间不重叠（如果有必要的话，可以合并区间）。

返回插入之后的 intervals。

注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。



示例 1：

输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]
示例 2：

输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval) {
        vector<vector<int>> ret;
        bool push = false;
        for(int i = 0; i < intervals.size(); ++i) {
            auto &first = intervals[i];
            if(std::max(first[0], newInterval[0]) <=
               std::min(first[1], newInterval[1])) {
                newInterval[0] = std::min(first[0], newInterval[0]);
                newInterval[1] = std::max(first[1], newInterval[1]);
            } else {
                if(newInterval[1] < first[0] && !push) {
                    ret.push_back(newInterval);
                    push = true;
                }
                ret.push_back(first);
            }
        }


        if(!push){
            ret.push_back(newInterval);
        }

        return ret;
    }
};

int main() { return 0; }
