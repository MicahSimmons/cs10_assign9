#pragma once

#include <iostream>
#include <string>
#include <queue>

class EntryEvent {
public:
   int entry_time;
   int work_time;
   EntryEvent(int entry, int work) : 
     entry_time(entry), work_time(work) 
     {}

    void print() { cout << entry_time << " : " << work_time << ";" << endl; };
};

class Door {
public:
    Door(string filename);
    bool isReady(int time);
    bool isEmpty();
    EntryEvent open();

private:
    queue<EntryEvent> events;
};