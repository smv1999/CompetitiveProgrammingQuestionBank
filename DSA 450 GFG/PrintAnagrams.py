
# Problem : https://practice.geeksforgeeks.org/problems/print-anagrams-together/1


# Input:
# N = 5
# words[] = {act,god,cat,dog,tac}
# Output: 
# god dog
# act cat tac
# Explanation:
# There are 2 groups of
# anagrams "god", "dog" make group 1.
# "act", "cat", "tac" make group 2.

from collections import defaultdict

def Anagrams(words,n):
    '''
    words: list of word
    n:      no of words
    return : list of group of anagram {list will be sorted in driver code (not word in grp)}
    '''
    
    #code here
    anagrams = defaultdict(list)
    
    for word in words:
        anagrams["".join(sorted(word))].append(word)
  
    return anagrams.values()
    

#  Driver Code 

if __name__ =='__main__':
    t= int(input())
    for tcs in range(t):
        n= int(input())
        words=input().split()
        
        ans=Anagrams(words,n)
        
        for grp in sorted(ans):
            for word in grp:
                print(word,end=' ')
            print()



# Used default dict from collections module . It does not raise key value error