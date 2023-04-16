
#include "waiting.hpp"

bool 
WaitingLine::isEmpty() {
    return (this->the_line.size() == 0);
}

bool 
WaitingLine::isReady() {
    return (this->the_line.size() > 0);
}

void 
WaitingLine::wait(Customer new_customer) {
    this->the_line.push(new_customer);
}

Customer 
WaitingLine::next() {
    auto annoyed_customer = this->the_line.front();
    this->the_line.pop();
    return annoyed_customer;
}
