// DP + Binary Search [ O(nlogn)]
// maintain a dp array of increasing elements
// the array doesn't contain the actual LIS
// rather it gets updated whether a later number
// can be used to replace a number in the dp

func lengthOfLIS(nums []int) int {
    n := len(nums)
    dp := make([]int,1)
    dp[0] = nums[0]

    for i:=1; i<n;i++ {
        if dp[len(dp)-1] < nums[i] {
            dp = append(dp,nums[i])
        } else {
            idToUpdate := findIdToUpdate(dp , nums[i])
            dp[idToUpdate] = nums[i]
        }
    }

    return len(dp)
}

func findIdToUpdate(nums []int, target int) int {
    left , right := 0 , len(nums)-1
    for left < right {
        mid := (left+right)/2
        if nums[mid] >= target {
            right = mid
        } else {
            left = mid+1
        }
    }
    return left
}

// DP [ O(n^2) ]
// each number is a subsequence of length 1
// if a number is less than any of it's previous
// it can be appended to previous number as LIS element 

/*
func lengthOfLIS(nums []int) int {
    len := len(nums)
    dp := make([]int, len)
    var res int
    for i:=0;i<len;i++ {
        dp[i]=1
        for j:=0;j<i;j++ {
            if nums[j] < nums[i] {
                dp[i]=max(dp[i] , dp[j]+1)
            }
        }
        res = max(res , dp[i])
    }

    return res
}
*/
