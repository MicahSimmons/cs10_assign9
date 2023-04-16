
#include <iostream>
#include <cstdlib>
using namespace std;

#include "app.hpp"

class Args {
public:
  string filename;

  Args(int argc, char ** argv) {
    string cli_switch = "";
    for (int idx=0; idx<argc; idx++) {
      if (argv[idx][0] == '-') {
        cli_switch = argv[idx];
        continue;
      }

      switch (cli_switch[1]) {
        case 'd': { // datafile 
          this->filename = argv[idx];
        } break;

        default: break;
      }
    }
  }

  string getFilename() { return filename; };
};

int
main (int argc, char ** argv ) {
  Args args(argc, argv);
  App app(args.getFilename());
  app.run();
  return 0;
}
