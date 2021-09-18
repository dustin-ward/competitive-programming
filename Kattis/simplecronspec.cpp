#include <bits/stdc++.h>
using namespace std;

bool schedule[24][60][60];

struct Job {
    bool hrs[24] = {0};
    bool mins[60] = {0};
    bool secs[60] = {0};
};

int main() {
    int n; cin>>n;
    vector<Job> jobs;

    int totalJobs = 0;
    int jobsPerDay = 0;
    for(int i=0; i<n; i++) {
        string h,m,s; cin>>h>>m>>s;
        Job jb;

        // SECONDS
        int perMin = 0;
        if(s == "*") {
            perMin = 60;
            for(int j=0; j<60; j++) jb.secs[j] = 1;
        }
        else if(s.find(",")) {
            bool flag = true;
            while(flag) {
                string temp;
                int next = s.find(",");
                if(next != string::npos) {
                    temp = s.substr(0, next);
                    s = s.substr(next+1);
                }
                else {
                    temp = s;
                    flag = false;
                }

                if(temp.find("-")) {
                    int pos = temp.find("-");
                    string start = temp.substr(0, pos);
                    string end = temp.substr(pos+1);

                    for(int j=stoi(start); j<=stoi(end); j++) {
                        jb.secs[j] = 1;
                        perMin++;
                    }
                }
                else {
                    jb.secs[stoi(temp)] = 1;
                    perMin++;
                }
            }
        }
        else if(s.find("-")) {
            int pos = s.find("-");
            string start = s.substr(0, pos);
            string end = s.substr(pos+1);

            for(int j=stoi(start); j<=stoi(end); j++) {
                jb.secs[j] = 1;
                perMin++;
            }
        }
        else {
            jb.secs[stoi(s)] = 1;
            perMin++;
        }
        // cout<<"SECS "<<perMin<<endl;
        // for(auto x:jb.secs)
        //     cout<<x<<" ";
        // cout<<endl;

        // MINUTES
        int perHr = 0;
        if(m == "*") {
            perHr = 60;
            for(int j=0; j<60; j++) jb.mins[j] = 1;
        }
        else if(m.find(",")) {
            bool flag = true;
            while(flag) {
                string temp;
                int next = m.find(",");
                if(next != string::npos) {
                    temp = m.substr(0, next);
                    m = m.substr(next+1);
                }
                else {
                    temp = m;
                    flag = false;
                }

                if(temp.find("-")) {
                    int pos = temp.find("-");
                    string start = temp.substr(0, pos);
                    string end = temp.substr(pos+1);

                    for(int j=stoi(start); j<=stoi(end); j++) {
                        jb.mins[j] = 1;
                        perHr++;
                    }
                }
                else {
                    jb.mins[stoi(temp)] = 1;
                    perHr++;
                }
            }
        }
        else if(m.find("-")) {
            int pos = m.find("-");
            string start = m.substr(0, pos);
            string end = m.substr(pos+1);

            for(int j=stoi(start); j<=stoi(end); j++) {
                jb.mins[j] = 1;
                perHr++;
            }
        }
        else {
            jb.mins[stoi(s)] = 1;
            perHr++;
        }
        // cout<<"MINS "<<perHr<<endl;
        // for(auto x:jb.mins)
        //     cout<<x<<" ";
        // cout<<endl;

        // HOURS
        int perDay = 0;
        if(h == "*") {
            perDay = 24;
            for(int j=0; j<24; j++) jb.hrs[j] = 1;
        }
        else if(h.find(",")) {
            bool flag = true;
            while(flag) {
                string temp;
                int next = h.find(",");
                if(next != string::npos) {
                    temp = h.substr(0, next);
                    h = h.substr(next+1);
                }
                else {
                    temp = h;
                    flag = false;
                }

                if(temp.find("-")) {
                    int pos = temp.find("-");
                    string start = temp.substr(0, pos);
                    string end = temp.substr(pos+1);

                    for(int j=stoi(start); j<=stoi(end); j++) {
                        jb.hrs[j] = 1;
                        perDay++;
                    }
                }
                else {
                    jb.hrs[stoi(temp)] = 1;
                    perDay++;
                }
            }
        }
        else if(h.find("-")) {
            int pos = h.find("-");
            string start = h.substr(0, pos);
            string end = h.substr(pos+1);

            for(int j=stoi(start); j<=stoi(end); j++) {
                jb.hrs[j] = 1;
                perDay++;
            }
        }
        else {
            jb.hrs[stoi(s)] = 1;
            perDay++;
        }
        // cout<<"HOURS "<<perDay<<endl;
        // for(auto x:jb.hrs)
        //     cout<<x<<" ";
        // cout<<endl;

        // cout<<"TOTAL "<<perMin*perHr*perDay<<endl;

        for(int hr=0; hr<24; hr++) {
            if(jb.hrs[hr]) {
                for(int mn=0; mn<60; mn++) {
                    if(jb.mins[mn]) {
                        for(int sc=0; sc<60; sc++) {
                            if(jb.secs[sc])
                                schedule[hr][mn][sc] = 1;
                        }
                    }
                }
            }
        }
        totalJobs += (perMin * perHr * perDay);
        jobs.push_back(jb);
    }

    for(int hr=0; hr<24; hr++) {
        for(int mn=0; mn<60; mn++) {
            for(int sc=0; sc<60; sc++) {
                if(schedule[hr][mn][sc])
                    jobsPerDay++;
            }
        }
    }
    cout<<jobsPerDay<<" "<<totalJobs<<endl;
}