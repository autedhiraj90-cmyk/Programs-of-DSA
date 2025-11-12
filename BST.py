class Node:
    key = None
    left = None
    right = None

def create_node(key):
    node = Node()
    node.key = key
    node.left = None
    node.right = None
    return node

def insert(root, key):
    if root is None:
        return create_node(key)
    if key < root.key:
        root.left = insert(root.left, key)
    elif key > root.key:
        root.right = insert(root.right, key)
    else:
        print(f"Duplicate entry {key} ignored!")
    return root

def min_value_node(node):
    current = node
    while current.left:
        current = current.left
    return current

def delete(root, key):
    if root is None:
        return root
    if key < root.key:
        root.left = delete(root.left, key)
    elif key > root.key:
        root.right = delete(root.right, key)
    else:
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left
        temp = min_value_node(root.right)
        root.key = temp.key
        root.right = delete(root.right, temp.key)
    return root

def search(root, key):
    if root is None:
        return False
    if root.key == key:
        return True
    elif key < root.key:
        return search(root.left, key)
    else:
        return search(root.right, key)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.key, end=" ")
        inorder(root.right)

def preorder(root):
    if root:
        print(root.key, end=" ")
        preorder(root.left)
        preorder(root.right)

def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.key, end=" ")

def depth(root):
    if root is None:
        return 0
    return max(depth(root.left), depth(root.right)) + 1

def display_leaves(root):
    if root:
        if root.left is None and root.right is None:
            print(root.key, end=" ")
        display_leaves(root.left)
        display_leaves(root.right)

def main():
    root = None
    while True:
        print("\nBinary Search Tree Operations")
        print("1. Insert")
        print("2. Delete")
        print("3. Search")
        print("4. Display Tree (Inorder)")
        print("5. Display Depth of Tree")
        print("6. Display Tree (Preorder)")
        print("7. Display Tree (Postorder)")
        print("8. Display Leaf Nodes")
        print("9. Exit")

        choice = int(input("Enter choice: "))

        match choice:
            case 1:
                val = int(input("Enter value to insert: "))
                root = insert(root, val)
            case 2:
                val = int(input("Enter value to delete: "))
                root = delete(root, val)
            case 3:
                val = int(input("Enter value to search: "))
                print("Found" if search(root, val) else "Not Found")
            case 4:
                inorder(root)
                print()
            case 5:
                print("Depth of tree:", depth(root))
            case 6:
                preorder(root)
                print()
            case 7:
                postorder(root)
                print()
            case 8:
                display_leaves(root)
                print()
            case 9:
                break
            case _:
                print("Invalid choice. Try again.")

main()
