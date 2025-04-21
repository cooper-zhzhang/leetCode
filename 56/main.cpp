
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