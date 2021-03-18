//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_OBSERVER_HPP
#define TBRPG_OBSERVER_HPP

#include <vector>
#include <memory>
#include <set>

class Observer {
public:
    struct BaseArgs {

    };
    class Subscriber {
    public:
        Subscriber() = default;
        ~Subscriber();
        std::set<Observer*> subscribedTo;
        void notify(const BaseArgs& eventArgs) const;
        virtual void onNotified(const BaseArgs& eventArgs) const = 0;
    };
    Observer() = default;
    void notifyAll(const BaseArgs& eventArgs);
    void subscribe(Subscriber* sub);
    void subscribe(void (*callback)(const Observer::BaseArgs& eventArgs));
    void unsubscribe(Subscriber* sub);
    void unsubscribe(void (*callback)(const Observer::BaseArgs& eventArgs));

protected:
    std::set<Subscriber*> subscribers;

private:
    std::set<void(*)(const BaseArgs&)> callbacks;

};


#endif //TBRPG_OBSERVER_HPP
