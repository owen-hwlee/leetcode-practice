

class Solution(object):
    def carPooling(self, trips, capacity):
        """
        :type trips: List[List[int]]
        :type capacity: int
        :rtype: bool
        """
        getIn = {}
        getOut = {}
        
        for _num, _from, _to in trips:
            if _from in getIn:
                getIn[_from] += _num
            else:
                getIn[_from] = _num
            if _to in getOut:
                getOut[_to] += _num
            else:
                getOut[_to] = _num
            
        locs = sorted(list(set(getIn.keys() + getOut.keys())))

        headCount = 0
        
        for loc in locs:
            if loc in getOut:
                headCount -= getOut[loc]
            if loc in getIn:
                headCount += getIn[loc]
            
            if headCount > capacity:
                return False
            
        return True
