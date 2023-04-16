#pragma once

#include <queue>
using namespace std;

#include "customer.hpp"

class WaitingLine {
public:
    WaitingLine() {};
    bool isEmpty();
    bool isReady();
    void wait(Customer new_customer);
    Customer next();

private:
    queue<Customer> the_line;
};