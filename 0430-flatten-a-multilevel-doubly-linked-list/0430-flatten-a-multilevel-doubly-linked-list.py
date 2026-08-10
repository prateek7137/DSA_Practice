class Solution(object):
    def flatten(self, head):
        if not head:
            return None

        stack = []
        current = head

        while current or stack:
            if current.child:
                if current.next:
                    stack.append(current.next)
                current.next = current.child
                current.child.prev = current
                current.child = None
            if not current.next and stack:
                next_node = stack.pop()
                current.next = next_node
                next_node.prev = current
            current = current.next

        return head