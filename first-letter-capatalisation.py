import os

def First_Letter_Capatilise(ls):
    ls = ls.split(' ')
    final = ''
    b = 1
    for i in range(len(ls)):
        if b!=1:
            final+=' '
        a = 1
        b+=1
        for j in ls[i]:
            if a==1:
                final+=j.upper()
            else:
                final+=j
            a+=1
    return final

a = input('Enter File Whole Path:')
a = a[1:len(a)-1]
final = []

with open(fr"{a}") as t:
    temp = t.readlines()
    for i in temp:
        _ = First_Letter_Capatilise(i)
        final.append(_)

with open(fr"{a}", 'w') as t:
    t.write('')

with open(fr"{a}", 'a') as t:
    for i in final:
        t.write(i)
