/*
斐波那契堆是一系列具有最小堆序 min-heap ordered 的有根树的集合。
也就是说，每棵树都遵循最小堆性质 min-heap property：
每个节点的关键字大于或等于它的父节点的关键字。
（树是无序的，所以并不需要关心树是怎么排序的）

节点的所有孩子节点都被链接成一个环形的双向链表。
环形双向链表在斐波那契堆中有两个优点：
1.可以在 O(1) 时间内从一个环形双向链表的任意位置插入一个节点和删除节点
2.给定两个这种链表，可以在 O(1) 时间内将他们链接成一个环形双向链表

相比于二叉堆，斐波那契堆的优势在于合并两个堆，且支持DECREASE-KEY和DELETE操作

*/
#include<bits/stdc++.h>
template <typename T>
class FibonacciHeap {
private:
    // 节点结构定义
    struct Node {
        T key;          // 节点的关键字值
        int degree;     // 子节点的数量
        bool marked;    // 标记，用于级联剪切操作
        Node* parent;   // 父节点指针
        Node* child;    // 指向任意一个子节点的指针
        Node* left;     // 左兄弟指针（环形双向链表）
        Node* right;    // 右兄弟指针（环形双向链表）
        
        // 构造函数
        Node(T k) : key(k), degree(0), marked(false), parent(nullptr), 
                    child(nullptr), left(this), right(this) {}
    };

    Node* minNode;      // 指向根表中最小节点的指针
    int nodeCount;      // 堆中节点的总数量

    // 将node添加到以target为代表的环形链表中
    void addToCircularList(Node* target, Node* node) {
        if (target == nullptr) {
            node->left = node;
            node->right = node;
            return;
        }
        
        node->right = target->right;
        node->left = target;
        target->right->left = node;
        target->right = node;
    }
    // 从环形链表中移除节点
    void removeFromCircularList(Node* node) {
        if (node->right == node) {
            // 链表中只有一个节点
            return;
        }
        
        node->left->right = node->right;
        node->right->left = node->left;
    }
    // 合并两个环形链表
    Node* mergeLists(Node* a, Node* b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        
        // 交换两个链表的一部分连接
        Node* temp = a->right;
        a->right = b->right;
        b->right->left = a;
        b->right = temp;
        temp->left = b;
        
        // 返回关键字较小的节点
        return (a->key <= b->key) ? a : b;
    }
public:
    // 构造函数
    FibonacciHeap() : minNode(nullptr), nodeCount(0) {}
    
    // 判断堆是否为空
    bool isEmpty() const {
        return minNode == nullptr;
    }
    
    // 获取节点数量
    int size() const {
        return nodeCount;
    }
    
    // 获取最小关键字
    T findMin() const {
        if (isEmpty()) {
            throw std::runtime_error("堆为空");
        }
        return minNode->key;
    }

    // 插入新节点
    void insert(T key) {
        Node* newNode = new Node(key);
        
        if (isEmpty()) {
            // 如果堆为空，新节点成为最小节点
            minNode = newNode;
        } else {
            // 将新节点添加到根表中
            addToCircularList(minNode, newNode);
            
            // 如果新节点的关键字小于当前最小节点，更新最小节点
            if (key < minNode->key) {
                minNode = newNode;
            }
        }
        
        nodeCount++;
    }
    
    // 合并另一个斐波那契堆
    void unionWith(FibonacciHeap<T>& other) {
        if (other.isEmpty()) {
            return;
        }

        //找minNode
        if (isEmpty()) {
            minNode = other.minNode;
        } else {
            // 合并两个根表
            minNode = mergeLists(minNode, other.minNode);
        }
        
        nodeCount += other.nodeCount;
        
        // 清空other堆
        other.minNode = nullptr;
        other.nodeCount = 0;
    }
private:
    // 将child设为parent的子节点
    void linkTrees(Node* child, Node* parent) {
        // 从根表中移除child
        removeFromCircularList(child);
        
        // 让child成为parent的子节点
        if (parent->child == nullptr) {
            parent->child = child;
            child->left = child;
            child->right = child;
        } else {
            addToCircularList(parent->child, child);
        }
        
        // 更新父子关系
        child->parent = parent;
        parent->degree++;
        child->marked = false;
    }
    
    // 合并度数相同的树
    void consolidate() {
        // 根据节点数量确定数组大小
        int maxDegree = static_cast<int>(log(nodeCount) / log(1.618)) + 1;
        std::vector<Node*> degreeTable(maxDegree, nullptr);
        
        // 收集所有根节点
        std::vector<Node*> roots;
        Node* current = minNode;
        do {
            roots.push_back(current);
            current = current->right;
        } while (current != minNode);
        
        // 遍历所有根节点进行合并
        for (Node* root : roots) {
            int degree = root->degree;
            
            // 当存在相同度数的树时进行合并
            while (degreeTable[degree] != nullptr) {
                Node* other = degreeTable[degree];
                
                // 确保root始终是关键字较小的节点
                if (root->key > other->key) {
                    std::swap(root, other);
                }
                
                // 合并树
                linkTrees(other, root);
                
                // 清除该度数的记录
                degreeTable[degree] = nullptr;
                degree++;
            }
            
            // 记录当前度数的树
            degreeTable[degree] = root;
        }
        
        // 重建根表并找到新的最小节点
        minNode = nullptr;
        for (Node* node : degreeTable) {
            if (node != nullptr) {
                // 创建新的根表
                if (minNode == nullptr) {
                    minNode = node;
                    node->left = node;
                    node->right = node;
                } else {
                    addToCircularList(minNode, node);
                    if (node->key < minNode->key) {
                        minNode = node;
                    }
                }
            }
        }
    }

public:
    // 提取最小节点
    T extractMin() {
        if (isEmpty()) {
            throw std::runtime_error("堆为空");
        }
        
        Node* oldMin = minNode;
        T result = oldMin->key;
        
        // 将最小节点的所有子节点添加到根表
        if (oldMin->child != nullptr) {
            Node* child = oldMin->child;
            Node* tempChild;
            do {
                tempChild = child;
                child = child->right;
                
                // 将子节点添加到根表
                tempChild->parent = nullptr;
                addToCircularList(minNode, tempChild);
            } while (child != oldMin->child);
        }
        
        // 从根表中移除最小节点
        if (oldMin == oldMin->right) {
            // 堆中只有一个节点
            minNode = nullptr;
        } else {
            minNode = oldMin->right;
            removeFromCircularList(oldMin);
            consolidate();
        }
        
        delete oldMin;
        nodeCount--;
        
        return result;
    }
private:
    // 剪切操作：将子节点从父节点中分离，并添加到根表
    void cut(Node* child, Node* parent) {
        // 从父节点的子链表中移除child
        if (parent->child == child) {
            if (child->right == child) {
                parent->child = nullptr;
            } else {
                parent->child = child->right;
            }
        }
        
        removeFromCircularList(child);
        parent->degree--;
        
        // 将child添加到根表
        addToCircularList(minNode, child);
        child->parent = nullptr;
        child->marked = false;
    }
    
    // 级联剪切：递归向上处理被标记的节点
    void cascadingCut(Node* node) {
        Node* parent = node->parent;
        if (parent != nullptr) {
            if (!node->marked) {
                // 首次失去子节点，标记节点
                node->marked = true;
            } else {
                // 已标记节点再次失去子节点，执行剪切
                cut(node, parent);
                cascadingCut(parent); // 递归处理父节点
            }
        }
    }

public:
    // 公共接口-节点句柄类
    class NodeHandle {
        friend class FibonacciHeap;
    private:
        Node* node;
        NodeHandle(Node* n) : node(n) {}
    public:
        NodeHandle() : node(nullptr) {}
    };
    
    // 插入并返回句柄
    NodeHandle insertWithHandle(T key) {
        Node* newNode = new Node(key);
        
        // 与普通插入相同的逻辑...
        if (isEmpty()) {
            minNode = newNode;
        } else {
            addToCircularList(minNode, newNode);
            if (key < minNode->key) {
                minNode = newNode;
            }
        }
        
        nodeCount++;
        return NodeHandle(newNode);
    }
    
    // 减小关键字
    bool decreaseKey(NodeHandle handle, T newKey) {
        Node* node = handle.node;
        
        // 新关键字必须小于当前关键字
        if (newKey > node->key) {
            return false;
        }
        
        node->key = newKey;
        Node* parent = node->parent;
        
        // 如果违反了最小堆性质
        if (parent != nullptr && node->key < parent->key) {
            cut(node, parent);
            cascadingCut(parent);
        }
        
        // 如果node成为新的最小节点
        if (node->key < minNode->key) {
            minNode = node;
        }
        
        return true;
    }
    
    // 删除节点
    void deleteNode(NodeHandle handle) {
        // 将节点的关键字减小到极小值
        decreaseKey(handle, std::numeric_limits<T>::min());
        
        // 提取最小值（即删除该节点）
        extractMin();
    }
private:
    // 递归删除节点及其子树
    void deleteTree(Node* node) {
        if (node != nullptr) {
            Node* current = node;
            Node* next;
            
            do {
                if (current->child != nullptr) {
                    deleteTree(current->child);
                }
                
                next = current->right;
                delete current;
                current = next;
            } while (current != node);
        }
    }

public:
    // 析构函数
    ~FibonacciHeap() {
        clear();
    }
    
    // 清空堆
    void clear() {
        if (minNode != nullptr) {
            deleteTree(minNode);
            minNode = nullptr;
            nodeCount = 0;
        }
    }
};