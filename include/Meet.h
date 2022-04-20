#ifndef _MEET_H_
#define _MEET_H_

#include "Team.h"

/**
 * A wrestling meet, with two or three teams.
 */
class Meet
{
public:
	/**
	 * A type of meet. Either dual (two teams),
	 * double dual (1 vs 2, 1 vs 3), or triple
	 * (1 vs 2, 1 vs 3, 2 vs 3)
	 */
	enum MeetType
	{
		DUAL,
		DOUBLE_DUAL,
		TRI
	};

	Meet(Team *team1, Team *team2);
	Meet(MeetType type, Team *team1, Team *team2, Team *team3 = nullptr);
	~Meet();

	Team* getTeam(const int index) const;
	MeetType getType() const;

	Team** getVsTeams(const int index) const;
	std::string getVsStrs(const int index) const;

private:
	/**
	 * The type of this meet
	 */
	MeetType type;

	/**
	 * The teams in this meet
	 */
	Team **teams;
};

#endif // _MEET_H_
