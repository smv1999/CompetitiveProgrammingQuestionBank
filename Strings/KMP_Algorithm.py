"""KMP Algorithm - Pattern Searching Algorithm

KMP Algorithm is also called as Knuth, Morris, and Pratt string searching algorithm
This algorithm uses the previous comparison data.
It uses a partial match table to analyze the pattern structure. 
The goal of the table is to allow the algorithm not to match any character of pattern more than once. 
The basic idea behind KMP’s algorithm is: 
whenever we detect a mismatch (after some matches), we already know some of the characters in the text of the next window.
We take advantage of this information to avoid matching the characters that we know will anyway match. 
We need to know about proper prefixes and proper suffixes first.

Proper prefix - All the characters in a string, with one or more cut off the end. 
“C”, “Co”, “Cod”, and “Codi” are all the proper prefixes of “Coding”.

Profer suffix - All the characters in a string, with one or more cut off the beginning. 
“adrid”, “drid”, “rid”, “id”, and “d” are all proper suffixes of “Madrid”.

The value of the partial table is the "length of the longest proper prefix that matches a proper suffix".

Pseudocode - 
if table[partial_match_length] > 1:
    skip ahead by partial_match_length - table[partial_match_length - 1] characters
else:
    don’t get to skip ahead by partial_match_length - table[partial_match_length - 1] characters. See next partial match.

Let’s say we’re matching the pattern “abababca” against the text “bacbababaabcbab”.
Here’s our partial match table again for easy reference

char:  | a | b | a | b | a | b | c | a |
index: | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 
value: | 0 | 0 | 1 | 2 | 3 | 4 | 0 | 1 |

Example - 
1. The first match is at index 1.
bacbababaabcbab
 |
 abababca
Hence partial_match_length = 1
See the next partial match and so on.
Repeat the steps till the last partial match is found.

Time Complexity :
Assuming n is the length of text and m is the length of pattern.
It can search for a pattern in O(n) time as it never re-compares a text symbol that has matched a pattern symbol. 
Construction of a partial match table takes O(m) time. 
Therefore, the overall time complexity of the KMP algorithm is O(m + n).
"""

# Python program for KMP Algorithm
def KMPSearch(pat, txt):
	plen = len(pat)
	tlen = len(txt)

	# create lps[] that will hold the longest prefix suffix
	# values for pattern
	lps = [0]*plen
	j = 0 # index for pat[]

	alen = 0 # length of the previous longest prefix suffix

	lps[0] # lps[0] is always 0
	i = 1

	# the loop calculates lps[i] for i = 1 to M-1
	while i < plen:
		if pat[i]== pat[alen]:
			alen += 1
			lps[i] = alen
			i += 1
		else:
			if len != 0:
				len = lps[alen-1]
				# Also, note that we do not increment i here
			else:
				lps[i] = 0
				i += 1

	i = 0 # index for txt[]
	while i < tlen:
		if pat[j] == txt[i]:
			i += 1
			j += 1

		if j == plen:
			print ("Found pattern at index " + str(i-j))
			j = lps[j-1]

		# mismatch after j matches
		elif i < tlen and pat[j] != txt[i]:
			# Do not match lps[0..lps[j-1]] characters,
			# they will match anyway
			if j != 0:
				j = lps[j-1]
			else:
				i += 1	

print("enter text: ")
txt=input()
print("enter pattern; ")
pat=input()
KMPSearch(pat, txt)
