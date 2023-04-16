#pragma once

#include <string>
using namespace std;

class App {
public:
  App(string datafile) : datafile(datafile) { };
  int run ();

private:
    string datafile;
};