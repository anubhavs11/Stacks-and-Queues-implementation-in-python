class Node(object):
    def __init__(self,data):
        self.data = data
        self.height = 0
        self.leftChild  =None
        self.rightChild = None
        
class AVL(object):
    def __init__(self):
        self.root=None
        
    def calcHeight(self,node):
        if not node:
            return -1;
        return node.height;
        
    def calcBalance(self,node):
        if not node:
            return 0;
        return self.calcHeight(node.leftChild)-self.calcHeight(node.rightChild)
                # if returns >1 ---> left heavy situation
                # if returns <-1 ---> right heavy situation        
    
    def rotateRight(self,node):
        print("Rotating node to right..",node.data)
        
        self.templeftChild=node.leftChild
        self.t=self.templeftChild.rightChild
        
        self.templeftChild.rightChild=node
        node.leftChild=self.t
        node.height=max(self.node.calcHeight(node.leftChild),self.node.calcHeight(node.rightChild))+1
        self.templeftChild.height=max(self.calcHeight(self.templeftChild.leftChild),
        self.calcHeight(self.tempLeftChild.rightChild))+1
        
        return self.templeftChild;


        
    def rotateLeft(self,node):
        print("Rotating node to left..",node.data)
        
        self.temprightChild=node.rightChild
        self.t=self.temprightChild.leftChild
        
        self.temprightChild.leftChild=node
        node.rightChild=self.t
        node.height=max(self.node.calcHeight(node.leftChild),self.node.calcHeight(node.rightChild))+1
        self.temprightChild.height=max(self.calcHeight(self.temprightChild.leftChild),self.calcHeight(self.temprightChild.rightChild))+1
        
        return self.temprightChild;
        
    def insert(self,data):
        self.root=self.insertNode(data,self.root)
     
    def insertNode(self,data,node):
        if not node:
            return Node(data)
        
        elif data<node.data:
            node.leftChild=self.insertNode(data,node.leftChild)
        
        else:
            node.rightChild=self.insertNode(data,node.rightChild)
            
            
        print("Inserting",data)
        print("self.calcHeight(node.leftChild)",self.calcHeight(node.leftChild));
        print("self.calcHeight(node.rightChild)",self.calcHeight(node.rightChild));
        
        self.val=max(self.calcHeight(node.leftChild),self.calcHeight(node.rightChild))
        print("val",self.val)
        node.height = 1 + self.val
        print("height",node.height)
        
        return self.settleViolation(data,node)
              
    def settleViolation(self,data,node):
        self.balance=self.calcBalance(node)
        print("checking violations..",self.balance)
        if self.balance>1 and data<node.leftChild.data :
            print("left left heavy situation...")
            return self.rotateRight(node)
        
        if self.balance<-1 and data>node.rightChild.data :
            print("right right heavy situation")
            return self.rotateLeft(node)
        
        if self.balance>1 and data>node.leftChild.data:
            print("left right heavy situation")
            node.leftChild=self.rotateLeft(node.leftChild)
            return self.rotateRight(node)
 
        if self.balance<-1 and data<node.rightChild.data:
            print("right left heavy situation")
            node.rightChild=self.rotateRight(node.rightChild)
            return self.rotateLeft(node)
                            
        return node;
            
    def traverse(self):
        if not self.root:
            print("None")
        else:
            self.Inorder(self.root)
            
    def Inorder(self,node):
        if node.leftChild:
            self.Inorder(node.leftChild)
            
        print(node.data," : ",self.calcHeight(node))
        
        if node.rightChild is not None:
            self.Inorder(node.rightChild)
            
       
ob=AVL()
ob.insert(1)
ob.insert(2)
ob.insert(-3)
ob.insert(3)
ob.traverse()
