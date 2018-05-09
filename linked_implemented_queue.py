class Node(object):
	def __init__(self,data):
		self.data=data
	
class queue(object):
	def __init__(self):
		self.head=None
		self.tail=None
		self.size=0

	def enqueue(self,data):
		newNode=Node(data)
		self.size=self.size+1
		if(self.head is None):	
			self.head=self.tail=newNode
			self.head.next=self.head.next=None
		else:
			self.tail.next=newNode
			newNode.next=None
			self.tail=newNode
		
	def dequeue(self):
		if(self.head is None):
			print("Queue is empty")
			return 0
		else:	
			self.size=self.size-1
			data=self.head.data
			self.head=self.head.next
			return data

	def isEmpty(self):
		return self.size==0

	def size(self):
		return self.size

	def peak(self):
		return self.head.data

	def showAll(self):
		currentNode=self.head

		if(currentNode is None):
			print("Queue is empty")
		while(currentNode is not None):
			print(currentNode.data)
			currentNode=currentNode.next

obj=queue()
obj.enqueue(1)
obj.enqueue(2)
obj.enqueue(3)
obj.enqueue(4)
print("Showing items")
obj.showAll()
print("dequeue : ",obj.dequeue())
print("Showing items")
obj.showAll()
print("Is Empty : ",obj.isEmpty())
print("Peak : ",obj.peak())
	
