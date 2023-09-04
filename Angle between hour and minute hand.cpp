#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int getAngle(int hour, int minutes) {
    if (hour == 12) hour = 0;
    if (minutes == 60) {
      minutes = 0;
      hour += 1;
      if (hour > 12) hour -= 12;
    }
    // 60 minutes --> 360 degree
    // 1 minute --> 6 degrees
    // m minutes --> 6 * m degrees

    // For calculating the hour angle we will convert the hour into minutes
    // for 1 hour the hour angle move by ==> 360/12 == 30
    // for m minutes the hour angle move by ==> (m/60) * 30 == m/2.
    // for n hour and m minutes the hour angle move by ==> (n*60 + m)/2

    float hour_angle = 0.5 * (hour * 60 + minutes);
    float minute_angle = 6 * minutes;
    float angle = abs(hour_angle - minute_angle);
    return min(360 - angle, angle);
  }
};