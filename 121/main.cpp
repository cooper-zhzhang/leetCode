#include <algorithm>
#include <iostream>
#include <vector>


class Solution2 {
public:
  int maxProfit(std::vector<int> &prices) {



    int maxProfit = 0;
    int minPrice  = prices[0];
    for (int i = 0; i < int(prices.size()); ++i) {
         
         maxProfit = std::max(maxProfit, prices[i] - minPrice);
         if (prices[i] < minPrice) {
            minPrice = prices[i];
         }
    }

    return maxProfit;

  }
};



class Solution1 {
public:
  int maxProfit(std::vector<int> &prices) {

    if (prices.size() == 1) {
        return 0;
    }
    for (int i = 1; i < int(prices.size()); ++i) {
      prices[i - 1] = prices[i] - prices[i - 1];
    }

    int maxProtfit = 0;
    int curProfit = 0;

    curProfit = prices[0];
    maxProtfit = std::max(maxProtfit, curProfit);
    for (int i = 1; i < int(prices.size() - 1); ++i) {

      if (curProfit < 0) {
        curProfit = 0;
      }
      curProfit += prices[i];

      maxProtfit = std::max(maxProtfit, curProfit);
    }

    return maxProtfit;
  }
};

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int profit = 0;

    int n = prices.size();
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int curProfit = prices[j] - prices[i];
        if (curProfit > profit) {
          profit = curProfit;
        }

        profit = std::max(profit, curProfit);
      }
    }

    return profit;
  }
};

int main() {

  std::vector<int> nums{7, 1, 5, 3, 6, 4};

//std::vector<int> nums{1};

  std::cout << Solution2().maxProfit(nums) << std::endl;

  return 0;
}
