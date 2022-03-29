COUNT = [10]


class node:
    def __init__(self, data):
        self.data = data
        self.height = 1
        self.left = None
        self.right = None


def max(a, b):
    return a if a > b else b


def height(root):
    return 0 if root is None else root.height


def balancefactor(root):
    return 0 if root is None else height(root.left) - height(root.right)


def leftrotate(root):
    temp1 = root.right
    temp2 = temp1.left
    temp1.left = root
    root.right = temp2
    root.height = 1 + max(height(root.left), height(root.right))
    temp1.height = 1 + max(height(temp1.left), height(temp1.right))
    return temp1


def rightrotate(root):
    temp1 = root.left
    temp2 = temp1.right
    temp1.right = root
    root.left = temp2
    root.height = 1 + max(height(root.left), height(root.right))
    temp1.height = 1 + max(height(temp1.left), height(temp1.right))
    return temp1


def minimum(root):
    return root if ((root is None) or (root.left is None)) else minimum(root.left)


def maximum(root):
    return root if ((root is None) or (root.right is None)) else maximum(root.right)


def search(root, value):
    if (root is None) or (root.data == value):
        return root
    else:
        return search(root.left, value) if (value < root.data) else search(root.right, value)


def insertnode(root, value):
    if root is None:
        return node(value)
    if value < root.data:
        root.left = insertnode(root.left, value)
    elif value > root.data:
        root.right = insertnode(root.right, value)
    else:
        return root
    root.height = 1 + max(height(root.left), height(root.right))
    bf = balancefactor(root)
    if (bf > 1) and (value < root.left.data):
        return rightrotate(root)
    if (bf < -1) and (value > root.right.data):
        return leftrotate(root)
    if (bf > 1) and (value > root.left.data):
        root.left = leftrotate(root.left)
        return rightrotate(root)
    if (bf < -1) and (value < root.right.data):
        root.right = rightrotate(root.right)
        return leftrotate(root)
    return root


def deletenode(root, value):
    if root is None:
        return root
    elif value < root.data:
        root.left = deletenode(root.left, value)
    elif value > root.data:
        root.right = deletenode(root.right, value)
    else:
        if root.left is None:
            temp = root
            root = root.right
        elif root.right is None:
            temp = root
            root = root.left
        else:
            print("Replace with 1.Inorder Predecessor 2.Inorder Successor")
            ch = int(input("Enter your Choice: "))
            if ch == 1:
                temp = maximum(root.left)
                root.data = temp.data
                root.left = deletenode(root.left, temp.data)
            else:
                temp = minimum(root.right)
                root.data = temp.data
                root.right = deletenode(root.right, temp.data)
    if root is None:
        return root
    root.height = 1 + max(height(root.left), height(root.right))
    bf = balancefactor(root)
    if (bf > 1) and (value < root.left.data):
        return rightrotate(root)
    if (bf < -1) and (value > root.right.data):
        return leftrotate(root)
    if (bf > 1) and (value > root.left.data):
        root.left = leftrotate(root.left)
        return rightrotate(root)
    if (bf < -1) and (value < root.right.data):
        root.right = rightrotate(root.right)
        return leftrotate(root)
    return root


def display(root, space):
    if root is None:
        return
    space = space + COUNT[0]
    display(root.right, space)
    print()
    for i in range(COUNT[0], space):
        print(end=" ")
    print(root.data)
    display(root.left, space)


root = None
print("AVL Tree Implementation")
print("1.Insert Node\t2.Delete Node\t3.Display\t4.End")
while True:
    choice = int(input("\nEnter your choice: "))
    if choice == 1:
        value = int(input("Enter Node: "))
        root = insertnode(root, value)
        print("Node Inserted")
    elif choice == 2:
        if root is None:
            print("Tree is Empty")
        else:
            value = int(input("Enter Node: "))
            temp = search(root, value)
            if temp is None:
                print("Node is not in Tree")
            else:
                root = deletenode(root, value)
                print("Node Deleted")
    elif choice == 3:
        if root is None:
            print("Tree is Empty")
        else:
            display(root, 0)
    elif choice == 4:
        print("Thank You")
        break
    else:
        print("Invalid Choice")
