class MyStack:

    def __init__(self):
        self.st = []        

    def push(self, x: int) -> None:
        self.st.append(x)
        for _ in range(len(self.st)-1):
            self.st.append(self.st.pop(0))

    def pop(self) -> int:
        if len(self.st) == 0:
            return None
        return self.st.pop(0)

    def top(self) -> int:
        if len(self.st) == 0:
            return None
        return self.st[0]

    def empty(self) -> bool:
        return len(self.st) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()