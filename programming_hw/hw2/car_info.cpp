#include<iostream>
#include<string>
#include<vector>
using namespace std;
//result
vector<string> results;

typedef struct _Violate
{
        int vio_code;//the violation code
        string place;//where
        string time;//when
        bool pro;//whether processed
        _Violate *next_v;//point to its next one
} Record;

typedef struct{
    string id;//car id
    Record* record;//use Llist
} Car;
//altogether
typedef struct{
    int num;
    Car car[110];
}CarList;

//add car data
void read_car(CarList &carl){
    string temp;
    cin>>temp>>carl.num;
    for (int i=0;i<carl.num;i++){
        cin>>carl.car[i].id;
        carl.car[i].record=nullptr;
    }
    return;
}

void add_violation(CarList &carl,string id,int vio_code,string place,string time,bool pro){
    for (int i=0;i<carl.num;i++){
        if(carl.car[i].id==id){
            Record* new_r=new Record;
            new_r->place=place;
            new_r->pro=pro;
            new_r->time=time;
            new_r->vio_code=vio_code;
            //add
            new_r->next_v=carl.car[i].record;
            carl.car[i].record=new_r;
            return;
        }
    }
}

void read_violation(CarList &carl){
    string temp;
    //temp data
    int vio_num;
    cin>>temp>>vio_num;

    string id;
    int vio_code;
    string place,time;
    bool pro;
    for(int i=0;i<vio_num;i++){
        cin>>id>>vio_code>>place>>time>>pro;
        //add it,right?
        add_violation(carl,id,vio_code,place,time,pro);
    }
    return;
}

void print_place(Car &tcar,string p){
    Record* current=tcar.record;
    while(current!=nullptr){
        if(current->pro!=1 && current->place==p){
            results.push_back(tcar.id+" "+to_string(current->vio_code)+" "+current->place+" "+current->time);
        }
        current=current->next_v;
    }
    return;
}
void print_code(Car &tcar,int code){
    Record* current=tcar.record;
    while(current!=nullptr){
        if(current->pro!=1 && current->vio_code==code){
            results.push_back(tcar.id+" "+to_string(current->vio_code)+" "+current->place+" "+current->time);
        }
        current=current->next_v;
    }
    return;
}
void print_time(Car &tcar,string t){
    Record* current=tcar.record;
    while(current!=nullptr){
        if(current->pro!=1 && current->time==t){
            results.push_back(tcar.id+" "+to_string(current->vio_code)+" "+current->place+" "+current->time);
        }
        current=current->next_v;
    }
    return;
}

void print_car(Car &tcar){
    Record* current=tcar.record;
    while(current!=nullptr){
        if(current->pro!=1){
            results.push_back(tcar.id+" "+to_string(current->vio_code)+" "+current->place+" "+current->time);
        }
        current=current->next_v;
    }
    return;
}

//... dreary job
void print(CarList &carl){
    //cope with the annoying input
    string command;
    cin>>command;
    string s;
    cin>>s;
    //tricky for id
    if(s.length()==5){
        for(int i=0;i<carl.num;i++){
            if(carl.car[i].id==s){
                print_car(carl.car[i]);
            }
        }
    }
    //whether it is time
    else if(s.length()==10){
        for(int i=0;i<carl.num;i++){
            print_time(carl.car[i],s);
        }
    }
    //whether the code
    else if(s.length()==3 && (s[0]>='0'&&s[0]<='9')){
        for(int i=0;i<carl.num;i++){
            print_code(carl.car[i],stoi(s));//a little bit awkward.
        }
    }
    //whether the place
    else for(int i=0;i<carl.num;i++){
        print_place(carl.car[i],s);
    }
    //output
    cout<<results.size()<<'\n';
    for(int i=0;i<results.size();i++){
        cout<<results[i]<<'\n';
    }
    return;
}
int main(){
    CarList carl;
    read_car(carl);
    read_violation(carl);
    print(carl);
    return 0;
}