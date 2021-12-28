class Solution {
public:
    int findComplement(int num) {
        int temp = num;
        int digits = 0;
        while (temp != 0) {
            ++digits;
            temp = temp >> 1;
        }
        temp = 1 << (digits - 1);
        cout << temp;
        int comp = 0;
        for (int i = 0; i < digits; ++i) {
            comp = comp | (temp & ~num);
            temp = temp >> 1;
        }
        return comp;
        
        
        // int temp = 0;
        // while (num != 0) {
        //     temp = temp << 1;
        //     temp += 1 - (num & 1);
        //     num = num >> 1;
        // }
        // int comp = 0;
        // while (temp != 0) {
        //     comp = temp << 1;
        //     comp += temp & 1;
        //     comp = comp >> 1;
        // }
        // return comp;
    }
};