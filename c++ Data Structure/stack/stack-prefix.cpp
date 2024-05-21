#include<iostream>
#include<stack>
#include<math.h>
#include<string.h>
using namespace std;
int prefix( string s )
{
    stack<int> st;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            int c1=st.top();
            st.pop();
            int c2=st.top();
            st.pop();

            switch(s[i])
            {
                case '+' :
                st.push(c1+c2);
                break;
                case '-' :
                st.push(c1-c2);
                break;
                case '*' :
                st.push(c1*c2);
                break;
                case '/' :
                st.push(c1/c2);
                break;
                case '^' :
                st.push(pow(c1,c2));
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string s="-+7*45+20";
    cout<<"-+7*45+20  =  "<<prefix(s)<<endl;
    return 0;
}