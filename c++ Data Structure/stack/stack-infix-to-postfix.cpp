#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int precidence(char c)
{
    if(c=='^')
    return 3;
    else if(c=='*' || c=='/')
    return 2;
    else if(c=='+' || c=='-')
    return 1;
    else
    return -1;
}

string infixToPostfix(string s)
{
    string r="";
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
        r=r+s[i];
        else if(s[i]=='(')
        st.push(s[i]);
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                r=r+st.top();
                st.pop();
            }
            if(!st.empty())
            st.pop();
        }
        else
        {
            while(!st.empty() && precidence(st.top())>precidence(s[i]))
            {
                r=r+st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        r=r+st.top();
        st.pop();
    }
    return r;
}

int main()
{
    string s="(a-b/c)*(a/k-l)";
    cout<<"(a-b/c)*(a/k-l)  = "<<infixToPostfix(s)<<endl;
    return 0;
}
//(a-b/c)*(a/k-l)  = abc/-ak/l-*