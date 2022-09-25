class Node:
    
    def __init__(self, val: int = -1, next=None, prev=None):
        self.val = val
        self.next = next
        self.prev = prev
        
        
class MyCircularQueue:
    
    def __init__(self, k: int):
        self.max_size: int = k
        self.size: int = 0
        self.tail = Node()
        self.head = Node(next=self.tail)
        self.tail.prev = self.head
        
    def enQueue(self, value: int) -> bool:
        if (self.size == self.max_size): return False
        node = Node(val=value,
                    next=self.tail,
                    prev=self.tail.prev)
        self.tail.prev.next = node
        self.tail.prev = node
        self.size += 1
        return True

    def deQueue(self) -> bool:
        if (self.size == 0): return False
        self.head.next.next.prev = self.head
        self.head.next = self.head.next.next
        self.size -= 1
        return True
        
    def Front(self) -> int:
        return self.head.next.val

    def Rear(self) -> int:
        return self.tail.prev.val

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.max_size

            
# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()