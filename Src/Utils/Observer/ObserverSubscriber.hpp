//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_OBSERVERSUBSCRIBER_HPP
#define TBRPG_OBSERVERSUBSCRIBER_HPP


class ObserverSubscriber {
public:
    void notify(){
        onNotified();
    }
    virtual void onNotified() = 0;
};


#endif //TBRPG_OBSERVERSUBSCRIBER_HPP
