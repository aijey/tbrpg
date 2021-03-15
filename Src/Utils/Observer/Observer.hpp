//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_OBSERVER_HPP
#define TBRPG_OBSERVER_HPP

#include <vector>
#include "ObserverSubscriber.hpp"
#include <memory>
template<class EventArgs>
class Observer {
private:
    std::vector<std::shared_ptr<ObserverSubscriber<EventArgs>>> subscribers;
public:
    Observer() = default;
    void notifyAll(const EventArgs& eventArgs){
        for (auto& i: subscribers){
            i->notify(eventArgs);
        }
    }
    void subscribe(const std::shared_ptr<ObserverSubscriber<EventArgs>>& sub) {
        subscribers.push_back(sub);
    }

};


#endif //TBRPG_OBSERVER_HPP
