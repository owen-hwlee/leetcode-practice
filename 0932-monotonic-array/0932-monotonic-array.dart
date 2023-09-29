class Solution {
  bool isMonotonic(List<int> nums) {
    if (nums.length <= 2) {
        return true;
    }

    bool isDesc = true, isAsc = true;

    int i = nums[0];
    for (int k = 1; k < nums.length; ++k) {
        int j = nums[k];

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