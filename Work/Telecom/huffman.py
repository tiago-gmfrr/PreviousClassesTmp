import math
import sys

class Node: 
	def __init__(self, value, char, left=None, right=None, parent=None, code=None):
		self.value = value
		self.char = char
		self.right = left
		self.left = right
		self.code = code
		self.parent = parent

	def setChildren(self, left = None, right = None):
		self.right = left
		self.left = right

def assignCode(node, tmp=""):
	if node.parent != None:
		np= node.parent
		node.code = str(np.code) + tmp
		#print(node.char, " : ", node.code)
	if node.left != None:
		assignCode(node.left, "0")
	if node.right != None:
		assignCode(node.right, "1")

	if node.left == None and node.right == None:
		print(hex(ord(node.char)), " : ", node.code)
	
	""" if node.left != None:
		if node.parent != None: 
			#print(node.parent.code)
			if node.parent.code != "":
				node.code = "0"
			else:
				np = node.parent
				node.code = str(np.code) + "0"
		#print(node.char, " : ", node.code)
		assignCode(node.left)

	if node.right != None:
		if node.parent != None: 
			if node.parent.code != "":
				node.code = "1"
			else:
				node.code = node.parent.code + "1"
		#print(node.char, " : ", node.code)
		assignCode(node.right) """
		
	return node
		

def huffman(charList):
	nodeList = []
	for c in charList:
		n = Node(c[1], c[0])
		nodeList.append(n)

	nodeList = sorted(nodeList, key=lambda item:item.value)

	while(len(nodeList) > 1):
		v1 = nodeList[0]
		v2 = nodeList[1]
		newNode = Node(v1.value + v2.value, v1.char+v2.char, v1, v2)
		v1.parent = newNode
		v2.parent = newNode
		nodeList.pop(1)
		nodeList.pop(0)
		nodeList.append(newNode)
		nodeList = sorted(nodeList, key=lambda item:item.value)

	tree = nodeList[0]
	tree.code=""
	codedList = assignCode(tree)

	""" for n in codedList:
		print(n.char, " : " ,n.code) """

	return nodeList[0]

fileNameRead = str(sys.argv[1])
fileNameWrite = str(sys.argv[2])

fileRead = open(fileNameRead, "r", encoding="UTF-8")
fileWrite = open(fileNameWrite, "w", encoding="UTF-8")

fileText = fileRead.read()

charCount = {}

for c in fileText:
	if c in charCount:
		charCount[c] = charCount[c] + 1
	else:
		charCount[c] = 1
charCount = sorted(charCount.items(), key=lambda item:item[1])

h = huffman(charCount)

# firstChild = Node(charCount[0][1], charCount[0][0])
# secondChild = Node(charCount[1][1], charCount[1][0])
# charCount.pop(0)
# charCount.pop(1)
# tree = Node(firstChild.value + secondChild.value, firstChild.char + secondChild.char, firstChild, secondChild)
# charCount[tree.char] = tree.value
# charCount = sorted(charCount.items(), key=lambda item:item[1])

# print(charCount)
