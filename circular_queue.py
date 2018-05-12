class Node(object):
    next=None
    def __init__(self,data):
            self.data=data
    
class Circular_Queue(object):
    def __init__(self):
        self.head=None
        self.tail=None
        self.size=0
    
    def Size(self):
        return self.size
        
    def insert(self,data,loc):
        found=False
        newNode=Node(data)
        if(self.head==None):
            self.size=self.size+1
            found=True
            self.head=self.tail=newNode
            self.head.next=self.tail
            self.tail=self.head
        else:
            cur=self.head
            if(self.head.data==loc):
                found=True
                self.size=self.size+1
                newNode.next=self.head.next
                self.head.next=newNode
            else:
                cur=cur.next    
                while(cur.data!=self.head.data):
                    if(cur.data==loc):
                        self.size=self.size+1
                        found=True
                        newNode.next=cur.next
                        cur.next=newNode
                        if(newNode.next==self.head):
                            self.tail=self.head
                        break
                    else:         
                        cur=cur.next
        if(found==False):
            print("Not inserted")
        else:
            print("Inserted : ",data)                    
                
    def showAll(self):
        print("Showing elements..")
        temp=self.head
        print(temp.data)
        temp=temp.next
        while(temp.data!=self.head.data):
            print(temp.data)
            temp=temp.next
               
    def pop(self,data):
        self.size=self.size-1
        if(self.head.data==data):
            self.head=self.head.next
            print("removed : ",data)
        else:
            temp=self.head
            while(temp.next.data!=self.head.data):
                if(temp.next.data==data):
                    temp.next=temp.next.next
                    print("removed : ",data)
                    break
                else:
                    temp=temp.next
                
               
obj=Circular_Queue()
obj.insert(4,0) # 4 will be inserted in circular queue
obj.insert(5,4) # 5 will be inserted after 4 in circular queue
obj.insert(3,5) # 3 will be inserted after 5 in circular queue
obj.showAll()
obj.pop(5)
obj.showAll()
print("size :",obj.Size())