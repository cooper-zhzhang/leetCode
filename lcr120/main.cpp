/*LCR 120. 寻找文件副本 - 设备中存有 n 个文件，文件 id 记于数组 documents。若文件 id 相同，则定义为该文件存在副本。请返回任一存在副本的文件 id。

 

示例 1：


输入：documents = [2, 5, 3, 0, 5, 0]
输出：0 或 5


 

提示：

 * 0 ≤ documents[i] ≤ n-1
 * 2 <= n <= 100000

 
https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
*/
// 712 625 847
#include <vector>
#include <iostream>

using namespace std;



class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
		int flag = -1;
		int i = 0;
		for(;i<documents.size();){
			int index = documents[i];
			if(index == i){
				// 在就本身的位置上 不做处理
				++i;
				continue;
			}

			if(documents[index] == documents[i]){
				// 找到相同的了 
				return documents[index];
			}

			swap(documents[i], documents[index]);
		}

		return flag;
    }
};

int main() { 
	

	vector<int>vec{2, 5, 3, 0, 5, 0};
	
	std::cout <<	Solution().findRepeatDocument(vec) << std::endl;


	return 0; 
}
