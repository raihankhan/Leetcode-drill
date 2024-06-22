func lengthOfLongestSubstring(s string) int {
    var start,end,ans int
    isExisting := make(map[byte]bool)
    len :=  len(s)
    for end < len {
        for isExisting[s[end]] == true {
            isExisting[s[start]] = false
            start++
        }
        ans = max(ans,end-start+1)
        isExisting[s[end]] = true
        end++
    }
    return ans
}
