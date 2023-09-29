#include "subject.h"
#include "Observer.h"

void Subject::registerObserver(Observer *observer)
{
    observers_.insert(observer);
}

void Subject::unregisterObserver(Observer *observer)
{
    observers_.erase(observer);
}

void Subject::notifyObservers()const
{
    for (Observer * observer : observers_)
    {
        observer->Update(this);
    }
}

 // namespace nvs
