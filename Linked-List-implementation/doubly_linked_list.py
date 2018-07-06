class Node(object):
	next=None
	prev=None
	def __init__(self,data):
		self.data=data
		
class Linked_List(object):
	def __init__(self):
		self.head=None
		self.tail=None
		self.size=0

	# inserts at the end
	def append(self,data):
		self.size=self.size+1
		newNode=Node(data)
		if(self.head is None):
			self.head=self.tail=newNode
			newNode.prev=None
			newNode.next=None
		else:
			newNode.prev=self.tail
			newNode.next=None
			self.tail.next=newNode
			self.tail=newNode

	#inserts in between
	def insert(self,loc,data):
		self.size=self.size+1
		currentNode=self.head
		while(currentNode is not None):
			if(currentNode.data == loc):
				newNode=Node(data)
				newNode.next=currentNode.next
				newNode.prev=currentNode
				
				currentNode.next.prev=newNode
				currentNode.next=newNode
				break
			else:
				currentNode=currentNode.next
					

	def traverse(self):
		temp=self.head
		if(temp is None):
			print("No elements found")
		else:
			while(temp is not None):
				print(temp.data)
				temp=temp.next
	def remove(self,data):
		self.size=self.size-1
		currentNode=self.head
		found=False
		while(currentNode is not None):
			if(currentNode.data == data):
				found=True
				if(currentNode.prev is not None):
					currentNode.prev.next=currentNode.next
					currentNode.next.prev=currentNode.prev
				else:
					self.head=currentNode.next
					currentNode.next.prev=None
				print(data," deleted")
				break
			else:
				currentNode=currentNode.next

		if(not found):
			print(data," already not in the list")

list=Linked_List()
ans="n"
print("<---**** Doubly Linked List Implementation ****--->")
while(ans=="n"):
	print("1. Apppend an element at end")
	print("2. Insert an element at a particular location")
	print("3. Remove an element")
	print("4. Display all elements")
	print("5. size of the linked list")
	choice=int(input())
	if(choice ==1): 
		data=input("Enter the item")
		list.append(data)
	elif(choice==2):
		loc=int(input("Enter the data item after which you will insert your data"))
		data=input("Enter the item to be inserted")
                list.insert(loc,data)
	elif(choice==3):
		data=input("Enter the element to be removed")
		list.remove(data)
	elif(choice==4):
		print("Elements are : ")
                list.traverse()
	elif(choice==5):
		print("Size of Linked List : ",list.size)
	else:
	        print("Invalid Option")
	ans=raw_input("Quit(y/n)")
