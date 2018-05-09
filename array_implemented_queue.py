class queue:
	def __init__(self):
		self.queue=[]

	def enqueue(self,data):
		self.queue.append(data)

	def dequeue(self):
		data=self.queue[0]
		del self.queue[0]
		return data

	def isEmpty(self):
		return len(self.queue)==0
	
	# it returns the First element from queue without affecting that
	def peak(self):
		return self.queue[0]

	def showAll(self):
		for i in self.queue:
			print(i)

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
	
