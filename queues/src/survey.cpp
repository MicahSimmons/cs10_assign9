
#include "survey.hpp"

void 
Survey::takeInfo(int wait_time) {
    count++;
    total_wait += wait_time;
}

int 
Survey::getCount() {
    return count;
}

double 
Survey::getAvgWait() {
    return ((double)total_wait) / count;
}
