func isSubsequence(s string, t string) bool {
    
        l:=0
        r:=0
        
    for l<len(s) && r<len(t) {
        if s[l]==t[r] {
            l++
            r++
        } else {
            r++
        }
    }
    
    if l==len(s) {
        return true
    }
    
    return false
}
