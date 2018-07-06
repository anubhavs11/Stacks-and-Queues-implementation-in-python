class Node(object):
	next=None
	def __init__(self,data):
		self.data=data

class Linked_List(object):
	size=0
	def __init__(self):
		self.head=None
		
	def push_beg(self,data):
		self.size=self.size+1
		newNode=Node(data)
		if self.head is None:
			self.head=newNode
		else:
			newNode.next=self.head
			self.head=newNode

	def push_end(self,data):
		self.size=self.size+1
		newNode=Node(data)
		temp=self.head;
		while(temp.next):
			temp=temp.next
		temp.next=newNode
		newNode.next=None
		
	def remove(self,data):
		self.size=self.size-1
		if self.root is None:
			print("list is already empty")
		elif self.root.data == data:
			print("Deleting.. ",data)
		else:
			temp = self.root
			while(temp.next.data != data):
				temp = temp.next
				
			print("Deleting ..",data)
			temp.next = temp.next.next
	
	def traverse(self):
		temp2=self.head
		while(temp2 is not None):
			print(temp2.data)
			temp2=temp2.next

list=Linked_List()
ans="n"
print("<---**** Linked List Implementation ****--->")
while(ans=="n"):
	print("1. Insert an element at begning")
	print("2. Insert an element at the end")
	print("3. Remove an element")
	print("4. Display all elements")
	print("5. size of the linked list")
	choice=int(input())
	if(choice ==1): 
		data=input("Enter the item")
		list.push_beg(data)
	elif(choice==2):
		data=input("Enter the item")
                list.push_end(data)
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
