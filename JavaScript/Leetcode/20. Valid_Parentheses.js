/*
    https://leetcode.com/problems/valid-parentheses/description/
    Time Complexity - O(n)
    Space Complexity - O(1)
    Solution by SkyC0der
*/
var isValid = function(s) {
    const openingBrackets = ["(", "{", "[" ]
    const closingBrackets = [")", "}", "]"]
    let arr = []
    
    let isClosing = false
    
    if (s.length === 1) return false
    for (let i = 0; i < s.length; i++){
        if (closingBrackets.includes(s[0])) return false;
        
        if (openingBrackets.includes(s[i])){
            arr.push(openingBrackets.indexOf(s[i]))
        }
        if (closingBrackets.includes(s[i])){
            isClosing = true
            let x = closingBrackets.indexOf(s[i])
            let y = arr.pop()
            
            if (x !== y) return false;
        }
    }
    return true && isClosing && arr.length === 0
}