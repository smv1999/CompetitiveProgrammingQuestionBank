"""
Purpose:

Implementation of Trie has been asked in my interviews like in Google
Store word in Dictionary
Search word in the dictionary returns True if exist
Stores words in a compressed manner
"""
"""
Inputs:
1nd line no of word you want to store in Trie (int)
2rd line to (2+1st line input)th line (string)
Next line enter number of words want to search
then enter strings in each line

"""
class Trie:
    root = {} #main dictionary of Trie
    
    def add(self, word): # This funtion adds new word to Trie
        cur = self.root  # cur is iterator to check whether new key/paths are required to add new word and root is main dictionary
        
        for ch in word: # ch is all the charactors in the word 
            if ch not in cur: # if charactor is not present add new key/path initiate it empty
                cur[ch] = {}  
            cur = cur[ch]    # now go to the key that was created or was present
        cur['*'] = True   # set * key to true at the end of each word
        #so larger the word the dictionary nesting will take place and * key represant the end state of the word
        
    def search(self,word): # This function searches whether the word is presant or not presant
        cur = self.root  #cur is iterator to check whether new key/paths are presant or not
        
        for ch in word:    # ch is all the charactors in the word 
            if ch not in cur:  # if ch is not found in cur that means word not presant so result is false
                return False
            cur = cur[ch] #if ch present then go till the end unless it becomes false
        if '*' in cur: # if * key not present that means words is prefix of a word that is present but word is not Present
            return True
        else:
            return False
# dynamic input 
n2 = int(input("No of words to be Added:\n")) 
print("enter words:")
words = []
checks = []
for j in range(n2):
    words.append(input())
n3 = int(input("No of words to be searched:\n"))
print("enter words:")
for j in range(n3):
    checks.append(input())

        

"""
Time complexity :
Insert: O(word Length)
Search: O(word Length)

Space complexity :
Insert: O(1)
Search: O(1)

Storages required for storing words:
if no word has same prefix the required (total word length+1)*(char size)

"""
dictionary = Trie() # Trie object created


for k in words:
    dictionary.add(k) # adding word in Trie from words list
for k in checks:
    print(dictionary.search(k)) # printing Searched word results if present then prints True if not present then returns False
