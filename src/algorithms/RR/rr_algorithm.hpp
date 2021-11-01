#ifndef RR_ALGORITHM_HPP
#define RR_ALGORITHM_HPP

#include <memory>
#include "algorithms/scheduling_algorithm.hpp"
#include <queue>

/*
    RRScheduler:
*/

class RRScheduler : public Scheduler {
public:

    //==================================================
    //  Member variables
    //==================================================

    // TODO: Add any member variables you may need.
    //queue
    std::queue<std::shared_ptr<Thread>> ready_queue;

    //==================================================
    //  Member functions
    //==================================================

    RRScheduler(int slice = 3);

    std::shared_ptr<SchedulingDecision> get_next_thread();

    void add_to_ready_queue(std::shared_ptr<Thread> thread);

    size_t size() const;

};

#endif
