"""To solve this problem we have to compute the nim sum of all the piles.
To compute the nim sum between two integers, we write them in base two (binary system).
Then, we apply the xor operator for each pair of digits of the integers in base two representation. (Bitwise).
For example:
let n = 2:
a = 7, the first pile with 7 stones.
b = 8, the second pile with 8 stones.
7 written in base two is 111, 8 written in base two is 1000.
111 hasn't the same number of digits as 1000, so we add a zero at the beginning and it won't change the number.
0111
1000
-xor-
1111.
1111 in base 10 (decimal system) is equals to 15.
So, 7 xor 8 = 15.


-Theorem:
If the game has n piles with a0, a1, a2, ... an-1 stones respectively.
Jack will win the game if and only if the nim sum of all the piles is not equal to zero. He will lose otherwise.

Using this theory, this problem can be solved easily in Python using the circumflex(^) operator to compute the xor operation
between all the piles.
"""

#Solution: 
while True:
    n = int(input())
    if n==0:
        break
    ans = 0
    for i in [int(i) for i in input().split()]:
        ans^=i 
    print("Yes" if ans!=0 else "No")

