#include <bits/stdc++.h>
using namespace std;

char operators[4] = {'*', '+', '-', '/'};

int main() {
    int a,b,c,d; cin>>a>>b>>c>>d;
    bool flag = false;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            switch(operators[i]) {
                case '+':
                    switch(operators[j]) {
                        case '+':
                            if(a+b == c+d) {
                                cout<<a<<" + "<<b<<" = "<<c<<" + "<<d<<endl;
                                flag = true;
                            }
                            break;
                        case '-':
                            if(a+b == c-d) {
                                cout<<a<<" + "<<b<<" = "<<c<<" - "<<d<<endl;
                                flag = true;
                            }
                            break;
                        case '*':
                            if(a+b == c*d) {
                                cout<<a<<" + "<<b<<" = "<<c<<" * "<<d<<endl;
                                flag = true;
                            }
                            break;
                        case '/':
                            if(!d)
                                break;
                            if(a+b == c/d) {
                                cout<<a<<" + "<<b<<" = "<<c<<" / "<<d<<endl;
                                flag = true;
                            }
                            break;
                    }
                    break;
                case '-':
                    switch(operators[j]) {
                        case '+':
                            if(a-b == c+d) {
                                cout<<a<<" - "<<b<<" = "<<c<<" + "<<d<<endl;
                                flag = true;
                            }
                            break;
                        case '-':
                            if(a-b == c-d) {
                                cout<<a<<" - "<<b<<" = "<<c<<" - "<<d<<endl;
                                flag = true;
                            }
                            break;
                        case '*':
                            if(a-b == c*d) {
                                cout<<a<<" - "<<b<<" = "<<c<<" * "<<d<<endl;
                                flag = true;
                            }
                            break;
                        case '/':
                            if(!d)
                                break;
                            if(a-b == c/d) {
                                cout<<a<<" - "<<b<<" = "<<c<<" / "<<d<<endl;
                                flag = true;
                            }
                            break;
                    }
                    break;
                case '*':
                    switch(operators[j]) {
                        case '+':
                            if(a*b == c+d) {
                                cout<<a<<" * "<<b<<" = "<<c<<" + "<<d<<endl;
                                flag = true;
                            }
                            break;
                        case '-':
                            if(a*b == c-d) {
                                cout<<a<<" * "<<b<<" = "<<c<<" - "<<d<<endl;
                                flag = true;
                            }
                            break;
                        case '*':
                            if(a*b == c*d) {
                                cout<<a<<" * "<<b<<" = "<<c<<" * "<<d<<endl;
                                flag = true;
                            }
                            break;
                        case '/':
                            if(!d)
                                break;
                            if(a*b == c/d) {
                                cout<<a<<" * "<<b<<" = "<<c<<" / "<<d<<endl;
                                flag = true;
                            }
                            break;
                    }
                    break;
                case '/':
                    if(!b)
                        break;
                    switch(operators[j]) {
                        case '+':
                            if(a/b == c+d) {
                                cout<<a<<" / "<<b<<" = "<<c<<" + "<<d<<endl;
                                flag = true;
                            }
                            break;
                        case '-':
                            if(a/b == c-d) {
                                cout<<a<<" / "<<b<<" = "<<c<<" - "<<d<<endl;
                                flag = true;
                            }
                            break;
                        case '*':
                            if(a/b == c*d) {
                                cout<<a<<" / "<<b<<" = "<<c<<" * "<<d<<endl;
                                flag = true;
                            }
                            break;
                        case '/':
                            if(!d)
                                break;
                            if(a/b == c/d) {
                                cout<<a<<" / "<<b<<" = "<<c<<" / "<<d<<endl;
                                flag = true;
                            }
                            break;
                    }
                    break;
            }
        }
    }
    if(!flag)
        cout<<"problems ahead"<<endl;
}