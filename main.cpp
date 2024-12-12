#include <iostream>
#include <vector>
#include <algorithm>
#include "AVL_tree.h"
using namespace std;

int main()
{
    AVL_tree *tree = new AVL_tree();
    Node *tmp;
    // vector<int> v = {1, 3, 5, 7, 9, 12, 15, 17, 21, 23, 25, 27};
    vector<int> v = {14, 10, 20, 30, 18, 15};
    for (auto it : v)
    {
        tmp = new Node(it);
        tree->InsertNode(tmp);
    }
    tree->TravelNLR();
}

// class Student
// {
// public:
//     string name;
//     int id;

//     Student(string name, int id) : name(name), id(id) {}
// };

// class AVLTree
// {
// public:
//     class Node
//     {
//     public:
//         Student data;
//         Node *left;
//         Node *right;
//         Node *parent;
//         int height;

//         Node(Student data) : data(data), left(nullptr), right(nullptr), parent(nullptr), height(1) {}
//     };

//     Node *root;

//     AVLTree() : root(nullptr) {}

//     // Cập nhật chiều cao của node
//     int height(Node *node)
//     {
//         if (node == nullptr)
//             return 0;
//         return node->height;
//     }

//     // Cập nhật chiều cao của node
//     void updateHeight(Node *node)
//     {
//         if (node != nullptr)
//         {
//             node->height = 1 + max(height(node->left), height(node->right));
//         }
//     }

//     // Tính toán độ cân bằng của node
//     int getBalance(Node *node)
//     {
//         if (node == nullptr)
//             return 0;
//         return height(node->left) - height(node->right);
//     }

//     // Xoay phải (Right Rotate)
//     void rightRotate(Node *&y)
//     {
//         Node *x = y->left;
//         Node *T2 = x->right;

//         // Thực hiện xoay
//         x->right = y;
//         y->left = T2;

//         // Cập nhật cha của các node
//         if (T2 != nullptr)
//             T2->parent = y;
//         x->parent = y->parent;
//         y->parent = x;

//         // Cập nhật chiều cao
//         updateHeight(y);
//         updateHeight(x);

//         // Thay đổi gốc của cây
//         y = x;
//     }

//     // Xoay trái (Left Rotate)
//     void leftRotate(Node *&x)
//     {
//         Node *y = x->right;
//         Node *T2 = y->left;

//         // Thực hiện xoay
//         y->left = x;
//         x->right = T2;

//         // Cập nhật cha của các node
//         if (T2 != nullptr)
//             T2->parent = x;
//         y->parent = x->parent;
//         x->parent = y;

//         // Cập nhật chiều cao
//         updateHeight(x);
//         updateHeight(y);

//         // Thay đổi gốc của cây
//         x = y;
//     }

//     // Chèn một node vào cây AVL
//     Node *insert(Node *node, Student student)
//     {
//         // Chèn vào cây nhị phân tìm kiếm
//         if (node == nullptr)
//             return new Node(student);

//         if (student.id < node->data.id)
//         {
//             node->left = insert(node->left, student);
//             node->left->parent = node;
//         }
//         else if (student.id > node->data.id)
//         {
//             node->right = insert(node->right, student);
//             node->right->parent = node;
//         }
//         else
//         {
//             // Nếu id đã tồn tại, không chèn nữa
//             return node;
//         }

//         // Cập nhật chiều cao của node hiện tại
//         updateHeight(node);

//         // Kiểm tra độ cân bằng và thực hiện xoay nếu cần
//         int balance = getBalance(node);

//         // Nếu node bị lệch trái trái (Left-Left)
//         if (balance > 1 && student.id < node->left->data.id)
//         {
//             rightRotate(node);
//         }
//         // Nếu node bị lệch phải phải (Right-Right)
//         else if (balance < -1 && student.id > node->right->data.id)
//         {
//             leftRotate(node);
//         }
//         // Nếu node bị lệch trái phải (Left-Right)
//         else if (balance > 1 && student.id > node->left->data.id)
//         {
//             leftRotate(node->left);
//             rightRotate(node);
//         }
//         // Nếu node bị lệch phải trái (Right-Left)
//         else if (balance < -1 && student.id < node->right->data.id)
//         {
//             rightRotate(node->right);
//             leftRotate(node);
//         }

//         return node;
//     }

//     // Tìm kiếm một sinh viên theo id
//     Node *search(Node *node, int id)
//     {
//         if (node == nullptr || node->data.id == id)
//             return node;

//         if (id < node->data.id)
//             return search(node->left, id);

//         return search(node->right, id);
//     }

//     // Hàm chèn sinh viên vào cây
//     void insert(Student student)
//     {
//         root = insert(root, student);
//     }

//     // Hàm tìm kiếm sinh viên trong cây
//     bool search(int id)
//     {
//         Node *result = search(root, id);
//         return result != nullptr;
//     }

//     // Duyệt cây theo NLR (Preorder)
//     void NLR(Node *node)
//     {
//         if (node == nullptr)
//             return;
//         cout << "ID: " << node->data.id << ", Name: " << node->data.name << endl;
//         NLR(node->left);
//         NLR(node->right);
//     }

//     // Hàm in cây theo thứ tự NLR
//     void print()
//     {
//         NLR(root);
//     }
// };

// int main()
// {
//     AVLTree tree;

//     // Thêm sinh viên vào cây
//     tree.insert(Student("Alice", 15));
//     tree.insert(Student("Bob", 9));
//     tree.insert(Student("Charlie", 5));
//     tree.insert(Student("David", 21));
//     tree.insert(Student("Eve", 17));

//     // In ra cây theo thứ tự NLR (preorder)
//     cout << "Tree in NLR order:\n";
//     tree.print();

//     // Tìm kiếm sinh viên theo ID
//     int searchId = 21;
//     if (tree.search(searchId))
//     {
//         cout << "Student with ID " << searchId << " found in the tree." << endl;
//     }
//     else
//     {
//         cout << "Student with ID " << searchId << " not found in the tree." << endl;
//     }

//     return 0;
// }
