//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_OBSERVERSUBSCRIBER_HPP
#define TBRPG_OBSERVERSUBSCRIBER_HPP

template<class EventArgs>
class ObserverSubscriber {
public:
    void notify(const EventArgs& eventArgs){
        onNotified(eventArgs);
    }
    virtual void onNotified(const EventArgs& eventArgs) = 0;
};


#endif //TBRPG_OBSERVERSUBSCRIBER_HPP
