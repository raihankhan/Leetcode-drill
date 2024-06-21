func maximumSubarraySum(nums []int, k int) int64 {
   var start,end int
   var maxSum,currSum int64
   existsInRange := make(map[int]bool)
   n := len(nums)
   for end < n {
      currSum += int64(nums[end])
      window := end-start+1 
      for window > k || existsInRange[nums[end]] {
         existsInRange[nums[start]] = false
         currSum -= int64(nums[start])
         start++
         window = end-start+1

      }
      if window == k {
        maxSum = max(maxSum, currSum)
      }
      existsInRange[nums[end]]=true
      end++
   }
   return maxSum
}
