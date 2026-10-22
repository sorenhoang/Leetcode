class Solution:
    def minCost(self, arr: List[int], brr: List[int], k: int) -> int:
        n = len(arr)

        def minCost():
            return sum(abs(a - b) for a, b in zip(arr, brr))
        
        res = minCost()
        arr = sorted(arr)
        brr = sorted(brr)

        res = min(res, minCost() + k)

        return res
        

