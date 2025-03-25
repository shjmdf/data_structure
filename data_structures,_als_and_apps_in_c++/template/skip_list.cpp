//this program is used to write a skip list
//skip list is intended to solve the search problem of a linked_list
//which is rated as O(n) considering the time.
#include<bits/stdc++.h>
//first is the dictionary
using std::pair;
using std::map;
using std::string;
using std::cout;
using std::cin;
using std::endl;
template<class K,class E>
class dictionary
{
    public:
        virtual ~dictionary() {}
        virtual bool empty() const=0;//return true unless the dic(well, dirty talk) is empty
        virtual int size() const=0;
        virtual pair<const K,E>* find(const K&) const=0;
        virtual void erase(const K&) const=0;
        virtual void insert(const pair<const K,E>& )=0;
        //try to think why i did not realize the method, 
        //and consider the benefits when using template, virtual function and so on.
        //extensibility and robustness
};
//
template <class K,class E>
class skipList : public dictionary<K,E> {
    private:
        // 用 map<K,E> 存储数据，实际应替换为跳表节点
        map<K,E> dataStore;
    
    public:
        // 构造函数
        skipList() {}
    
        // 判断是否为空
        bool empty() const override {
            return dataStore.empty();
        }
    
        // 返回大小
        int size() const override {
            return dataStore.size();
        }
    
        // 查找
        pair<const K,E>* find(const K& key) const override {
            auto it = dataStore.find(key);
            if(it == dataStore.end()) {
                return nullptr;
            }
            // 动态分配仅用于演示，请注意资源管理
            return new pair<const K,E>(it->first, it->second);
        }
    
        // 删除
        void erase(const K& key) const override {
            // 因为此函数被声明为 const，需要 const_cast 解除限制
            // 真实设计中一般不会把 erase 修饰成 const
            auto self = const_cast<skipList<K,E>*>(this);
            self->dataStore.erase(key);
        }
    
        // 插入
        void insert(const pair<const K,E>& kv) override {
            // 如果键已存在会覆盖其对应的值
            dataStore[kv.first] = kv.second;
        }
    };
    
    // 简单测试
    int main(){
        skipList<int, string> sk;
    
        // 插入
        sk.insert({1, "One"});
        sk.insert({2, "Two"});
        cout << "size = " << sk.size() << endl;
    
        // 查找
        auto p = sk.find(1);
        if(p) {
           cout << "Found key=1, value=" << p->second << endl;
           delete p; // 释放动态分配的内存
        }
        // 删除
        sk.erase(1);
        cout << "After erase, size = " << sk.size() << endl;
    
        return 0;
    }