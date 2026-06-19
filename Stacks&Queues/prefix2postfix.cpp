#include <iostream>
#include <string>
#include <stack>
using namespace std;
string prefix2postfix(string prefix,int n){
    stack<string> st;
    int i=n-1;
    while(i>=0){
        char ch=prefix[i];
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
            st.push(string(1,ch));
        }
        else{
            string c1=st.top();
            st.pop();
            string c2=st.top();
            st.pop();
            string con= c1 + c2 + string(1,ch);
            st.push(con);
        }
        i--;
    }
    return st.top();
}
int main(){
    string prefix="/-AB*+DEF";
    int n=prefix.size();
    string postfix=prefix2postfix(prefix,n);
    for(int i=0;i<postfix.size();i++){
        cout << postfix[i];
    }
    cout << endl;
}