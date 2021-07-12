def isSubsequence(V,B):
    list_v = []
    list_b = []
    for c in V:
         list_v.append(c)

    for j in B:
        list_b.append(j)

    vindex = 0
    bindex = 0
    while vindex < len(list_v) and bindex < len(list_b):
        if list_v[vindex] == list_b[bindex]:
            bindex += 1
        vindex += 1

    if bindex == len(list_b):
        return True
    return False

V = str(input())
N = int(input())
for i in range(N):
    B = str(input())
    result = isSubsequence(V,B)
    if result == True:
        print("POSITIVE")
    else:   
        print("NEGATIVE")
