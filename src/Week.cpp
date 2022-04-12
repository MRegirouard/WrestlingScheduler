#include "Week.h"

/**
 * Create a new week.
 */
Week::Week()
{
	meets = new std::vector<Meet*>();
}

/**
 * Destroy this week.
 */
Week::~Week()
{
	delete meets;
}

/**
 * Add a meet to this week.
 */
void Week::addMeet(Meet *meet)
{
	meets->push_back(meet);
}

/**
 * Get the full vector of meets in this week.
 * @return The vector of meets.
 */
std::vector<Meet*>* Week::getMeets() const
{
	return meets;
}

/**
 * Get a specific meet in this week.
 * @param index The index of the meet to get.
 * @return The meet at the specified index.
 */
Meet* Week::getMeet(const int index) const
{
	return meets->at(index);
}
