class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1

class AVLTreeOptimized:
    def get_height(self, node):
        return node.height if node else 0
    
    def get_balance(self, node):
        return self.get_height(node.left) - self.get_height(node.right) if node else 0
    
    def right_rotate(self, y):
        x = y.left
        T2 = x.right
        
        x.right = y
        y.left = T2
        
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))
        x.height = 1 + max(self.get_height(x.left), self.get_height(x.right))
        
        return x
    
    def left_rotate(self, x):
        y = x.right
        T2 = y.left
        
        y.left = x
        x.right = T2
        
        x.height = 1 + max(self.get_height(x.left), self.get_height(x.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))
        
        return y
    
    def insert(self, node, key):
        if not node:
            return Node(key)
        
        if key < node.key:
            node.left = self.insert(node.left, key)
        elif key > node.key:
            node.right = self.insert(node.right, key)
        else:
            print(f"Key {key} already exists in the tree")
            return node
        
        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))
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
    
    def delete(self, node, key):
        if not node:
            print(f"Key {key} not found in the tree")
            return node
        
        if key < node.key:
            node.left = self.delete(node.left, key)
        elif key > node.key:
            node.right = self.delete(node.right, key)
        else:
            if not node.left:
                return node.right
            elif not node.right:
                return node.left
            
            temp = node.right
            while temp.left:
                temp = temp.left
            
            node.key = temp.key
            node.right = self.delete(node.right, temp.key)
        
        if not node:
            return node
        
        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))
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
        current = node
        while current:
            if key == current.key:
                return True
            elif key < current.key:
                current = current.left
            else:
                current = current.right
        return False
    
    def inorder(self, node, result=None):
        if result is None:
            result = []
        if node:
            self.inorder(node.left, result)
            result.append(node.key)
            self.inorder(node.right, result)
        return result
    
    def preorder(self, node, result=None):
        if result is None:
            result = []
        if node:
            result.append(node.key)
            self.preorder(node.left, result)
            self.preorder(node.right, result)
        return result
    
    def postorder(self, node, result=None):
        if result is None:
            result = []
        if node:
            self.postorder(node.left, result)
            self.postorder(node.right, result)
            result.append(node.key)
        return result
    
    def display_tree(self, node, level=0, prefix="Root: "):
        if node:
            print(" " * (level * 4) + prefix + str(node.key) + f" (h={node.height}, b={self.get_balance(node)})")
            if node.left or node.right:
                if node.left:
                    self.display_tree(node.left, level + 1, "L--- ")
                else:
                    print(" " * ((level + 1) * 4) + "L--- None")
                if node.right:
                    self.display_tree(node.right, level + 1, "R--- ")
                else:
                    print(" " * ((level + 1) * 4) + "R--- None")

def menu():
    avl = AVLTreeOptimized()
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
                result = avl.inorder(root)
                print("Inorder Traversal:", " ".join(map(str, result)))
        
        elif choice == '5':
            if root is None:
                print("Tree is empty")
            else:
                result = avl.preorder(root)
                print("Preorder Traversal:", " ".join(map(str, result)))
        
        elif choice == '6':
            if root is None:
                print("Tree is empty")
            else:
                result = avl.postorder(root)
                print("Postorder Traversal:", " ".join(map(str, result)))
        
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