
#include "app.hpp"

#include "door.hpp"
#include "customer.hpp"
#include "waiting.hpp"
#include "service.hpp"
#include "survey.hpp"


int
App::run () {
    int time = 0;
    Door door(this->datafile);
    WaitingLine waiting;
    Service counter;
    Survey survey;

    cout << "Simulation Begins" << endl;

    /* The day is over, when:
     *   no more customers are at the door 
     *   the line is empty
     *   the service counter is free
     */
    while ((door.isEmpty() == false) ||
           (waiting.isEmpty() == false) ||
           (counter.isReady() == false)
          )
     {

        /* If any customers are at the door, then let them in */
        if (door.isReady(time)) {
            auto event = door.open();

            cout << "Processing an arrival event at time: " << event.entry_time << endl;
            Customer happy_customer(event.entry_time, event.work_time);
            waiting.wait(happy_customer);
        }
        
        if (counter.isReady() == false) {
            /* If the service counter is occupied, then do some work, until done */
            if (counter.doWork()) {
                /* Work is done! Please complete our survey.  
                 * Your input is important to us. 
                 * Please only give me 8's and 9's.
                 */
                cout << "Processing an departure event at time: " << time << endl;
                auto tired_customer = counter.goodbye();
                tired_customer.setEndTime(time);
                survey.takeInfo(tired_customer.getWaitTime());
            }
        }

        if (counter.isReady()) {
            /* If the service counter is empty, take the next person from the line if any */
            if (waiting.isReady()) {
                auto annoyed_customer = waiting.next();
                annoyed_customer.setQueueTime(time);

                counter.hello(annoyed_customer);
            }
        }

        time++;
    }

    cout << "Simulation Ends" << endl;

    cout << endl;
    cout << "Final Statistics:" << endl;
    cout << "   " << "Total number of people processed: " << survey.getCount() << endl;
    cout << "   " << "Average amount of time spent waiting: " << survey.getAvgWait() << endl;

    return 0;
}