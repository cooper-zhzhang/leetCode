// 712 625 847
class Solution {

  public:
    vector<vector<int>> ret;

    void twoSum(vector<int> &vec, int i) {
        int j = i + 1;
        int k = vec.size() - 1;

        while(j < k) {
            int sum = vec[i] + vec[j] + vec[k];
            if(sum == 0) {
                // get
                ret.push_back({vec[i], vec[j], vec[k]});

                int temp = vec[j];
                while(j < k && vec[j] == temp) {
                    j++;
                }

            } else if(sum < 0) {
                j++;

            } else {
                k--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int> &vec) {

        if(vec.size() < 3) {
            return ret;
        }
        sort(vec.begin(), vec.end());

        for(int i = 0; i < vec.size();) {
            twoSum(vec, i);
            int temp = vec[i];
            while(i < vec.size() && vec[i] == temp) {
                i++;
            }
        }

        return ret;
    }
};

int main() { return 0; }
