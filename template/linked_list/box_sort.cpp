#include<bits/stdc++.h>
using namespace std;
struct StudentRecord{
    int score;
    string* name;
    operator int() const {return score;}
};
/*
    for example:
// 创建一些示例 StudentRecord 对象
    StudentRecord sr1{90, new string("Alice")};
    StudentRecord sr2{75, new string("Bob")};
    StudentRecord sr3{85, new string("Charlie")};

    // 1. 直接赋值给 int 类型变量
    int score1 = sr1; // 等效于 score1 = sr1.operator int()，值为 90
    cout << "score1 = " << score1 << endl;

    // 2. 使用 sort 根据 score 排序
    vector<StudentRecord> students = {sr1, sr2, sr3};
    sort(students.begin(), students.end()); 
    // sort会调用 operator int() 获取分数，用于比较大小

*/
ostream& operator<<(ostream& out,const StudentRecord &x){
    out<<x.score<<' '<<x.name<<endl;
    return out;
}//重载输出