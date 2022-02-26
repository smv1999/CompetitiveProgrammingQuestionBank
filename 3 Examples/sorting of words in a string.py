#Enter a string separated with hyphens to sort the string

def sorter(val):
    val=val.lower()
    val=val.split("-")
    val.sort()
    val="-".join(val)
    print(val)


val=input("Enter the string")
sorter(val)
