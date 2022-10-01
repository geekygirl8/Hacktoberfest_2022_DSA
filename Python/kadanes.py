# Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

# A subarray is a contiguous part of an array.
# CODE HERE

# solved using kadanes algo
def solve(n, arr):
    # CODE HERE
    curr_sum = 0
    max_sum = -9999999
    for i in range(n):
        curr_sum = curr_sum+arr[i]
        if max_sum < curr_sum:
            max_sum = curr_sum
        if curr_sum < 0:
            curr_sum = 0
    return max_sum
