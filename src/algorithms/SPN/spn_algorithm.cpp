#include "algorithms/SPN/spn_algorithm.hpp"

#include <cassert>
#include <stdexcept>

#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"

/*
    Here is where you should define the logic for the SPN algorithm.
*/

SPNScheduler::SPNScheduler(int slice) {
    if (slice != -1) {
        throw("SPN must have a timeslice of -1");
    }
}

std::shared_ptr<SchedulingDecision> SPNScheduler::get_next_thread() {
        std::shared_ptr<SchedulingDecision> decision;
        if(this->empty()){
            decision->explanation = "No threads available for scheduling.";
            decision->thread = nullptr;
            return decision;
        }
        decision->thread = ready_queue.top();
        decision->explanation = "Selected from " + std::to_string(ready_queue.size())+ " threads. Will run to completion of burst.";
        ready_queue.pop();
        return decision;
        
}

void SPNScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
        // TODO: might need to make length negative so that smallest time == largest priority
        ready_queue.push(thread->bursts.front()->length,thread);
}

size_t SPNScheduler::size() const {
        // TODO: implement me!
        return ready_queue.size();
}
