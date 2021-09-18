#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin>>s;
    stack<int> st;

    int i=0;
    while(i<s.size()) {
        switch(s[i]) {
            case 'S':
                i++;
                switch(s[i]) {
                    case 'S': {
                        i++;
                        //SS
                        string binNum;
                        while(s[i]!='N') {
                            binNum.append(s[i]=='S' ? "0" : "1");
                            i++;
                        }
                        int temp = stoi(binNum.substr(1), 0, 2);
                        if(binNum[0]=='1')
                            temp = -temp;
                        st.push(temp);
                        break;
                    }
                    case 'N':
                        i++;
                        switch(s[i]) {
                            case 'S':
                                //SNS
                                if(!st.empty()) {
                                    int temp = st.top();
                                    st.push(temp);
                                }
                                else
                                    cout<<"Invalid copy operation"<<endl;
                                break;
                            case 'T':
                                //SNT
                                if(st.size() >= 2) {
                                    int temp = st.top(); st.pop();
                                    int temp2 = st.top(); st.pop();
                                    st.push(temp); st.push(temp2);
                                }
                                else
                                    cout<<"Invalid swap operation"<<endl;
                                break;
                            case 'N':
                                //SNN
                                if(!st.empty())
                                    st.pop();
                                else
                                    cout<<"Invalid remove operation"<<endl;
                                break;
                        }
                        break;
                }
                break;
            case 'T':
                i++;
                switch(s[i]) {
                    case 'S':
                        i++;
                        switch(s[i]) {
                            case 'S':
                                i++;
                                switch(s[i]) {
                                    case 'S':
                                        //TSSS
                                        if(st.size() >= 2) {
                                            int temp = st.top(); st.pop();
                                            int temp2 = st.top(); st.pop();
                                            st.push(temp+temp2);
                                        }
                                        else
                                            cout<<"Invalid addition operation"<<endl;
                                        break;
                                    case 'T':
                                        //TSST
                                        if(st.size() >= 2) {
                                            int temp = st.top(); st.pop();
                                            int temp2 = st.top(); st.pop();
                                            st.push(temp2-temp);
                                        }
                                        else
                                            cout<<"Invalid subtraction operation"<<endl;
                                        break;
                                    case 'N':
                                        //TSSN
                                        if(st.size() >= 2) {
                                            int temp = st.top(); st.pop();
                                            int temp2 = st.top(); st.pop();
                                            st.push(temp*temp2);
                                        }
                                        else
                                            cout<<"Invalid multiplication operation"<<endl;
                                        break;
                                }
                                break;
                            case 'T':
                                i++;
                                //TSTS
                                if(st.size() >= 2) {
                                    if(st.top()==0)
                                        cout<<"Division by zero"<<endl;
                                    else {
                                        int temp = st.top(); st.pop();
                                        int temp2 = st.top(); st.pop();
                                        st.push(temp2/temp);
                                    }
                                }
                                else
                                    cout<<"Invalid division operation"<<endl;
                                break;
                        }
                        break;
                    case 'N':
                        //TNST
                        if(!st.empty()) {
                            cout<<st.top()<<endl;
                            st.pop();
                        }
                        else
                            cout<<"Invalid print operation"<<endl;
                        break;
                }
                break;
        }
        i++;
    }
}