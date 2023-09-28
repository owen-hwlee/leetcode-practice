class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // provide quick calculation for boundary cases
        if (query_row == 0) {
            return (poured < 1.0) ? poured : 1.0;
        }

        // // initialize tower with row 0 with only 1 glaas
        // vector<vector<double>> tower = { { static_cast<double>(poured) } };
        vector<double> prev = { static_cast<double>(poured) };
        
        // iterate flowing down the tower up until right before the query_row
        for (int i = 1; i < query_row; ++i) {
            vector<double> row(i + 1, 0);
            // const vector<double>& prev = tower[tower.size() - 1];

            // receive from row directly above
            row[0] = (prev[0] > 1) ? (prev[0] - 1) / 2 : 0;
            double left = 0, right = row[0] * 2;
            for (int j = 1; j < i; ++j) {
                // calculate excess from left and right cups from previous row
                left = right;
                right = (prev[j] > 1) ? prev[j] - 1 : 0;
                row[j] = (left + right) / 2;
            }
            row[i] = right / 2;

            // if middle glass gets less than 1, all glasses must also get less than 1
            // all subsequent rows get 0
            if (row[i / 2] < 1) {
                return 0;
            }

            // tower.push_back(row);
            prev = row;
        }

        // no need to calculate the entire query_row, just the query_glass suffices
        // const vector<double>& prev_row = tower[query_row - 1];
        double left = (query_glass == 0 || prev[query_glass - 1] < 1) ? 0 : prev[query_glass - 1] - 1;
        double right = (query_glass == query_row || prev[query_glass] < 1) ? 0 : prev[query_glass] - 1;
        double received = (left + right) / 2;

        return (received < 1.0) ? received : 1.0;
    }
};