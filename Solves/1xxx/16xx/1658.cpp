func minOperations(nums []int, x int) int {
    n := len(nums)
    ans := n + 1
    sum := 0
    for i := 0; i < n; i++ {
        sum += nums[i]
    }
    curLeft := n-1
    curSum := 0
    if sum == x {
        ans = n
    }
        
    for i := n-1; i >= 0; i-- {
        for curSum + sum > x{
            sum -= nums[curLeft];
            curLeft --;
        }
        
        if curSum + sum == x{
            ans = min (ans, curLeft + n - i);
        } 
        curSum += nums[i]
        if (curSum > x) {
            break;
        }
            
    }

    if(ans > n){
        return -1;
    }
    return ans;
}