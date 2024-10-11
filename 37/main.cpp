#include <vector>
using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        fun(board, 1);
    }

private:
    int fun(vector<vector<char>> &a, int count)
    {
        int i;
        int x;
        int y;
        if (count > 81)
            return 1;
        x = (count - 1) / 9;
        y = (count - 1) % 9;

        if (a[x][y] != '.')
        {
            if (fun(a, count + 1))
                return 1;
            return 0;
        }
        else
        {
            for (i = 1; i <= 9; ++i)
            {
                if (check(a, x, y, i))
                {
                    a[x][y] = i+'0';
                    if (fun(a, count + 1))
                        return 1;
                    a[x][y] = '.';
                }
            }
        }
        return 0;
    }

    int check(vector<vector<char>> &a, int x, int y, int b)
    {
        int i;
        int j;
        for (j = 0; j < 9; ++j)
        {
            if (j != x)
            {
                if (b+'0' == a[j][y])
                    return 0;
            }

            if (j != y)
            {
                if (b+'0' == a[x][j])
                    return 0;
            }
        }

        i = x - x % 3;
        j = y - y % 3;
        int loo1 = i;
        int loo2 = j;

        for (i = loo1; i < loo1 + 3; ++i)
            for (j = loo2; j < loo2 + 3; ++j)
            {
                if (i == x && j == y)
                    continue;
                if (b+'0' == a[i][j])
                    return 0;
            }
        return 1;
    }
};

int main() {

    return 0;

}



//大一时写的代码 稍显青涩