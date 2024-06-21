func longestNiceSubarray(nums []int) int {
    var start,end,maxWindow int
    bitCount := make([]int,32)
    n := len(nums)
    for end < n {
        // store bitcounts
        isNice := true
        for bit,count := range bitCount {
            if (nums[end] & (1<<bit)) != 0 {
                bitCount[bit] = count+1
                if bitCount[bit] > 1 {
                    isNice = false
                }
            }
        }

        for !isNice {
            // restore bitcounts
            isNice = true
            for bit,count := range bitCount {
                if (nums[start] & (1<<bit)) != 0 {
                    bitCount[bit] = count-1
                }
                if bitCount[bit] > 1 {
                    isNice = false
                }
            }
            start++
        }

        maxWindow = max(maxWindow, end-start+1)
        end++
    }
    return maxWindow
}

// AND operation between any pair in a range can be non-zero
// only when atleast two numbers share 1 in a same bit position
// store bits on the end pointers and 
// restore bits on the start pointer if false conditions matches
