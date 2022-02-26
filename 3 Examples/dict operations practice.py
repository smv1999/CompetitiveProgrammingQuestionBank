print("Dictionary operations")

def Dict(d,k,v):
    print("Current dictionary",d)
    d[k]=v
    print("Updated dictionay",d)
    
    
d=eval(input("Enter the dictionary"))
print(d, "The given dict")

k=input("Enter the key to be updated")
if k in d.keys():
    v=input("Enter the new value of the key")
    Dict(d,k,v)
else:
    print("Key not found")
    
    
