//本程序旨在实现大根堆
//大根堆：完全二叉树，w根>w子
#include <bits/stdc++.h>
using namespace std;
//对节点i，2i+1是左节点，2i+2是右节点，i下标从0开始
template <class T>
class maxHeap {
    private:
        vector<T> heap;  // 使用vector存储堆元素
    
        // 上浮操作：将新插入元素上移到合适位置
        void siftUp(int position) {
            T temp = heap[position];
            // 当position>0且父节点小于当前节点时，交换
            while (position > 0 && heap[(position-1)/2] < temp) {
                heap[position] = heap[(position-1)/2];  // 父节点下移
                position = (position-1)/2;  // 更新位置为父节点位置
            }
            heap[position] = temp;  // 放置元素到最终位置
        }
    
        // 下沉操作：将根节点下移到合适位置
        void siftDown(int position) {
            int i = position;
            int j = 2*i + 1;  // j是i的左子节点
            T temp = heap[i];

            while (j < heap.size()) {
                // 如果右子节点存在且大于左子节点，j指向右子节点
                if (j+1 < heap.size() && heap[j] < heap[j+1]) {
                    j++;
                }
            
                // 如果当前节点不小于两个子节点中的较大者，退出循环
                if (temp >= heap[j]) {
                    break;
                }
            
                // 较大的子节点上移
                heap[i] = heap[j];
                i = j;
                j = 2*i + 1;  // 更新j为新i的左子节点
            }
        
        heap[i] = temp;  // 放置元素到最终位置
    }
    
public:
    // 构造函数
    maxHeap() {}
    
    // 从数组构建堆
    maxHeap(T arr[], int n) {
        // 复制数组元素到堆
        for (int i = 0; i < n; i++) {
            heap.push_back(arr[i]);
        }
        
        // 从最后一个非叶节点开始向下调整
        for (int i = heap.size()/2-1; i >= 0; i--) {
            siftDown(i);
        }
    }
    
    // 插入元素
    void push(const T& theElement) {
        // 首先将元素添加到末尾
        heap.push_back(theElement);
        
        // 然后上浮到合适位置
        siftUp(heap.size()-1);
    }
    
    // 移除最大元素
    void pop() {
        if (empty()) {
            throw runtime_error("Heap is empty");
        }
        
        // 将最后一个元素放到根节点
        heap[0] = heap.back();
        heap.pop_back();
        
        // 如果堆不为空，对根节点进行下沉操作
        if (!empty()) {
            siftDown(0);
        }
    }
    
    // 获取最大元素
    T top() const {
        if (empty()) {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }
    
    // 判断堆是否为空
    bool empty() const {
        return heap.empty();
    }
    
    // 获取堆大小
    int size() const {
        return heap.size();
    }
    
    // 清空堆
    void clear() {
        heap.clear();
    }
    
    // 打印堆（用于调试）
    void print() const {
        for (const T& element : heap) {
            cout << element << " ";
        }
        cout << endl;
    }
};