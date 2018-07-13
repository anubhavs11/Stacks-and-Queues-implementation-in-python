class HashTable(object):
	def __init__(self):
		self.size = 10
		self.keys = [None] * self.size
		self.values = [None] * self.size

	def put(self,key,data):
		self.index = self.hashfunction(key)
		while self.keys[self.index] is not None:
			
			if self.keys[self.index] == key:
				self.values[self.index] = data  #updating
			
			self.index = (self.index+1)%self.size

		self.keys[self.index] = key
		self.values[self.index] = data


	def get(self,key):
		self.index = self.hashfunction(key)

		while self.keys[self.index] is not None:
			if(self.keys[self.index] == key ):
				return key,self.index,self.values[self.index]
			self.index = (self.index+1) % self.size
		return None,None,None


	def hashfunction(self,key):
		sum=0
		for i in range(len(key)):
			sum = sum + ord(key[i])

		return sum %self.size
	
hasher = HashTable()
hasher.put("apple",12)
hasher.put("mango",11)
hasher.put("manhn",14)
hasher.put("banana",15)
hasher.put("grapes",16)

key,index,val = hasher.get("apple")
print(key ,index,val)

key,index,val = hasher.get("mango")
print(key ,index,val)
key,index,val = hasher.get("manhn")
print(key ,index,val)

key,index,val = hasher.get("banana")
print(key ,index,val)
key,index,val = hasher.get("grapes")
print(key ,index,val)

''' OUTPUT
apple 0 12
mango 1 11   #linear probing
manhn 2 14   #linear probing
banana 9 15
grapes 3 16
'''
