#https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true
#Name: Vasundhara Shenoy
#Github: https://github.com/VasundharaShenoy

def staircase(n):
   for i in range(n):

    for j in range(n):

        if j>=(n-i-1):

            print('#',end="")

        else:
            print(' ',end="")
    print( )
        
