//
// Created by Arturan on 13.03.2021.
//

#include <iostream>
#include "Observer.hpp"

void Observer::notifyAll(const Observer::BaseArgs &eventArgs) {
    for (auto& i: subscribers){
        i->notify(eventArgs);
    }
    for (auto& i: callbacks){
        (*i)(eventArgs);
    }
}

void Observer::subscribe(Observer::Subscriber *sub) {
    std::cout << "+Subscriber" << std::endl;
    subscribers.insert(sub);
    sub->subscribedTo.insert(this);
}

void Observer::unsubscribe(Observer::Subscriber *sub) {
    std::cout << "-Subscriber" << std::endl;
    subscribers.erase(sub);
    sub->subscribedTo.erase(this);
}

void Observer::subscribe(void (*callback)(const Observer::BaseArgs& eventArgs)) {
    callbacks.insert(callback);
}

void Observer::unsubscribe(void (*callback)(const Observer::BaseArgs &)) {
    callbacks.erase(callback);
}

Observer::Subscriber::~Subscriber() {
    while (!subscribedTo.empty()){
        auto& b = *subscribedTo.begin();
        b->unsubscribe(this);
        subscribedTo.erase(b);
    }
}

void Observer::Subscriber::notify(const Observer::BaseArgs &eventArgs) const {
    onNotified(eventArgs);
}

