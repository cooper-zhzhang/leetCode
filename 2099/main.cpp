// 712 625 847
class Solution {
  public:
    int comp(std::pair<int, int> &v1, std::pair<int, int> &v2) {
        if(v1.second < v2.second) {
            return -1;
        }

        if(v1.second > v2.second) {
            return 1;
        }

		if (v1.first < v2.first){
			return -1;
		}
		
		return 1;
    }

    int findMaxK(std::vector<std::pair<int, int>> &vec, int l, int r,
                 int targetK) {

        int i = l;
        int j = l;
        int k = r + 1;

        std::pair<int, int> midValue = vec[i];

        for(; i < k;) {
            int compRet = comp(vec[i], midValue);
            if(compRet == -1) {
                // 小于midvalue
                std::swap(vec[i], vec[j]);
                i++;
                j++;
            } else if(compRet == 0) {
                //==
                i++;
            } else {
                // > midValue
                k--;
                std::swap(vec[i], vec[k]);
            }
        }
        //[l, j-1], [j, k-1], [k, r] ok
        int orderMaxCount = r-k+1;
		if(orderMaxCount == targetK){
			return 0;
		}else if(orderMaxCount > targetK){
   			return findMaxK(vec, k, r, targetK);
		}else {
			// targetK > orderMaxCount
			targetK = targetK - orderMaxCount;
			int equalCount = k-1-j+1;
			if(equalCount >= targetK){
				// 相等的部分足够了
				return 0;
			}
			targetK=targetK-equalCount;
			return findMaxK(vec, l, j-1, targetK);
		}

    }
    std::vector<int> maxSubsequence(std::vector<int> &vec, int k) {
        if(vec.size() <= k) {
            return vec;
        }
        std::vector<std::pair<int, int>> pairVec;
        for(int i = 0; i < vec.size(); ++i) {
            pairVec.push_back({i, vec[i]});
        }

        findMaxK(pairVec, 0, pairVec.size() - 1, k);

        std::vector<std::pair<int, int>> PairRet(
            pairVec.begin() + pairVec.size() - k, pairVec.end());

        sort(PairRet.begin(), PairRet.end(),
             [](std::pair<int, int> &v1, std::pair<int, int> &v2) {
                 return v1.first < v2.first;
             });

        std::vector<int> ret;
        for(int i = 0; i < PairRet.size(); ++i) {
            ret.push_back(PairRet[i].second);
        }

        return ret;
    }
};
int main() { return 0; }
