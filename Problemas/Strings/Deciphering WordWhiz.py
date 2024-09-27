n=int(input())
words=[input() for i in range(n)]
g=int(input())
guesses=[input() for i in range(g)]
key=words[0]
def guess(key,word):
    s=""
    for i in range(5):
        if(word[i]==key[i]):
            s+="*"
        elif(word[i] in key):
            s+="!"
        else:
            s+="X"
    return s
for i in range(g):
    c=0
    for word in words:
        if(guess(key,word)==guesses[i]):
            c+=1
    print(c)
