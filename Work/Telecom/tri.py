import math
import sys

fileLink = str(sys.argv[1])
newFileName = "out1.txt"
newFileName2 = "out2.txt"

fileRead = open(fileLink, "r", encoding="UTF-8")
fileWrite = open(newFileName, "w", encoding="UTF-8")
fileWrite2 = open(newFileName2, "w", encoding="UTF-8")

fileText = fileRead.read()

x = sorted(fileText)

sortedChars=""
sortedChars = ''.join(x)
fileWrite.write(sortedChars)

charNumber = len(sortedChars)

fileRead.close()
fileWrite.close()

charCount = {}

for c in sortedChars:
	if c in charCount:
		charCount[c] = charCount[c] + 1
	else:
		charCount[c] = 1
charCount = sorted(charCount.items(), key=lambda item:item[1], reverse=True)

for c in charCount:
	for i in range(c[1]):
		fileWrite2.write(c[0])
fileWrite2.close()

entropie = 0

D = math.log(charNumber, 2)

for c in charCount:
	proba = c[1] / charNumber
	entropie += (proba * math.log(proba, 2) )
	print(hex(ord(c[0])), ":", proba)

entropie *= -1

redondence = D - entropie
tauxMax = (D-entropie)/D
print("H = ", entropie)
print("R = ", redondence)
print("D = ", D)
print("compression max = ", tauxMax)