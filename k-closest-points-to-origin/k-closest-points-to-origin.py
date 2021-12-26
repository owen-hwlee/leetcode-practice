class Solution:
    
    from math import sqrt
    from bisect import bisect_left
    
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        
        # helper function to calculate Euclidean distance
        def euclidean_distance(idx: int) -> int:
            (x, y) = points[idx]
            return sqrt(x**2 + y**2)
        
        # initiate for first k points in given points array
        k_idx: List[int] = list(range(k))
        k_dist: List[int] = [euclidean_distance(i) for i in k_idx]
            
        # sort the list in increasing order of distance
        k_idx.sort(key = lambda x: k_dist[x])
        # k_idx = [idx for dist, idx in sorted(zip(k_dist, k_idx))]
        k_dist.sort()
        
        # print(k_dist)
        # print(k_idx)
            
        # perform replacement as needed for the remaining (n - k) points
        for i in range(k, len(points)):
            dist = euclidean_distance(i)
            if dist >= k_dist[k-1]:
                continue
            else:
                # find position to insert
                new_idx = bisect_left(k_dist, dist)
                k_dist[new_idx:new_idx] = [dist]
                k_idx[new_idx:new_idx] = [i]
                k_dist.pop()
                k_idx.pop()

        return [points[idx] for idx in k_idx]
                        
        
        