#pragma once

class Observer
{
public:
	virtual void update() = 0;
	virtual void pull_update() = 0;
};

class Subject
{
public:
	virtual void add_observer(Observer *observer) = 0;
	virtual void delete_observer(Observer *observer) = 0;
	virtual void notify_observers() const = 0;
	virtual void notify_observer(Observer *observer) const = 0;
};