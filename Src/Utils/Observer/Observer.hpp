//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_OBSERVER_HPP
#define TBRPG_OBSERVER_HPP

#include <vector>
#include "ObserverSubscriber.hpp"
#include <memory>
class Observer {
private:
    std::vector<std::shared_ptr<ObserverSubscriber>> subscribers;
public:
    Observer() = default;
    void notifyAll(){
        for (auto& i: subscribers){
            i->notify();
        }
    }
    void subscribe(const std::shared_ptr<ObserverSubscriber>& sub) {
        subscribers.push_back(sub);
    }

};


#endif //TBRPG_OBSERVER_HPP
