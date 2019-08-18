#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Observer.h"


using namespace std;

class TeamMember : public Observer
{
private:
	Subject *MeetingInfo;
	string mTime;
	string mPlace;
	string mName;
	
public:
	// Observer을(를) 통해 상속됨
	virtual void update() override
	{
		cout << mName << "님! 정보가 업데이트 되었습니다!" << endl;
	}
	virtual void pull_update() override
	{
		MeetingInfo->notify_observer(this);
	}

	TeamMember(string name,  Subject* publisher)
		:mName(name), MeetingInfo(publisher)
	{
		MeetingInfo->add_observer(this);
	}

	void unsubscribe()
	{
		MeetingInfo->delete_observer(this);
		cout << mName << "님! 구독 해제를 완료했습니다." << endl;
	}
	
};

class MeetingInfo : public Subject
{
private:
	vector<Observer*> observerList;
	string mTime;
	string mPlace;
public:
	explicit MeetingInfo(string time, string place)
		:mTime(time), mPlace(place)
	{

	}
	~MeetingInfo()
	{

	}
	// Subject을(를) 통해 상속됨
	virtual void add_observer(Observer * observer) override
	{
		observerList.push_back(observer);
	}
	virtual void delete_observer(Observer * observer) override
	{
		auto toDelete = find(observerList.begin(), observerList.end(), observer);
		if (toDelete != observerList.end())
		{
			observerList.erase(toDelete);
		}
		else
		{
			cout << "해당 정보의 구독자가 존재하지 않습니다." << endl;
		}
	}
	virtual void notify_observers() const override
	{
		for (auto observer : observerList)
		{
			observer->update();
		}
	}
	virtual void notify_observer(Observer *targetObserver) const override
	{
		auto i = find(observerList.begin(), observerList.end(), targetObserver);
		if (i != observerList.end())
		{
			targetObserver->update();
		}
		else
		{
			cout << "해당 구독자의 정보를 찾을 수 없습니다." << endl;
		}
	}

	string get_time() const
	{
		return mTime;
	}

	string get_place() const
	{
		return mPlace;
	}

	void set_time(string time)
	{
		mTime = time;
		notify_observers();
	}

	void set_place(string place)
	{
		mPlace = place;
		notify_observers();
	}

	void set_all(string time, string place)
	{
		mTime = time, mPlace = place;
		notify_observers();
	}

};


int main()
{

	MeetingInfo *meetingInfo = new MeetingInfo("3시 20분", "종각 토즈");
	
	TeamMember t1("항복", meetingInfo);
	TeamMember t2("길동", meetingInfo);
	TeamMember t3("철수", meetingInfo);

	// 정보 업데이트
	meetingInfo->set_all("4시", "강남역 토즈");
	
	cout << endl;
	
	// 구독 해제
	t3.unsubscribe();

	cout << endl;

	// 정보 업데이트
	meetingInfo->set_place("청담동 토즈");

	cout << endl;

	t3.pull_update();
	t1.pull_update();

	return 0;
}