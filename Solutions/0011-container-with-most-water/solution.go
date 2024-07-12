func maxArea(height []int) int {
    left , right := 0 , len(height) -1
    maxArea := 0

    for left < right {
        if height[left] < height[right] {
            containerArea := height[left] * (right - left)
            if containerArea > maxArea {
                maxArea = containerArea
            }
            left++
        } else {
            containerArea := height[right] * (right - left)
            if containerArea > maxArea {
                maxArea = containerArea
            }
            right--
        }
    }
    return maxArea
}
