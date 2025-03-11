#include<bits/stdc++.h>
using namespace std;
double calculate(char &sign,double a,double b){
        if (sign=='+')return(b+a);
        else if (sign=='-')return(b-a);
        else if (sign=='*')return(b*a);
        else return(b/a);
}
double parse(string &a,int &i){
    while(i<a.length()&&a[i]==' ')i++;
        char temp=a[i++];
        if (!(temp>='0'&&temp<='9')){
            double x=calculate(temp,parse(a,i),parse(a,i));
            //cout<<temp<<" "<<x<<" ";
            return x;
        }
        else{
            i--;
            int temp_num=0;
            bool flag=0;
            int wei=0;
            while(a[i]!=' '&& i<a.length()){
                if(a[i]!='.'){
                    temp_num*=10;
                    temp_num+=int(a[i]-'0');
                    if(flag==true) wei++;
                }
                else{
                    flag=true;
                }
                i++;
            }
            double num_now=double(temp_num)/double(pow(10,wei));
            return(num_now);
        }
}
int main(){
    string a;
    getline(cin,a);
    int i=0;
    printf("%f\n",parse(a,i));
    return 0;
}
