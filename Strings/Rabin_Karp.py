""" Rabin Karp Algorithm for pattern searching in Python

Rabin-Karp algorithm is an algorithm used for searching/matching patterns in the text using a hash function. 
It does not travel through every character in the initial phase rather it filters the characters that do not match
and then performs the comparison.

Working - 
A sequence of characters is taken and checked for the possibility of the presence of the required string. 
If the possibility is found then, character matching is performed.
f the hash values are unequal, the algorithm will determine the hash value for next plen-character sequence. If the hash values are equal, 
the algorithm will analyze the pattern and the plen-character sequence. 
In this way, there is only one comparison per text subsequence, and character matching is only required when the hash values match.

Features - 
Like naive algorithm we slide the pattern over the string one by one and compare every character in pattern with the text.
To reduce the number of comparisons, we use hashing. 
We compare the hash values of the pattern and the current text window if the hash value match, 
then only we proceed to compare individual characters of pattern and the text window.
To calculate the hash value of the current window we use the concept of rolling hash. 
In rolling hash we compute hash value of current window using the hash value of the previous window.

Time Complexity - 
Assuming n is length of text and m is length of pattern.
Its worst-case time is O(nm). 
Worst case of Rabin-Karp algorithm occurs when all characters of pattern and text are same as the hash values
of all the substrings of text[] match with hash value of pattern[].

Example - 
text – “abdabc”
pattern – “abc”

a b c d 
1 2 3 4 

text – “a  b  d  a  b  c”
plen = pattern length = 3
t  =  4

hash_0  =  1 * 4^2  +  2 * 4^1  +  4 * 4^0  =  28
hash_1  =  4 * {hash_0 – 1 * 4^2} + 1  =  49
hash_2  =  4 * {hash_1 – 2 * 4^2} + 2  =  70
hash_3  =  4 * {hash_2 – 4 * 4^2} + 3  =  27

Hence in general
hash_i+1  =  t * {hash_i  –  text[i] * t^(plen-1)} + text[i+plen]

"""

#Program


d = 10

def Rabin_Karp(pattern, text, q):
    m = len(pattern)    #len of pattern
    n = len(text)       #len of text
    p = 0
    t = 0
    h = 1
    i = 0
    j = 0

    for i in range(m-1):
        h = (h*d) % q

    # Calculate hash value for pattern and text
    for i in range(m):
        p = (d*p + ord(pattern[i])) % q    #formula to calculate hash func for pattern
        t = (d*t + ord(text[i])) % q       #formula to calculate hash func for text

    # Find the match
    for i in range(n-m+1):
        if p == t:
            #Check for characters one by one 
            for j in range(m):
                if text[i+j] != pattern[j]:
                    break

            j += 1
            if j == m:
                print("Pattern is found at position: " + str(i+1))

        #Calculate hash value for next window of text: Remove leading digit, add trailing digit
        if i < n-m:
            #Calculate hash value of next window
           #t = (d*(t-ord(text[i])*h) + ord(text[i+m])) % q
            t = (d*(t-ord(text[i])*h) + ord(text[i+m])) % q

            # We might get negative value of t, converting it to positive 
            if t < 0:
                t = t+q


print("Enter text: ")           
text=input()                    #input text
print("Enter pattern: ")
pattern=input()                 #input pattern
q = len(text)+len(pattern)
Rabin_Karp(pattern, text, q)