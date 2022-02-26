#sorting of words using functions functions
#Program accepting hyphen separated words and giving the ordered output

def sorter(word):
    word=word.lower()
    word=word.split("-")
    word.sort()
    word="-".join(word)
    print("The arranged sequence of words separated by hyphen")
    print(word)
    
def reverser(word):
    word=word.lower()
    word=word.split("-")
    word.sort(reverse=True)
    word="-".join(word)
    print("The arranged sequence of words separated by hyphens in reverse order")
    print(word)

x=input("Enter the string of words separated by hyphens")
sorter(x)
reverser(x)
