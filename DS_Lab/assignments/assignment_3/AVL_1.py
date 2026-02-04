class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1

class AVLTree:
    def get_height(self, node):
        if node is None:
            return 0
        return node.height
    
    def get_balance(self, node):
        if node is None:
            return 0
        return self.get_height(node.left) - self.get_height(node.right)
    
    def update_height(self, node):
        if node is None:
            return
        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))
    
    def right_rotate(self, y):
        x = y.left
        T2 = x.right
        
        x.right = y
        y.left = T2
        
        self.update_height(y)
        self.update_height(x)
        
        return x
    
    def left_rotate(self, x):
        y = x.right
        T2 = y.left
        
        y.left = x
        x.right = T2
        
        self.update_height(x)
        self.update_height(y)
        
        return y
    
    def insert(self, node, key):
        if node is None:
            return Node(key)
        
        if key < node.key:
            node.left = self.insert(node.left, key)
        elif key > node.key:
            node.right = self.insert(node.right, key)
        else:
            print(f"Key {key} already exists in the tree")
            return node
        
        self.update_height(node)
        balance = self.get_balance(node)
        
        if balance > 1 and key < node.left.key:
            return self.right_rotate(node)
        
        if balance < -1 and key > node.right.key:
            return self.left_rotate(node)
        
        if balance > 1 and key > node.left.key:
            node.left = self.left_rotate(node.left)
            return self.right_rotate(node)
        
        if balance < -1 and key < node.right.key:
            node.right = self.right_rotate(node.right)
            return self.left_rotate(node)
        
        return node
    
    def get_min_value_node(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current
    
    def delete(self, node, key):
        if node is None:
            print(f"Key {key} not found in the tree")
            return node
        
        if key < node.key:
            node.left = self.delete(node.left, key)
        elif key > node.key:
            node.right = self.delete(node.right, key)
        else:
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            
            temp = self.get_min_value_node(node.right)
            node.key = temp.key
            node.right = self.delete(node.right, temp.key)
        
        if node is None:
            return node
        
        self.update_height(node)
        balance = self.get_balance(node)
        
        if balance > 1 and self.get_balance(node.left) >= 0:
            return self.right_rotate(node)
        
        if balance > 1 and self.get_balance(node.left) < 0:
            node.left = self.left_rotate(node.left)
            return self.right_rotate(node)
        
        if balance < -1 and self.get_balance(node.right) <= 0:
            return self.left_rotate(node)
        
        if balance < -1 and self.get_balance(node.right) > 0:
            node.right = self.right_rotate(node.right)
            return self.left_rotate(node)
        
        return node
    
    def search(self, node, key):
        if node is None:
            return False
        
        if key == node.key:
            return True
        elif key < node.key:
            return self.search(node.left, key)
        else:
            return self.search(node.right, key)
    
    def inorder(self, node):
        if node is None:
            return
        self.inorder(node.left)
        print(node.key, end=" ")
        self.inorder(node.right)
    
    def preorder(self, node):
        if node is None:
            return
        print(node.key, end=" ")
        self.preorder(node.left)
        self.preorder(node.right)
    
    def postorder(self, node):
        if node is None:
            return
        self.postorder(node.left)
        self.postorder(node.right)
        print(node.key, end=" ")
    
    def display_tree(self, node, level=0, prefix="Root: "):
        if node is not None:
            print(" " * (level * 4) + prefix + str(node.key) + f" (h={node.height}, b={self.get_balance(node)})")
            if node.left is not None or node.right is not None:
                if node.left:
                    self.display_tree(node.left, level + 1, "L--- ")
                else:
                    print(" " * ((level + 1) * 4) + "L--- None")
                if node.right:
                    self.display_tree(node.right, level + 1, "R--- ")
                else:
                    print(" " * ((level + 1) * 4) + "R--- None")

def menu():
    avl = AVLTree()
    root = None
    
    while True:
        print("\n========== AVL TREE OPERATIONS ==========")
        print("1. Insert")
        print("2. Delete")
        print("3. Search")
        print("4. Inorder Traversal")
        print("5. Preorder Traversal")
        print("6. Postorder Traversal")
        print("7. Display Tree Structure")
        print("8. Exit")
        print("=========================================")
        
        choice = input("Enter your choice: ")
        
        if choice == '1':
            key = int(input("Enter key to insert: "))
            root = avl.insert(root, key)
            print(f"Key {key} inserted successfully")
        
        elif choice == '2':
            if root is None:
                print("Tree is empty")
            else:
                key = int(input("Enter key to delete: "))
                root = avl.delete(root, key)
        
        elif choice == '3':
            if root is None:
                print("Tree is empty")
            else:
                key = int(input("Enter key to search: "))
                if avl.search(root, key):
                    print(f"Key {key} found in the tree")
                else:
                    print(f"Key {key} not found in the tree")
        
        elif choice == '4':
            if root is None:
                print("Tree is empty")
            else:
                print("Inorder Traversal: ", end="")
                avl.inorder(root)
                print()
        
        elif choice == '5':
            if root is None:
                print("Tree is empty")
            else:
                print("Preorder Traversal: ", end="")
                avl.preorder(root)
                print()
        
        elif choice == '6':
            if root is None:
                print("Tree is empty")
            else:
                print("Postorder Traversal: ", end="")
                avl.postorder(root)
                print()
        
        elif choice == '7':
            if root is None:
                print("Tree is empty")
            else:
                print("\nTree Structure:")
                avl.display_tree(root)
        
        elif choice == '8':
            print("Exiting...")
            break
        
        else:
            print("Invalid choice! Please try again")

if __name__ == "__main__":
    menu()