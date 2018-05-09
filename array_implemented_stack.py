class stack:
	def __init__(self):
		self.stack=[]

	def push(self,data):
		self.stack.append(data)

	def pop(self):
		data=self.stack[-1]
		del self.stack[-1]
		return data

	def isEmpty(self):
		return len(self.stack)==0
	
	# it returns the last element from stack without affecting that
	def peak(self):
		return self.stack[-1]

	def showAll(self):
		size=len(self.stack)-1
		for i in range(size,-1,-1):
			print(self.stack[i])

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
	
