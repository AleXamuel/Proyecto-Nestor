# https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n < 1:
            return ""
        
        start, end = 0, 0

        for i in range(n):
            odd = self.expandCenter(s, i, i)
            even = self.expandCenter(s, i, i+1)
            longest = max(odd, even)
            
            if longest > end - start:
                #Buscamos el índice que esté a la mitad del palíndromo. 
                #Como longest es la longitud del palíndromo, restamos 1 para obtener la longitud real 
                #(ya que los índices empiezan en 0). Luego, dividimos entre 2 para obtener el índice del centro.
                start = i - (longest - 1) // 2 
                #Aquí también calculamos el índice del final del palíndromo. 
                #Como i es el índice del centro del palíndromo, sumamos longest // 2 para obtener el índice del final.
                end = i + longest // 2

        return s[start:end + 1]
        
    def expandCenter(self, s: str, l: int, r: int) -> int:
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return len(s[l + 1:r])
