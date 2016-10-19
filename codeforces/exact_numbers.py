import sys


text = sys.stdin.readline()
a = ""
b = ""

text = text.strip()
text = text.replace(';', ',')
words = text.split(',')

isWord = False
if text[-1] == ',':
    isWord = True


for w in words:
    number = w.isdigit()

    if number == True and len(w) > 1 and w[0] == '0':
        #then its not a number:
        b = b + w + ","
    elif number == True:
        a = a + w + ","
    else:
        b = b + w + ","

#remove the last " symbol
a = a[:-1]
b = b[:-1]

a = a.strip()
b = b.strip()

a =  "\"" + a + "\""
b =  "\"" + b + "\""

if len(a) > 2:
    print(a)
else:
     print("-")

if len(b) > 2:
    print(b)
else:
    if isWord == True:
        print(b)
    else:
        print("-")
