"""
Leetcode Problem #20
Link: https://leetcode.com/problems/valid-parentheses/

Name: Ayesh Biswal
Github: heyyayesh (https://github.com/heyyayesh)
"""


class Solution:
    def isValid(self, s: str) -> bool:

        # Dictionary which stores matching parentheses
        matches = {
            ')': '(',
            '}': '{',
            ']': '['
        }

        # List to implement stack functionality and store parentheses
        stk = []

        # Iterate through the string
        for char in s:

            # If it's an opening type, push to stack
            if char in matches.values():
                stk.append(char)

            # If it's a closing type,
            else:
                # If stack is empty or top element of stack doesn't match opening type, return False
                if len(stk) == 0 or matches[char] != stk[-1]:
                    return False

                # Otherwise if it matches opeing type, pop it from the stack
                stk.pop()

        # After going through the string, if stack is empty return True, else return False
        return not len(stk)
