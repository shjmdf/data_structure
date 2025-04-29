#include<bits/stdc++.h>
using namespace std;

// FGK节点
struct FGKNode {
    int weight;             // 权重/频率
    int number;             // 节点编号
    int symbol;             // 符号(-1表示内部节点、-2表示NYT节点)
    FGKNode *left, *right, *parent;
    
    FGKNode(int w, int num, int sym) : 
        weight(w), number(num), symbol(sym), 
        left(nullptr), right(nullptr), parent(nullptr) {}
};

class FGKTree {
private:
    FGKNode* root;          // 树的根节点
    FGKNode* NYT;           // Not Yet Transmitted节点
    vector<FGKNode*> nodes; // 存储所有符号节点的指针
    int nextNumber;         // 下一个分配的编号

    // 交换两个节点(保持树结构)
    void swapNodes(FGKNode* a, FGKNode* b) {
        // 交换符号和权重，而非指针
        swap(a->symbol, b->symbol);
        swap(a->weight, b->weight);
        
        // 更新符号对应的节点指针
        if(a->symbol >= 0) nodes[a->symbol] = a;
        if(b->symbol >= 0) nodes[b->symbol] = b;
    }
    
    // 查找可交换的节点(具有相同权重但更高编号的节点)
    FGKNode* findNodeToSwap(FGKNode* node) {
        int weight = node->weight;
        FGKNode* swapNode = nullptr;
        
        // 遍历所有节点查找可交换的节点
        for(FGKNode* current : getAllNodes()) {
            if(current != node && 
               current->weight == weight && 
               current->number > node->number && 
               !isAncestor(current, node)) {
                
                if(!swapNode || current->number > swapNode->number) {
                    swapNode = current;
                }
            }
        }
        return swapNode;
    }
    
    // 检查a是否是b的祖先
    bool isAncestor(FGKNode* a, FGKNode* b) {
        while(b->parent) {
            if(b->parent == a) return true;
            b = b->parent;
        }
        return false;
    }
    
    // 获取所有节点(用于遍历)
    vector<FGKNode*> getAllNodes() {
        vector<FGKNode*> result;
        queue<FGKNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            FGKNode* node = q.front();
            q.pop();
            result.push_back(node);
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
        return result;
    }

public:
    // 构造函数
    FGKTree(int numSymbols) : nextNumber(2 * numSymbols - 1) {
        // 初始只有一个NYT节点
        NYT = new FGKNode(0, nextNumber--, -2);
        root = NYT;
        
        // 初始化符号节点映射
        nodes.resize(numSymbols + 1, nullptr);
    }
    
    // 析构函数
    ~FGKTree() {
        function<void(FGKNode*)> deleteNode = [&](FGKNode* node) {
            if(!node) return;
            deleteNode(node->left);
            deleteNode(node->right);
            delete node;
        };
        deleteNode(root);
    }
    
    // 更新树(处理一个符号)
    void update(int symbol) {
        if(nodes[symbol]) {
            // 符号已存在
            updateExistingSymbol(nodes[symbol]);
        } else {
            // 新符号
            addNewSymbol(symbol);
        }
    }
    
    // 添加新符号
    void addNewSymbol(int symbol) {
        // 分裂NYT节点
        FGKNode* oldNYT = NYT;
        
        // 创建新的NYT节点
        FGKNode* newNYT = new FGKNode(0, nextNumber--, -2);
        
        // 创建新的符号节点
        FGKNode* symbolNode = new FGKNode(1, nextNumber--, symbol);
        nodes[symbol] = symbolNode;
        
        // 连接新节点
        oldNYT->left = newNYT;
        oldNYT->right = symbolNode;
        newNYT->parent = oldNYT;
        symbolNode->parent = oldNYT;
        
        // 更新原NYT为内部节点
        oldNYT->symbol = -1;
        oldNYT->weight = 1;
        
        // 指向新的NYT节点
        NYT = newNYT;
        
        // 更新路径
        updateNodePath(oldNYT->parent);
    }
    
    // 更新已存在的符号
    void updateExistingSymbol(FGKNode* node) {
        // 增加节点权重
        node->weight++;
        
        // 调整树结构
        while(node != root) {
            // 查找可交换的节点
            FGKNode* swapNode = findNodeToSwap(node);
            if(swapNode && swapNode != node->parent) {
                swapNodes(node, swapNode);
            }
            
            // 更新父节点权重
            node = node->parent;
            node->weight++;
        }
    }
    
    // 更新节点路径上的权重
    void updateNodePath(FGKNode* node) {
        while(node) {
            node->weight++;
            node = node->parent;
        }
    }
    
    // 计算编码总长度
    long long calculateTotalLength() {
        long long total = 0;
        
        function<void(FGKNode*, int)> dfs = [&](FGKNode* node, int depth) {
            if(!node) return;
            
            // 如果是叶子节点(不是NYT)，累加编码长度
            if(!node->left && !node->right && node->symbol >= 0) {
                total += node->weight * depth;
            }
            
            // 如果是NYT节点，也需要计算其长度
            if(node == NYT) {
                total += depth;  // 结束符的频率为1
            }
            
            dfs(node->left, depth + 1);
            dfs(node->right, depth + 1);
        };
        
        dfs(root, 0);
        return total;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    // 创建FGK树
    FGKTree tree(n);
    
    // 处理查询和更新
    for(int i = 0; i < m; i++) {
        int query;
        cin >> query;
        
        if(query == 0) {
            // 计算编码总长度
            cout << tree.calculateTotalLength() << endl;
        } else {
            // 更新树
            tree.update(query);
        }
    }
    
    return 0;
}