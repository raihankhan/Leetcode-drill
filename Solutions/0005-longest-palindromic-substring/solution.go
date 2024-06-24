func longestPalindrome(s string) string {
    var l, r int
    n := len(s)

    maxLen := 1
    for i:=1;i<n;i++ {
        // odd lenth
        start, end := isPalindrome(s,i,i,n)
      
        if maxLen < (end - start + 1) {
            maxLen = end - start + 1
            l = start
            r = end
        }
      
        // even lenth
        start, end = isPalindrome(s,i-1,i,n)
        if maxLen < (end - start + 1) {
            maxLen = end - start + 1
            l = start
            r = end
        }
    }
    
    return s[l:r+1]
}

func isPalindrome(s string,start int, end int, n int) (int, int) {
    for start >= 0 && end < n {
        if s[start] != s[end] {
            return start+1, end-1
        }
        
        start--
        end++
    }

    return start+1, end-1
}
