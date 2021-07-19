import string

def Strength(password):
     
    n = len(password)

    hasLower = False
    hasUpper = False
    hasDigit = False
    specialChar = False
    p = string.ascii_letters + string.digits  #contains all alphabets(in lower & upper case) and digits (0-9)

    for i in range(n):
        if password[i].islower():
            hasLower = True
        if password[i].isupper():
            hasUpper = True
        if password[i].isdigit():
            hasDigit = True
        if password[i] not in p:
            specialChar = True
 
    # Strength of password calculation.
    # password is strong only if it has both upper case and lowercase letters as well as special characters. 
    # Also length should be greater than or equal to 8
    print("Strength of password:-", end = "")
    if (hasLower and hasUpper and
        hasDigit and specialChar and n >= 8):
        print("Strong")
         
    elif ((hasLower or hasUpper) and
          specialChar and n >= 6):
        print("Moderate")
    else:
        print("Weak")
 

if __name__=="__main__":
     
    password = input("Enter password: ")
     
    Strength(password)