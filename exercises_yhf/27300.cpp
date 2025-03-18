#include <bits/stdc++.h>
using namespace std;

typedef struct num{
    string num_name;
    long long num;
}Num;
typedef struct model{
    string name;
    vector<Num> num;
}Model;
vector<Model> model;

int n;
void addst(string s){
    string t_name="";
    string t_num="";
    bool flag=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='-'){
            flag=true;
            continue;
        }
        if(flag==false){
            t_name+=s[i];
        }
        else{
            t_num+=s[i];
        }
    }
    long long r_num;
    string num_name = "";
    string num_value_str = "";
    
    for (char c : t_num) {
        if (isdigit(c) || c == '.') {
            num_value_str += c;
        } else {
            num_name += c;
        }
    }

    double temp_val = stod(num_value_str);
    long long num_value = 0;

    if (num_name == "B" || num_name == "b") {
        num_value = (long long)(temp_val * 1000000000);
    } else if (num_name == "M" || num_name == "m") {
        num_value = (long long)(temp_val * 1000000);
    } else if (num_name == "K" || num_name == "k") {
        num_value = (long long)(temp_val * 1000);
    } else {
        num_value = (long long)temp_val;
    }
    r_num=num_value;
    //update model
    bool model_exist=0;
    for(auto& m: model){
        if(t_name==m.name){
            model_exist=true;
            Num new_num={t_num,r_num};
            m.num.push_back(new_num);
            break;
        }
    }
    if(!model_exist){
        Model new_model;
        new_model.name=t_name;
        Num new_num={t_num,r_num};
        new_model.num.push_back(new_num);
        model.push_back(new_model);
    }
    return;
}
int main(){
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        addst(s);
    }
    sort(model.begin(), model.end(), [](const Model& a, const Model& b) {
        return a.name < b.name;
    });
    
    for (auto& m : model) {
        sort(m.num.begin(), m.num.end(), [](const Num& a, const Num& b) {
            return a.num < b.num;
        });
    }
    
    for (const auto& m : model) {
        cout << m.name << ": ";
        
        for (size_t i = 0; i < m.num.size(); i++) {
            cout << m.num[i].num_name;
            
            if (i < m.num.size() - 1) {
                cout << ", ";
            }
        }
        
        cout << endl;
    }
    return 0;
}