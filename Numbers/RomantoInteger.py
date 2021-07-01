# To convert Roman numeral to its equivalent integer

def romanToInt(s): 
        romanToNum={
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }
        
        total=0
        i=0                 # to iterate through each letter of the roman numeral
        
        while i<len(s):
            index1=romanToNum[s[i]]
            if(i+1<len(s)):
                index2=romanToNum[s[i+1]]
                if index1>=index2:
                    total=total+index1
                    i=i+1
                else:
                    total=total-index1
                    i=i+1
            
            else:
                total=total+index1
                i=i+1
        return total

print("Enter the Roman Numeral")        
s=input()
st=romanToInt(s)
print("The roman to integer of the given input is: ",st)
