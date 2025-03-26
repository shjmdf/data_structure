#include<bits/stdc++.h>
using namespace std;

//book class
class book{
    public:
        vector<string> words;
        string number;
};

//word bank forbidden
unordered_set<string> word_bank_forbidden={
    "a","an","the","to","in","on","at",
    "with","and","but","or","if","because",
    "it","this","that","they","we","be",
    "do","have","will","can","up","out",
    "off","some","any","each","oh","ah",
    "wow","oops"
};
//whether in forbidden word bank:
bool is_key_word(const string& str){
    return word_bank_forbidden.find(str) == word_bank_forbidden.end();
}
//input function(to avoid ' ' and neglect '\n')
void input(book& b){
    int ch;
    string temp_word;
    while((ch=getchar())!=EOF){
        //continue when ' '
        if (ch==' '){
            if (temp_word!="" && is_key_word(temp_word)==true)
                b.words.push_back(temp_word);

            temp_word="";
            continue;
        }
        //break when '\n'
        if (ch=='\n'){
            if (temp_word!="" && is_key_word(temp_word)==true)
                b.words.push_back(temp_word);

            temp_word="";
            break;
        }
        //avoid messes
        if(ch<='Z' && ch>='A'){
            ch=ch-'A'+'a';
        }
        //get ch
        temp_word+=char(ch);
    }
    return;
}
void match_input(string & s){
    int ch;
    while((ch=getchar())!='\n'){
        if(ch>='A' && ch<='Z'){
            ch=ch-'A'+'a';
        }
        s+=char(ch);
    }
    return;
}
//kmp
const int maxsize=100+1;

vector<int> computeNext(const string& pattern) {
    int m = pattern.length();
    vector<int> next(m,0);
    next[0]=0; 
    for (int j=1,i=0;j<m;j++) {
        while (i>0 && pattern[i]!=pattern[j]) {
            i=next[i-1];
        }
        if (pattern[i]==pattern[j]) {
            i++;
        }
        next[j]=i;
    }
    return next;
}
bool kmpsearch(const string &text,const string& word){
    vector<int> next=computeNext(word);
    int l_text=text.length();
    int l_word=word.length();
    for(int i=0,j=0;i<l_text;i++){
        while(j>0 && text[i]!=word[j]){
            j=next[j-1];
        }
        if(text[i] == word[j]) {
            j++;
        }
        if(j==l_word){
            return true;
        }
    }
    return false;
}

int main(){
    int num;
    cin>>num;
    cin.ignore();
    //init books
    vector<book> s(num);
    //init ans
    vector<string> ans;
    //input the num&name
    for(int i=0;i<num;i++){
        cin>>s[i].number;
        input(s[i]);
    }
    //string for search
    string s_name;
    match_input(s_name);
    for(int i=0;i<num;i++){
        for(auto& word:s[i].words){
            if(kmpsearch(s_name,word)){
                ans.push_back(s[i].number);
                break;
            }     
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(const auto& match: ans){
        cout<<match<<endl;
    }
    return 0;
}