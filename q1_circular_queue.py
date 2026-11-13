class CircularQueue:
    def __init__(self, size):
        self.size = size
        self.queue = [None] * size
        self.front = 0
        self.rear = 0
        self.count = 0

    def enqueue(self, data):
        # 1. Check if full
        if self.count == self.size:
            print(f"Overflow! Queue is full, cannot add {data}")
            return
        
        # 2. Add item at rear and wrap rear around if needed
        self.queue[self.rear] = data
        self.rear = (self.rear + 1) % self.size
        self.count += 1
        print(f"Enqueued {data}")

    def dequeue(self):
        # 1. Check if empty
        if self.count == 0:
            print("Underflow! Queue is empty")
            return
        
        # 2. Remove item at front and wrap front around if needed
        removed = self.queue[self.front]
        self.queue[self.front] = None
        self.front = (self.front + 1) % self.size
        self.count -= 1
        print(f"Dequeued {removed}")

    def display(self):
        if self.count == 0:
            print("Queue is empty")
            return
        
        items = []
        for i in range(self.count):
            index = (self.front + i) % self.size
            items.append(self.queue[index])
        print("Current Queue:", items)


# --- Test the Circular Queue ---
cq = CircularQueue(3)   # Capacity is 3
cq.enqueue(10)          # [10]
cq.enqueue(20)          # [10, 20]
cq.enqueue(30)          # [10, 20, 30] -> Now Full!
cq.enqueue(40)          # Prints Overflow!

cq.dequeue()            # Removes 10 -> frees index 0
cq.enqueue(40)          # Wraps around and puts 40 into index 0!
cq.display()            # Output: Current Queue: [20, 30, 40]