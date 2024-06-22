func rob(nums []int) int {
    n := len(nums)
    dp := make([]int, n)
    
    dp[0] = nums[0]
    if n > 1 {
        dp[1] = max(nums[1] , nums[0])
    }
    if n > 2 {
        dp[2] = max( nums[2] + nums[0] , nums[1] )  
    }

    for i:=3;i<n;i++ {
        dp[i] = max(nums[i]+dp[i-2], dp[i-1])
    }

    return dp[n-1]
}
