/*56. 合并区间 - 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

 

示例 1：


输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].


示例 2：


输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。

 

提示：

 * 1 <= intervals.length <= 104
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 104
https://leetcode.cn/problems/merge-intervals
*/

#include <algorithm>
#include <vector>


using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
        {
            return intervals;
        }

        vector<vector<int>> result;
        std::sort(intervals.begin(), intervals.end(), [](vector<int> &it1, vector<int> &it2) { return it1[0] < it2[0]; });

        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            vector<int> &curData = intervals[i];
            vector<int> &data = *(result.rbegin());
            //vector<int> &data = result[result.size() - 1];

            if (data[1] < curData[0])
            {// 不相交
                result.push_back(curData);
                continue;
            }
            
            data[1] = data[1] > curData[1] ? data[1] : curData[1];
        }
        
        return result;
    }
};

int main(){

    return 0;
}