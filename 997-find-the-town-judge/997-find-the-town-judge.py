class Solution(object):
    def findJudge(self, n, trust):
        """
        :type n: int
        :type trust: List[List[int]]
        :rtype: int
        """
        trustee = [0]*n
        trusts = list(range(1, n+1))
        for a, b in trust:
            if a in trusts:
                trusts.remove(a)
            trustee[b-1] += 1
        # print(trustee)
        # print(trusts)
        for i in trusts:
            if trustee[i-1] == (n-1):
                return i
        return -1
            
            