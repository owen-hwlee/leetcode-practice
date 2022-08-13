class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = vector<int>(rowIndex + 1, 1);
        if (rowIndex > 1) {
            for (int i = 2; i <= rowIndex; ++i) {
                int temp1 = row[rowIndex-1], temp2 = row[rowIndex];
                for (int j = rowIndex - 1; j > rowIndex - i; --j) {
                    row[j] = temp1 + temp2;
                    temp2 = temp1;
                    temp1 = row[j-1];
                }
            }
        }
        return row;
    }
};