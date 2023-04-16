#pragma once

#include "customer.hpp"

class Service {
public:
  Service() : has_customer(false), working(0, 0) {};
  bool isReady();
  void hello(Customer busybody);
  bool doWork();
  Customer goodbye();


private:
  bool has_customer;
  Customer working;
};