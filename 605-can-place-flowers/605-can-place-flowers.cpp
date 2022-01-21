class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        if (flowerbed.size() == 1) return (n - flowerbed[0]);
        if (flowerbed.size() == 2) return n==1 && !(flowerbed[0] || flowerbed[1]);
        
        // every time can, decrease n
        
        if (!(flowerbed[0] || flowerbed[1])) {
            --n;
            flowerbed[0] = 1;
        }
        
        int i = 1;
        while (i < flowerbed.size()-1) {
            // current bit == 1
            if (flowerbed[i]) {
                // no need to consider next bit
                i += 2;
                continue;
            }
            // current bit == 0
            // surrounding bit contains 1, cannot place
            if (flowerbed[i-1] || flowerbed[i+1]) {
                i += 1 + flowerbed[i+1];
                continue;
            } else {    // surrounding bit == 0, can place
                if (--n == 0) return true;      // place one flower
                flowerbed[i] = 1;
                i += 2;
            }
        }
        n -= !(flowerbed[flowerbed.size()-2] || flowerbed[flowerbed.size()-1]);
        return n <= 0;
    }
};