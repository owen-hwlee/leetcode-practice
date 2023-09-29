class Solution {
    fun isMonotonic(nums: IntArray): Boolean {
        if (nums.size <= 2) {
            return true;
        }

        var isDesc: Boolean = true;
        var isAsc: Boolean = true;

        var i: Int = nums[0];
        for (k in 1..nums.size - 1) {
            val j: Int = nums[k];

            if (i < j) {
                isDesc = false;
            } else if (i > j) {
                isAsc = false;
            }

            if (!isDesc && !isAsc) {
                return false;
            }

            i = j;
        }

        return true;
    }
}