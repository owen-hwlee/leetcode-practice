class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle = vector<vector<int>>(numRows);
        for (int i = 1; i <= numRows; ++i) {
            vector<int> layer = vector<int>(i, 1);
            if (numRows > 2) {
                for (int j = 1; j < i - 1; ++j) {
                    layer[j] = pascalTriangle[i - 2][j - 1] + pascalTriangle[i - 2][j];
                }
            }
            pascalTriangle[i - 1] = layer;
        }
        return pascalTriangle;
    }
};