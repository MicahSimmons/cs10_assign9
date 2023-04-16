#include <iostream>
using namespace std;

#include "customer.hpp"

void
Customer::setEndTime(int end_time) {
    this->end_timestamp = end_time;
}

void
Customer::setQueueTime(int queue_time) {
    this->queue_timestamp = queue_time;
}

bool
Customer::doWork() {
    this->work_remaining--;
    return (this->work_remaining <= 0);
}

int
Customer::getWaitTime() {
    return this->queue_timestamp - this->start_timestamp;
}
