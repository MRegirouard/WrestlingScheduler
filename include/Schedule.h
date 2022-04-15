#ifndef _SCHEDULE_H_
#define _SCHEDULE_H_

#include "Week.h"

/**
 * A wrestling schedule, containing weeks with meets.
 */
class Schedule
{
public:
	Schedule(const int weekCount);
	~Schedule();

	void addMeet(const int weekNum, Meet* meet);

	Week* getWeek(const int weekNum) const;
	int getWeekCount() const;

private:
	const int weekCount;
	Week** weeks;
};

#endif // _SCHEDULE_H_
