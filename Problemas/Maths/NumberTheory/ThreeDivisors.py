#https://leetcode.com/problems/three-divisors/?envType=problem-list-v2&envId=number-theory&difficulty=EASY
class Solution:
    def isThree(self, n: int) -> bool:
        def get_divisors(n):
            divisors = []
            for a in range(1, int(n**0.5) + 1):
                if n % a == 0:
                    divisors.append(a)
                    if a != n // a:
                        divisors.append(n // a)
            return divisors
        return len(get_divisors(n)) == 3
