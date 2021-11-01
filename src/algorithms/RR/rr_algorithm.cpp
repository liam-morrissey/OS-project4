#include "algorithms/RR/rr_algorithm.hpp"

#include <cassert>
#include <stdexcept>

#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"

/*
    Here is where you should define the logic for the RR algorithm.
*/

RRScheduler::RRScheduler(int slice) {
    if (slice <= 0) {
        throw("RR must have a timeslice > 0");
    }
    this->time_slice = slice;
}

std::shared_ptr<SchedulingDecision> RRScheduler::get_next_thread() {
        std::shared_ptr<SchedulingDecision> decision;
        if(this->empty()){
            decision->explanation = "No threads available for scheduling.";
            decision->thread = nullptr;
            return decision;
        }
        decision->thread = ready_queue.front();
        decision->explanation = "Selected from " + std::to_string(ready_queue.size())+ " threads. Will run for at most "+std::to_string(this->time_slice)+" ticks.";
        ready_queue.pop();
        if(decision->thread->bursts.front()->length>this->time_slice){
            decision->thread->bursts.front()->update_time(this->time_slice);
            ready_queue.push(decision->thread);
        }
        
        return decision;
        
}

void RRScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
        // TODO: implement me!
        ready_queue.push(thread);
}

size_t RRScheduler::size() const {
        // TODO: implement me!
        return ready_queue.size();
}
