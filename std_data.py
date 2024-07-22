/*-------------------------------------*/
/* Name : Girish Machhhindra Unde      */
/* Roll.No : SA029   DIV : A  Batch:2  */
/*-------------------------------------*/

#!/user/bin/env python3
# -*- coding utf-8 -*-
"""
Created on Jul 19 09:01:05 2024

@author : Student
"""
marks = []
tot_Student = int(input("Enter a No of Student : "))
for i in range(tot_Student):
    mark = input("Enter a Marks : ")
    x = 0
    if(mark == "ABSENT" and mark == "absent"):
        x = x + 1
        break
    if(x>=1):
        print("Number of Absent Student : ",x)
    mark = int(mark)
    if(mark>0 and mark<=30):
        marks.append(mark)
    else:
        print(Invalid)

def avrage(marks):
    sum = 0
    for i in range(len(marks)):
        sum += marks[i]
    print("Average No of Marks : ",sum)
avrage(marks)
        
def Minimum(marks):
    Min = 31
    for i in range(len(marks)):
        if(marks[i]<Min):
            Min = marks[i]
    print("Minimum Obtain Marks : ",Min)
Minimum(marks)

def Maximum(marks):
    Max = 0
    for i in range(len(marks)):
        if(marks[i]>Max):
            Max = marks[i]
    print("Maximum Obtain Marks : ",Max)
Maximum(marks)
    
def Freq(marks):
    mark_freq = {}
    valid_marks = [mark for mark in marks if mark is not None]
    for mark in valid_marks:
        if mark in mark_freq:
            mark_freq[mark] += 1
        else:
            mark_freq[mark] = 1
    max_freq = max(mark_freq.values(), default=0)
    most_frequent_marks = [mark for mark, freq in mark_freq.items() if freq == max_freq]
    print("Highest frequency:", max_freq)
    print("Marks with the highest frequency:", most_frequent_marks)
Freq(marks)
