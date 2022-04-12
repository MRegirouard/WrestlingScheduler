#ifndef _WEEK_H_
#define _WEEK_H_

#include "Meet.h"
#include <vector>

/**
 * A week of the schedule.
 */
class Week
{
public:
	Week();
	~Week();

	void addMeet(Meet *meet);
	std::vector<Meet*>* getMeets() const;

	Meet* getMeet(const int index) const;

private:
	/**
	 * The vector of meets in this week.
	 */
	std::vector<Meet*> *meets;
};

#endif // _WEEK_H_
