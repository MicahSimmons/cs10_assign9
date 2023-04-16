
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


#include "door.hpp"

Door::Door(string filename) {
    ifstream input_file(filename);
    if (input_file.is_open()) {
        cout << "File successfully opened." << endl;

        /* Extract the file contents and convert to a stream of ints */
        string line;
        while (getline(input_file, line)) {
          stringstream ss(line);
          vector<int> values;
          string token;
          while (getline(ss, token, ' ')) {
            try {
                int value = stoi(token);
                values.push_back(value);
            } catch (std::invalid_argument) {
                /* nop */
            }
          }

          if (values.size() == 2) {
            EntryEvent entry(values[0], values[1]);
            this->events.push(entry);
          }

        }
    }
}

bool 
Door::isReady(int time) {
    return ((this->events.empty() == false) &&
            (this->events.front().entry_time <= time));
}

bool 
Door::isEmpty() {
    return (this->events.empty());
}

EntryEvent
Door::open() {
    auto event = this->events.front();
    this->events.pop();
    return event;
}