

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)

        res = [-1 , -1]

        left = self.binarysearch(nums ,target, 0 , n-1, True )
        if left == -1 :
            return res
        right = self.binarysearch(nums ,target , 0 , n-1, False )
        res[0] = left
        res[1] = right

        return res
    
    def binary_search(self, nums: List[int],t:int, l:int , r:int ,  left_bool :bool)->int:
        if(l <= r):
            mid = (l+r)//2

            if(nums[mid] == t):
                if left_bool :
                    l_index = self.binarysearch(nums , t , l , mid-1 ,left_bool )
                    if (l_index == -1) :
                        return mid 
                    return l_index

                else:
                    r_index = self.binarysearch(nums , t , mid+1 , r , left_bool)
                    if (r_index == -1):
                        return mid 
                    return r_index
            elif(nums[mid]<t):
                return self.binary_search(nums, t, mid+1, r, left_bool)
            else:
                return self.binary_search(nums, t, l, mid-1, left_bool)    
            

    
if __name__ == "__main__":
    #init
    sol = Solution()
    sol.searchRange([5,7,7,8,8,10], 8)
    #act