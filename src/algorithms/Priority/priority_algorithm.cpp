#include "algorithms/Priority/priority_algorithm.hpp"

#include <cassert>
#include <stdexcept>

#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"

/*
    Here is where you should define the logic for the Priority algorithm.
*/

PriorityScheduler::PriorityScheduler(int slice) {
    if (slice != -1) {
        throw("Priority must have a timeslice of -1");
    }
}

std::shared_ptr<SchedulingDecision> PriorityScheduler::get_next_thread() {
        std::shared_ptr<SchedulingDecision> decision;
        if(this->empty()){
            decision->explanation = "No threads available for scheduling.";
            decision->thread = nullptr;
            return decision;
        }
        decision->thread = ready_queue.top();
        decision->explanation = "[S: "+std::to_string(priority_counts[0])+" I: "+std::to_string(priority_counts[1])+" N: "+std::to_string(priority_counts[2])+" B: "
        +std::to_string(priority_counts[3])+"] ";
        priority_counts[decision->thread->priority] --;
        ready_queue.pop();
        decision->explanation = decision->explanation +"-> "+"[S: "+std::to_string(priority_counts[0])+" I: "+std::to_string(priority_counts[1])+" N: "+std::to_string(priority_counts[2])+" B: "
        +std::to_string(priority_counts[3])+"]. Will run to completion of burst.";
        return decision;
        
}

void PriorityScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
        // TODO: determine if the priority needs to be flipped (ie made negative)
        ready_queue.push(thread->priority,thread);
        priority_counts[thread->priority]++;
        
}

size_t PriorityScheduler::size() const {
        // TODO: implement me!
        return ready_queue.size();
}
