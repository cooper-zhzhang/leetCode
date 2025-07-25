/*LCR 118. 冗余连接 - 树可以看成是一个连通且 无环 的 无向 图。

给定往一棵 n 个节点 (节点值 1～n)
的树中添加一条边后的图。添加的边的两个顶点包含在 1 到
n 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组
edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。

请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n
个节点的树。如果有多个答案，则返回数组 edges 中最后出现的边。

 

示例 1：

[https://pic.leetcode-cn.com/1626676174-hOEVUL-image.png]


输入: edges = [[1,2],[1,3],[2,3]]
输出: [2,3]


示例 2：

[https://pic.leetcode-cn.com/1626676179-kGxcmu-image.png]


输入: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
输出: [1,4]


 

提示:

 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ai < bi <= edges.length
 * ai != bi
 * edges 中无重复元素
 * 给定的图是连通的 

 

注意：本题与主站
684 题相同： https://leetcode-cn.com/problems/redundant-connection/
[https://leetcode-cn.com/problems/redundant-connection/]


https://leetcode.cn/problems/7LpjUW
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

    unordered_map<int, int> checkMap;
    int checkValue(int value) {
        while(1) {
            auto it = checkMap.find(value);
            if(it == checkMap.end() || it->second == value) {
                return value;
            }

            value = it->second;
        }
    }

    void insert(int v1, int v2) { checkMap[v1] = v2; }

  public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {

        for(auto &edge : edges) {

            int v1 = checkValue(edge[0]);
            int v2 = checkValue(edge[1]);

            if(v1 == v2) {
                return edge;
            }

            if(v1 == edge[0]) {
                insert(v1, v1);
            }

            if(v2 == edge[1]) {
                insert(v2, v2);
            }

            insert(v1, v2);
        }

        return {};
    }
};

int main() {

    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};

    auto ret = Solution().findRedundantConnection(edges);

    for(auto v : ret) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}