#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
int priority(char ch){
    if(ch=='^'){
        return 3;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else if(ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
string infix2prefix(string infix){
    reverse(infix.begin(), infix.end());
    int n = infix.size();
    for(int i = 0; i < n; i++){
        if(infix[i] == '('){
            infix[i] = ')';
        }
        else if(infix[i] == ')'){
            infix[i] = '(';
        }
    }
    stack<char> st;
    string ans = "";
    int i = 0;
    while(i < n){
        char ch = infix[i];
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
            ans += ch;
        }
        else if(ch == '('){
            st.push(ch);
        }
        else if(ch == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else if(ch=='^'){
            while(!st.empty() && (priority(ch) <= priority(st.top()))){
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
        else{
            while(!st.empty() && (priority(ch) < priority(st.top()))){
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
        i++;
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    string infix="(A+B)-(C/D)*E";
    string prefix = infix2prefix(infix);
    cout << prefix << endl;
}