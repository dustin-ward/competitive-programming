#include <bits/stdc++.h>
using namespace std;

struct Ingredient {
    string name;
    double w;
    double p;
};

int main() {
    int caseno=1;
    int T; cin>>T;
    while(T--) {
        int R,P,D; cin>>R>>P>>D;
        vector<Ingredient> recipe(R);
        int main;
        double sf = (double)D/(double)P;
        for(int i=0; i<R; i++) {
            string s; cin>>s;
            double w,p; cin>>w>>p;
            Ingredient x = {s,w,p};
            recipe[i] = x;
            if(p == 100.0) main = i;
        }

        cout<<"Recipe # "<<caseno++<<endl;

        double mainW = (recipe[main].w *= sf);
        for(int i=0; i<R; i++) {
            if(i != main)
                recipe[i].w = mainW * (recipe[i].p/100);
            cout<<fixed<<recipe[i].name<<" "<<recipe[i].w<<endl;
        }

        cout<<"----------------------------------------"<<endl;
    }
}