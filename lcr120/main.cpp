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
