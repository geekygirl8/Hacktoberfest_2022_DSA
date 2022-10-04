# Username - Saurabh-2809
# Github Id - https://github.com/Saurabh-2809

# Problem Link - https://www.hackerrank.com/challenges/write-a-function/problem?isFullScreen=true

def is_leap(year):
    leap = False
    
    if year%4 != 0:
        leap = False
    else:
        if year%100 != 0:
            leap = True
        else:
            if year%400 == 0:
                leap = True
            else:
                leap = False
    
    return leap
    
year = int(input())
print(is_leap(year))
