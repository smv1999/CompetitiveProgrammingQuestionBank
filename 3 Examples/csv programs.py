#Search details using a csv file:
import csv
def writer():
    F=open("D:\\12th File handle\\studrec.csv","w",newline=" ")
    w=csv.writer(F)
    while True:
        rec=[]
        rno=input("Enter the roll number of the student")
        name=input("Enter the name of the student")
        marks=input("Enter the marks of the student")
        data=[rno,name,marks]
        rec.append(data)
        ch=input("Do you want to enter more records? y/n")
        if ch in "Nn":
            break

    w.writerows(rec)
    print("Records written successfully\n")
    F.close()

def search():
    F=open("D:\\12th File handle\\studrec.csv","r",newlinw="")
