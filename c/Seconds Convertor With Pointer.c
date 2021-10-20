#include <stdio.h>


void split_time(long total_sec, int * hr, int * min, int * sec){
   int hour = *hr;
    hour = (hour/60/60);
    double minutes = *min;
    minutes = minutes/60/60;
    minutes = (minutes - hour) *60;
    double seconds = minutes - (int)minutes;
    seconds = seconds*60;
    if(hour<12){
        hour = hour-12;
        printf("%d:%0.f.%0.fam = %ld seconds",hour,minutes,seconds,total_sec);
    } else if (hour<24&&hour>=12){
        hour = hour-12;
        printf("%d:%0.f.%0.fpm = %ld seconds",hour,minutes,seconds,total_sec);
    }
}


int main() {
    long total_sec = 62605;
    int * hr = (int *) &total_sec;
    int * min = (int *) &total_sec;
    int * sec = (int *) &total_sec;
    split_time(total_sec,hr,min,sec);
}
