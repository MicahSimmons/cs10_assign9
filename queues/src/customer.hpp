#pragma once

#include <iostream>
using namespace std;

class Customer {
public:
    Customer(int start_time, int work_time) :
      start_timestamp(start_time), work_time(work_time), work_remaining(work_time)
      {
      }

    bool
    doWork();

    void
    setEndTime(int end_time);

    void
    setQueueTime(int queue_time);

    int
    getWaitTime();

private:
    int start_timestamp;
    int work_time;
    int work_remaining;
    int queue_timestamp;
    int end_timestamp;
};