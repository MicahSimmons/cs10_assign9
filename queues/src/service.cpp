
#include "service.hpp"


bool 
Service::isReady() {
    return (this->has_customer == false);
}

void 
Service::hello(Customer busybody) {
    this->working = busybody;
    this->has_customer = true;
}

bool 
Service::doWork() {
    return this->working.doWork();
}

Customer 
Service::goodbye() {
    this->has_customer = false;
    return this->working;
}