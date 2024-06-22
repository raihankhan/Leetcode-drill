func minSubArrayLen(target int, nums []int) int {
    var start,end,sum int
    len := len(nums)
    ans := len+1
    for end < len {
        sum+=nums[end]
        for sum >= target {
            ans =  min(ans, end-start+1)
            sum-=nums[start]
            start++
        }
        end++
    }

    if ans == len + 1 {
        return 0
    }

    return ans
}
