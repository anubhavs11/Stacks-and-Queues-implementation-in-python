class Node(object):
    def __init__(self,data):
        self.data=data
        self.leftChild=None
        self.rightChild=None
        
class Binary_Search_Tree(object):
    def __init__(self):
        self.root=None
        
    # main methodfor insertion
    def insert(self,data):
        if self.root is None:
            self.root=Node(data)
        else:
            self.insertNode(data,self.root)
        
    #don't call <-- recursive method -->
    def insertNode(self,data,node):
        if data<node.data:
            if node.leftChild:
                self.insertNode(data,node.leftChild)
            else:
                node.leftChild=Node(data)
        else:
            if node.rightChild:
                self.insertNode(data,node.rightChild)
            else:
                node.rightChild=Node(data)
            
    #main method for min_calculation
    def getMin(self):
        if self.root is not None:
            self.getMinVal(self.root)
            
    #don't call <-- recursive method -->        
    def getMinVal(self,node):
        if node.leftChild is not None:
            self.getMinVal(node.leftChild)
        else:
            print("Minimmum Value: ",node.data)
    
    #main method for max_calculation        
    def getMax(self):
        if self.root is not None:
            self.getMaxVal(self.root)
            
    #don't call <-- recursive method -->            
    def getMaxVal(self,node):
        if node.rightChild is not None:
            self.getMaxVal(node.rightChild)
        else:
            print("Maximum Value:",node.data)
            
                 
    #main method for Inorder traversal
    def Inorder(self):
        print("InOrder Traversal")
        if self.root:
            self.InOrderTraverse(self.root)
    
    #don't call <-- recursive method -->
    def InOrderTraverse(self,node):
        if node.leftChild:
            self.InOrderTraverse(node.leftChild)
            
        print(node.data)
        
        if node.rightChild:
            self.InOrderTraverse(node.rightChild)
    
                 
    #main method for Inorder traversal
    def Preorder(self):
        print("PreOrder Traversal")
        if self.root:
            self.PreTraverse(self.root)
    
    #don't call <-- recursive method -->
    def PreTraverse(self,node):
        print(node.data)
        
        if node.leftChild:
            self.PreTraverse(node.leftChild)
        
        if node.rightChild:
            self.PreTraverse(node.rightChild)


    #main method for Inorder traversal
    def Postorder(self):
        print("PostOrder Traversal")
        if self.root:
            self.PostOrderTraverse(self.root)
    
    #don't call <-- recursive method -->
    def PostOrderTraverse(self,node):        
        if node.leftChild:
            self.PostOrderTraverse(node.leftChild)
        
        if node.rightChild:
            self.PostOrderTraverse(node.rightChild)
            
        print(node.data)
            
    def removeNode(self,node,data):
        if not node:
            return node
        if data<node.data:
            node.leftChild=self.removeNode(node.leftChild,data)
        elif data>node.data:
            node.rightChild=self.removeNode(node.rightChild,data)
        else:
            if not node.leftChild and not node.rightChild:
                print("Removing leaf node..")
                del node
                return None
            if not node.leftChild:
                print("Removing a node having single right child..")
                self.tempNode=node.rightChild
                del node
                return self.tempNode
            if not node.rightChild:
                print("Removing a node having single left child..")
                self.tempNode=node.leftChild
                del node
                return self.tempNode
            print("Removing node having two childs..")
            self.tempNode=self.getPredecessor(node.leftChild,data)
            node.data=self.tempNode.data
            node.leftChild=self.removeNode(node.leftChild,self.tempNode.data)
        return node;
                
    def getPredecessor(self,node,data):
        if node.rightChild:
            node.rightChild=self.getPredecessor(node.rightChild,data)
        return node
        
    def remove(self,data):
        if self.root:
            self.root=self.removeNode(self.root,data)
    
                                                
ob=Binary_Search_Tree()
ob.insert(10)
ob.insert(5)
ob.insert(4)
ob.insert(2)
ob.insert(68)
ob.insert(7)
ob.insert(87)
ob.insert(9)
ob.insert(11)
ob.getMin()
ob.getMax()

ob.Inorder()
ob.Preorder()
ob.Postorder()

ob.remove(10)
