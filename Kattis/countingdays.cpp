#include "countingdays.h"

int day = 1;
int curHour = 0;
int curMin = 0;

void lookAtClock(int hours, int minutes) {
    if(hours < curHour) {
        day++;
    } else if(hours == curHour) {
        if(minutes < curMin) {
            day++;
        }
    }
    curHour = hours;
    curMin = minutes;
}

int getDay() {
    return day;
}