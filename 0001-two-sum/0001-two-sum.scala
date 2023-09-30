object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        val map = collection.mutable.HashMap[Int, Int]()

        for ((n, i) <- nums.zipWithIndex) {
            val result = map.get(target - n)
            if (result.isDefined) {
                return Array(result.get, i)
            } else {
                map.put(n, i)
            }
        }
        Array(0, 0)
    }
}