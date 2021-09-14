#include <bits/stdc++.h>
using namespace std;

struct Window {
    long long x;
    long long y;
    long long w;
    long long h;
};

vector<Window> w;

bool overlap(Window &a, Window &b) {
    if(a.x >= b.x+b.w || b.x >= a.x+a.w)
        return false;
    if(a.y >= b.y+b.h || b.y >= a.y+a.h)
        return false;
    return true;
}

bool fx(int a, int b) {
    return w[a].x < w[b].x;
}

bool fy(int a, int b) {
    return w[a].y < w[b].y;
}

int main() {
    long long xMax, yMax; cin>>xMax>>yMax;

    string command;
    int commandno=0;
    while(cin>>command) {
        commandno++;
        if(command=="OPEN") {
            long long p1,p2,p3,p4; cin>>p1>>p2>>p3>>p4;
            if(p1 > xMax || p2 > yMax || p1+p3 > xMax || p2+p4 > yMax) {
                cout<<"Command "<<commandno<<": "<<command<<" - window does not fit"<<endl;
                continue;
            }
            Window temp = {p1,p2,p3,p4};
            bool flag = false;
            for(int i=0; i<w.size(); i++) {
                if(overlap(w[i], temp)) {
                    cout<<"Command "<<commandno<<": "<<command<<" - window does not fit"<<endl;
                    flag = true;
                    break;
                }
            }
            if(flag)
                continue;
            
            w.push_back(temp);
        }
        else if(command=="RESIZE") {
            long long p1,p2,p3,p4; cin>>p1>>p2>>p3>>p4;
            int pos;
            bool flag = false;
            for(int i=0; i<w.size(); i++) {
                if(p1 >= w[i].x && p1 < w[i].x+w[i].w && p2 >= w[i].y && p2 < w[i].y+w[i].h) {
                    pos = i;
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                cout<<"Command "<<commandno<<": "<<command<<" - no window at given position"<<endl;
                continue;
            }

            Window temp = w[pos];
            temp.w = p3; temp.h = p4;
            flag = false;
            for(int i=0; i<w.size(); i++) {
                if(i == pos) continue;
                if(overlap(w[i], temp)) {
                    flag = true;
                    break;
                }
            }
            if(flag) {
                cout<<"Command "<<commandno<<": "<<command<<" - window does not fit"<<endl;
                continue;
            }
            else {
                w[pos].w = p3;
                w[pos].h = p4;
            }
        }
        else if(command=="MOVE") {
            long long p1,p2,p3,p4; cin>>p1>>p2>>p3>>p4;
            int pos;
            bool flag = false;
            for(int i=0; i<w.size(); i++) {
                if(p1 >= w[i].x && p1 < w[i].x+w[i].w && p2 >= w[i].y && p2 < w[i].y+w[i].h) {
                    pos = i;
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                cout<<"Command "<<commandno<<": "<<command<<" - no window at given position"<<endl;
                continue;
            }
            else {
                if(p3) { // VERTICAL MOVEMENT
                    if(p3 > 0) { // RIGHT MOVEMENT
                        vector<int> inTheWay;
                        int sum=0;
                        for(int i=0; i<w.size(); i++) {
                            if(i==pos) continue;
                            if(w[i].x >= w[pos].x+w[pos].w && w[i].y < w[pos].y+w[pos].h && w[i].y+w[i].h > w[pos].y) {
                                inTheWay.push_back(i);
                                sum+=(w[i].w);
                            }
                        }

                        long long d = p3;
                        if(w[pos].x+w[pos].w+p3 > xMax - sum) {
                            d = (xMax - sum) - (w[pos].x+w[pos].w);
                            cout<<"Command "<<commandno<<": "<<command<<" - moved "<<d<<" instead of "<<p3<<endl;
                        }

                        w[pos].x += d;
                        if(d!=p3) {
                            sort(inTheWay.rbegin(), inTheWay.rend(), fx);

                            long long tempXmax = xMax;
                            for(int i=0; i<inTheWay.size(); i++) {
                                w[inTheWay[i]].x = tempXmax - w[inTheWay[i]].w;
                                tempXmax -= w[inTheWay[i]].w;
                            }
                        }
                        else {
                            sort(inTheWay.begin(), inTheWay.end(), fx);

                            long long newX = w[pos].x+w[pos].w;
                            for(int i=0; i<inTheWay.size(); i++) {
                                w[inTheWay[i]].x = newX;
                                newX += w[inTheWay[i]].w;
                            }
                        }
                    }
                    else { // LEFT MOVEMENT
                        vector<int> inTheWay;
                        long long sum=0;
                        p3 = abs(p3);
                        for(int i=0; i<w.size(); i++) {
                            if(i==pos) continue;
                            if(w[i].x+w[i].w <= w[pos].x && w[i].y < w[pos].y+w[pos].h && w[i].y+w[i].h > w[pos].y) {
                                inTheWay.push_back(i);
                                sum+=(w[i].w);
                            }
                        }

                        long long d = p3;
                        if(w[pos].x-p3 < 0 + sum) {
                            d = (w[pos].x) - (0 + sum);
                            cout<<"Command "<<commandno<<": "<<command<<" - moved "<<d<<" instead of "<<p3<<endl;
                        }

                        w[pos].x -= d;
                        if(d!=p3) {
                            sort(inTheWay.begin(), inTheWay.end(), fx);

                            long long tempXmin = 0;
                            for(int i=0; i<inTheWay.size(); i++) {
                                w[inTheWay[i]].x = tempXmin;
                                tempXmin += w[inTheWay[i]].w;
                            }
                        }
                        else {
                            sort(inTheWay.rbegin(), inTheWay.rend(), fx);

                            long long newX = w[pos].x;
                            for(int i=0; i<inTheWay.size(); i++) {
                                w[inTheWay[i]].x = newX - w[inTheWay[i]].w;
                                newX -= w[inTheWay[i]].w;
                            }
                        }
                    }
                }
                else { // HORIZONTAL MOVEMENT
                    if(p4 > 0) { // DOWN MOVEMENT
                        vector<int> inTheWay;
                        long long sum=0;
                        for(int i=0; i<w.size(); i++) {
                            if(i==pos) continue;
                            if(w[i].y >= w[pos].y+w[pos].h && w[i].x < w[pos].x+w[pos].w && w[i].x+w[i].w > w[pos].x) {
                                inTheWay.push_back(i);
                                sum+=(w[i].h);
                            }
                        }

                        long long d = p4;
                        if(w[pos].y+w[pos].h+p4 > yMax - sum) {
                            d = (yMax - sum) - (w[pos].y+w[pos].h);
                            cout<<"Command "<<commandno<<": "<<command<<" - moved "<<d<<" instead of "<<p4<<endl;
                        }

                        w[pos].y += d;
                        if(d!=p4) {
                            sort(inTheWay.rbegin(), inTheWay.rend(), fy);

                            long long tempYmax = yMax;
                            for(int i=0; i<inTheWay.size(); i++) {
                                w[inTheWay[i]].y = tempYmax - w[inTheWay[i]].h;
                                tempYmax -= w[inTheWay[i]].h;
                            }
                        }
                        else {
                            sort(inTheWay.begin(), inTheWay.end(), fy);

                            long long newY = w[pos].y+w[pos].h;
                            for(int i=0; i<inTheWay.size(); i++) {
                                w[inTheWay[i]].y = newY;
                                newY += w[inTheWay[i]].h;
                            }
                        }
                    }
                    else { // UP MOVEMENT
                        vector<int> inTheWay;
                        long long sum=0;
                        p4 = abs(p4);
                        for(int i=0; i<w.size(); i++) {
                            if(i==pos) continue;
                            if(w[i].y+w[i].h <= w[pos].y && w[i].x < w[pos].x+w[pos].w && w[i].x+w[i].w > w[pos].x) {
                                inTheWay.push_back(i);
                                sum+=(w[i].h);
                            }
                        }

                        long long d = p4;
                        if(w[pos].y-p4 < 0 + sum) {
                            d = (w[pos].y) - (0 + sum);
                            cout<<"Command "<<commandno<<": "<<command<<" - moved "<<d<<" instead of "<<p4<<endl;
                        }

                        w[pos].y -= d;
                        if(d!=p4) {
                            sort(inTheWay.begin(), inTheWay.end(), fy);

                            long long tempYmin = 0;
                            for(int i=0; i<inTheWay.size(); i++) {
                                w[inTheWay[i]].y = tempYmin;
                                tempYmin += w[inTheWay[i]].h;
                            }
                        }
                        else {
                            sort(inTheWay.rbegin(), inTheWay.rend(), fy);

                            long long newY = w[pos].y;
                            for(int i=0; i<inTheWay.size(); i++) {
                                w[inTheWay[i]].y = newY - w[inTheWay[i]].h;
                                newY -= w[inTheWay[i]].h;
                            }
                        }
                    }
                }
            }
        }
        else {  //command=="close"
            long long p1,p2; cin>>p1>>p2;
            int pos;
            bool flag = false;
            for(int i=0; i<w.size(); i++) {
                if(p1 >= w[i].x && p1 < w[i].x+w[i].w && p2 >= w[i].y && p2 < w[i].y+w[i].h) {
                    pos = i;
                    flag = true;
                    break;
                }
            }
            if(flag) {
                w.erase(w.begin()+pos);
            }
            else {
                cout<<"Command "<<commandno<<": "<<command<<" - no window at given position"<<endl;
                continue;
            }
        }
    }

    cout<<w.size()<<" window(s):"<<endl;
    for(int i=0; i<w.size(); i++) {
        cout<<w[i].x<<" "<<w[i].y<<" "<<w[i].w<<" "<<w[i].h<<endl;
    }
}