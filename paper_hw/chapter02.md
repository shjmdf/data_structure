# Chapter 02
**谢胡睿 2400014151 数算（B）24-25春**

书面作业：书p67复习(4、6、7)， 算法（3、12、16）

## 复习
### 4. 
前后顺序；指针或者引用关系
### 6.
#### 顺序存储：
**pros:** 存储密度高，且理解较为直观
**cons:** 删改较麻烦；需要连续空间；检索为O(n)
#### 链接存储：
**pros:** 插入删除灵活；空间灵活，并非静态
**cons:** 存取麻烦，且指针使用较为麻烦，指针内存管理较麻烦

### 7.
B

## 算法
### 3.
//e为顺序表
e=list()
void reverse (list &e) {

&emsp;if e==NULL:
&emsp;&emsp;return 

&emsp;lene=len(e)

&emsp;for(i=0;i<lene;i++){
&emsp;&emsp;temp=e[i]
&emsp;&emsp;e[i]=e[lene-i-1]
&emsp;&emsp;e[lene-i-1]=temp
&emsp;}
&emsp;return
}
### 12.

//使用一个数组储存
void del_repe(Llist* head ,int len){
&emsp;Llist* current{head}
&emsp;Llist* pre{head}
&emsp;flag=[ ]
&emsp;for(i=0 ;i < x; i++){
&emsp;&emsp;if (current->value not in flag) //need a function to realize the "in"
&emsp;&emsp;&emsp;flag.add(current->value)
&emsp;&emsp;else {
&emsp;&emsp;&emsp;if (current->value in flag)
&emsp;&emsp;&emsp;&emsp;Llist* temp{nullptr}
&emsp;&emsp;&emsp;&emsp;pre->next=current->next
&emsp;&emsp;&emsp;&emsp;free(current)
&emsp;&emsp;&emsp;&emsp;current=pre->next
&emsp;&emsp;&emsp;else{
&emsp;&emsp;&emsp;&emsp;pre=current
&emsp;&emsp;&emsp;&emsp;current=current->next
&emsp;&emsp;&emsp;}
&emsp;&emsp;}
&emsp;}
}

### 16.
Llist* combine(Llist* a,Llist* b){
&emsp;Llist* chead=new Llist{nullptr}
&emsp;Llist* c=chead->next
&emsp;List* acurrent{a->head} ,bcurrent{b->head}
&emsp;if(acurrent->next== nullptr && bcurrent->next== nullptr){
&emsp;&emsp;return c
&emsp;}//robustness
&emsp;while(acurrent->next!= nullptr || bcurrent->next!= nullptr){//判空
&emsp;&emsp;if (acurrent->next!= nullptr && bcurrent->next!= nullptr){
&emsp;&emsp;&emsp;c->value=acurrent->value>bcurrent->value?acurrent->value:bcurrent->value
&emsp;&emsp;&emsp;bcurrent=bcurrent->next
&emsp;&emsp;&emsp;acurrent=acurrent->next
&emsp;&emsp;}
&emsp;&emsp;else{
&emsp;&emsp;&emsp;if(acurrent->next==nullptr) {//尾巴
&emsp;&emsp;&emsp;&emsp;c->value=bcurrent->value
&emsp;&emsp;&emsp;&emsp;bcurrent=bcurrent->next
&emsp;&emsp;&emsp;}

&emsp;&emsp;&emsp;if(bcurrent->next==nullptr) {//尾巴
&emsp;&emsp;&emsp;&emsp;c->value=acurrent->value
&emsp;&emsp;&emsp;&emsp;acurrent=acurrent->next
&emsp;&emsp;&emsp;} 
&emsp;&emsp;}
&emsp;&emsp;c=c->next
&emsp;}
&emsp;return chead
}
