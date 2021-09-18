#include <iostream>
using namespace std;

int main() {
    int N,R,E,C;
    cin>>N;

    for(int i=0; i<N; i++) {
        cin>>R>>E>>C;

        if(R > E - C)
            cout<<"do not advertise"<<endl;
        else if(R < E - C)
            cout<<"advertise"<<endl;
        else
            cout<<"does not matter"<<endl;
    }

}