#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int getAngle(int hour, int minutes) {
    if (hour == 12) hour = 0;
    if (minutes == 60) {
      minutes = 0;
      hour += 1;
      if (hour > 12) hour = hour - 12;
    }
    // 60 --> 1 hour
    // minutes min --> (1/60)*minutes hour
    // for 1 hour ---> 30 degree
    // (1/60)*minutes hour ---> (1/60)*minutes*30===> minutes/2;
    float hour_angle = 0.5 * (hour * 60 + minutes);
    float minute_angle = 6 * minutes;
    float angle = abs(hour_angle - minute_angle);
    return min(360 - angle, angle);
  }
};