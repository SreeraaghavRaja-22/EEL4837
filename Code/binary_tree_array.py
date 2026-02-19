class ArrayBinaryTree:
    def __init__(self, capacity):
        self.tree = [None] * capacity
        self.capacity = capacity

    def set_root(self, key):
        self.tree[0] = key

    def set_left(self, key, parent_index):
        left_index = 2 * parent_index + 1
        if left_index >= self.capacity:
            print("Index out of bounds")
            return
        if self.tree[parent_index] is None:
            print(f"Parent at index {parent_index} does not exist")
            return
        self.tree[left_index] = key

    def set_right(self, key, parent_index):
        right_index = 2 * parent_index + 2
        if right_index >= self.capacity:
            print("Index out of bounds")
            return
        if self.tree[parent_index] is None:
            print(f"Parent at index {parent_index} does not exist")
            return
        self.tree[right_index] = key

    def get_root(self):
        return self.tree[0]

    def print_tree(self):
        print("Tree Array:", self.tree)
        for i in range(self.capacity):
            if self.tree[i] is not None:
                print(f"Node at index {i}: {self.tree[i]}")

# Example Usage
if __name__ == "__main__":
    # Create a tree with capacity for 10 nodes
    abt = ArrayBinaryTree(10)

    # Set Root
    abt.set_root('A')

    # Set children of Root (A is at index 0)
    abt.set_left('B', 0)
    abt.set_right('C', 0)

    # Set children of B (B is at index 1)
    abt.set_left('D', 1)
    abt.set_right('E', 1)

    # Set child of C (C is at index 2)
    abt.set_right('F', 2)

    abt.print_tree()
    
    # Verify parent-child relationships
    # Parent of E (index 4) should be B (index 1) -> (4-1)//2 = 1. Correct.
