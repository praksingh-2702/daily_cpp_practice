#include <iostream>
#include <stack>
#include <string>
using namespace std;
string postfix2prefix(string postfix,int n){
    stack<string> st;
    int i=0;
    while(i<n){
        char ch=postfix[i];
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
            st.push(string(1,ch));
        }
        else{
            string c1=st.top();
            st.pop();
            string c2=st.top();
            st.pop();
            string con=string(1,ch)+c2+c1;
            st.push(con);
        }
        i++;
    }
    return st.top();
}
int main(){
    string postfix="AB-DE+F*/";
    int n=postfix.size();
    string prefix=postfix2prefix(postfix,n);
    for(int i=0;i<prefix.size();i++){
        cout << prefix[i];
    }
    cout << endl;
    return 0;
}