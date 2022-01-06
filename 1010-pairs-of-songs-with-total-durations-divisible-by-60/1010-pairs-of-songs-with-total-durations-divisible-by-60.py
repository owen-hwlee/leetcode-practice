class Solution(object):
    def numPairsDivisibleBy60(self, time):
        """
        :type time: List[int]
        :rtype: int
        """
        hashtable = [0]*60
        count = 0
        for i in time:
            i %= 60
            count += hashtable[60-i] if i else 0
            hashtable[i] += 1
            print(count)
        count += (hashtable[0]**2 - hashtable[0]) // 2
        return count
        