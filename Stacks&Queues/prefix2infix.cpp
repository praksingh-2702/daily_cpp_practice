#include <iostream>
#include <stack>
#include <string>
using namespace std;
string prefix2infix(string prefix,int n){
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
            string con="(" + c1 + string(1,ch) + c2 + ")";
            st.push(con);
        }
        i--;
    }
    return st.top();
}
int main(){
    string prefix="*+PQ-MN";
    int n=prefix.size();
    string infix=prefix2infix(prefix,n);
    for(int i=0;i<infix.size();i++){
        cout << infix[i];
    }
    cout << endl;
    return 0;
}