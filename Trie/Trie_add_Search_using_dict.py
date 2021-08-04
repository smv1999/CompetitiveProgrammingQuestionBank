"""Trie DS implementation in Python"""
class Trie:
    root = {}
    
    def add(self, word):
        cur = self.root
        
        for ch in word:
            if ch not in cur:
                cur[ch] = {}
            cur = cur[ch]
        cur['*'] = True
        
    def search(self,word):
        cur = self.root
        
        for ch in word:
            if ch not in cur:
                return False
            cur = cur[ch]
        if '*' in cur:
            return True
        else:
            return False
dictionary = Trie()
dictionary.add("pqr")
dictionary.add("pqrst")
print(dictionary.search("pqr"))
print(dictionary.search("pq"))
print(dictionary.search("p"))
print(dictionary.search("pqrst"))
dictionary.add("p")
print(dictionary.search("p"))
