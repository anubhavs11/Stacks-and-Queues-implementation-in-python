class Node(object):
	def __init__(self,data):
		self.data=data

class stack(object):
	def __init__(self):
		self.head=None
		self.size=0
	
	def push(self,data):
		self.size=self.size+1
		newNode=Node(data)
		if(self.head is None):
			self.head=newNode
			newNode.next=None
		else:
			newNode.next=self.head
			self.head=newNode
	
	def pop(self):
		self.size=self.size-1
		data=self.head.data
		self.head=self.head.next
		return data
	
	def isEmpty(self):
		return self.head is None

	def peak(self):
		return self.head.data
	
	def size(self):
		return self.size;

	def showAll(self):
		currentNode=self.head;
		while(currentNode is not None):	
			print(currentNode.data)
			currentNode=currentNode.next

obj=stack()
obj.push(1)
obj.push(2)
obj.push(3)
obj.push(4)
print("Showing items")
obj.showAll()
print("Popped item : ",obj.pop())
print("Showing items")
obj.showAll()
print("Is Empty : ",obj.isEmpty())
print("Peak : ",obj.peak())

