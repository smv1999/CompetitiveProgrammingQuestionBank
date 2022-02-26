#palindrome check loop method:
#divide the string into 2 parts

def palindrome():
    value=input("Enter the word")
    value=value.lower()
    l=len(value)
    mid=l//2
    rev=-1

    for num in range(mid):
        if value[num]==value[rev]:
            pass
            num+=1
            rev-=1

        else:
            print("The entered word is not a palindrome")
            break

    else:  #This runs once,when the whole loop is executed without error
        print("Yes the entered word is a palindrome")
palindrome()        


            
