class Heap(object):

    HEAP_SIZE=10
    def __init__(self):
        self.heap = [0]*Heap.HEAP_SIZE
        self.currentPosition = -1

    def insert(self,item):
        if self.isFull():
            print("Heap is full...")
            return
        self.currentPosition = self.currentPosition + 1
        self.heap[self.currentPosition] = item
        self.fixUp(self.currentPosition)

    def fixUp(self,index):
        parentIndex = int((index-1)/2)

        while(parentIndex >= 0 and self.heap[parentIndex] < self.heap[index] ):
            temp = self.heap[index]
            self.heap[index] = self.heap[parentIndex]
            self.heap[parentIndex] = temp
            parentIndex = (int)((index-1)/2)

    def heapsort(self):
        for i in range(0,self.currentPosition+1):
            self.fix(0,self.currentPosition-i)
            temp = self.heap[0]
            print(" %d " % temp)
            self.heap[0] = self.heap[self.currentPosition-i]
            self.heap[self.currentPosition-i] = temp
            

    def fix(self,i,j):
        largest = i
        l=2*i+1
        r=2*i+2
        if(l<j and self.heap[l]>self.heap[largest]):
            largest = l;
        if(r<j and self.heap[r]>self.heap[largest]):
            largest = r;
        if(largest != i):
            temp = self.heap[largest]
            self.heap[largest]=self.heap[i]
            self.heap[i] = temp
            self.fix(largest,j)

        
    def fixDown(self,index,upto):
        while index <= upto:
            leftChild = 2*index+1
            rightChild = 2*index+2
            if leftChild < upto:
                childToSwap = None
                if rightChild > upto :
                    childToSwap = leftChild
                else:
                    if self.heap[leftChild]>self.heap[rightChild]:
                        childToSwap = leftChild
                    else:
                        childToSwap = rightChild
                if self.heap[index] < self.heap[childToSwap]:
                    temp = self.heap[index]
                    self.heap[index] = self.heap[childToSwap]
                    self.heap[childToSwap] = temp
                else:
                    break;
                index = childToSwap
            else:
                break;

            
    def isFull(self):
        if(self.currentPosition == self.HEAP_SIZE):
            return True
        else:
            return False

    def traverse(self):
        print("Elements are:")
        for i in range(0,self.currentPosition+1):
            print(self.heap[i])

heap = Heap()
heap.insert(10)
heap.insert(4)
heap.insert(-10)
heap.insert(20)

heap.traverse()
