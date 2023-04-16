#pragma once

class Survey {
public:
  Survey() : count(0), total_wait(0) {};
  void takeInfo(int wait_time);
  int getCount();
  double getAvgWait();

private:
  int count;
  int total_wait;
};