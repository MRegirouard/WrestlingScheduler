#include "Schedule.h"

/**
 * Create a new schedule with the given number of weeks.
 * @param weekCount The number of weeks in the schedule.
 */
Schedule::Schedule(const int weekCount)
: weekCount(weekCount)
{
	weeks = new Week*[weekCount];

	for (int i = 0; i < weekCount; i++)
		weeks[i] = new Week();
}

/**
 * Destroy this schedule, deleting the weeks.
 */
Schedule::~Schedule()
{
	for (int i = 0; i < weekCount; i++)
		delete weeks[i];

	delete[] weeks;
}

/**
 * Adds a meet to the given week number.
 * @param weekNum The week number to add a meet to, starting at 0.
 * @param meet The meet to add.
 */
void Schedule::addMeet(const int weekNum, Meet* meet)
{
	if (weekNum < 0 || weekNum >= weekCount)
		return;

	Week* week = getWeek(weekNum);

	week->addMeet(meet);
}

/**
 * Gets a week at the given index, starting at 0.
 * If an invalid index is given, returns nullptr.
 * @param weekNum The week number to get, starting at 0.
 * @return The week at the given index.
 */
Week *Schedule::getWeek(const int weekNum) const
{
	if (weekNum < 0 || weekNum >= weekCount)
		return nullptr;

	return weeks[weekNum];
}

/**
 * Gets the number of weeks in this schedule.
 * @return The number of weeks in this schedule.
 */
int Schedule::getWeekCount() const
{
	return weekCount;
}
