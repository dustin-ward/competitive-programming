#include <bits/stdc++.h>
using namespace std;

struct Person {
    int startHealth;
    int currentHealth;

    friend bool operator<(const Person& a, const Person &b) {
        if(a.currentHealth == b.currentHealth)
            return a.startHealth < b.startHealth;
        else
            return a.currentHealth < b.currentHealth;
    }
};


int main() {
    int s, m;
    cin >> s >> m;

    priority_queue<Person> available;

    for(int i=0; i<s; i++) {
        int h;
        cin >> h;
        Person p;
        p.startHealth = h;
        p.currentHealth = h;
        available.push(p);
    }

    int e;
    cin >> e;

    bool ded = false;

    queue<int> zombies;
    priority_queue<Person> ward;
    queue<pair<Person,int>> rest;


    for(int i=0; i<e; i++) {
        // if on a medicine event
        if(i && !ward.empty() && ((i+1) % m == 0)) {
            Person p = ward.top(); ward.pop();
            p.startHealth = p.startHealth/2;
            p.currentHealth = p.startHealth;
            if(!p.currentHealth)
                ward.push(p);
            else
                available.push(p);
        }

        while(!rest.empty() && rest.front().second <= i) {
            available.push(rest.front().first); rest.pop();
        }

        //event text
        string s;
        cin >> s;
        if(s == "APPROACH") {
            int z;
            cin >> z;
            zombies.push(z);
        }
        else {
            // ATTACK
            while(zombies.front() > 0) {
                //if pq is empty
                if(available.empty()) {
                    cout << "overrun" << endl;
                    return 0;
                }
                Person p = available.top();
                available.pop();

                int currentZombie = zombies.front();
                int currentSurvivor = p.currentHealth;

                currentZombie -= p.currentHealth;
                currentSurvivor -= zombies.front();
                zombies.front() = currentZombie;
                p.currentHealth = currentSurvivor;

                if(p.currentHealth <= 0)
                    ward.push(p);
                else
                    rest.push({p, i+2});
            }
            zombies.pop();
        }
    }
    if(!ded) {
        cout << "success" << endl;
    } else 
        cout << "overrun" << endl;
}
