#include "Meet.h"

/**
 * Create a new Meet with two teams, a dual meet
 * @param team1 The first team
 * @param team2 The second team
 */
Meet::Meet(Team *team1, Team *team2)
{
	teams = new Team*[2];
	teams[0] = team1;
	teams[1] = team2;
	type = DUAL;
}

/**
 * Create a new Meet with a type and two or three teams
 * @param type The type of meet
 * @param team1 The first team
 * @param team2 The second team
 * @param team3 The third team, defaults to nullptr
 */
Meet::Meet(MeetType type, Team *team1, Team *team2, Team *team3)
{
	if (team3 == nullptr || type == DUAL)
	{
		this->type = DUAL;
		this->teams = new Team*[2];
		this->teams[0] = team1;
		this->teams[1] = team2;
	}
	else
	{
		this->type = type;
		this->teams = new Team*[3];
		this->teams[0] = team1;
		this->teams[1] = team2;
		this->teams[2] = team3;
	}
}

/**
 * Destroy this meet. Deletes the teams array
 */
Meet::~Meet()
{
	delete[] teams;

}

/**
 * Get the team at the given index. If the index is out
 * of bounds, (0-1 for a dual meet, 0-2 for a triple meet),
 * nullptr is returned
 * @param index The index of the team to get
 * @return The team at the given index, or nullptr
 */
Team* Meet::getTeam(const int index) const
{
	if (index < 0)
		return nullptr;

	if (type == DUAL)
	{
		if (index > 1)
			return nullptr;
	}
	else
	{
		if (index > 2)
			return nullptr;
	}

	return this->teams[index];
}

/**
 * Get the type of this meet
 * @return This meet's type
 */
Meet::MeetType Meet::getType() const
{
	return this->type;
}

/**
 * Get the teams that the given team index
 * will play against in this meet.
 * @param index The index of the team to get the vs teams for
 * @return The teams that the given team index will play against.
 * Returns nullptr if the index is out of bounds, and returns
 * nullptr for the second team if this team only plays one team.
 */
Team** Meet::getVsTeams(const int index) const
{
	if (index < 0 || index > 2)
		return nullptr;

	Team* team = getTeam(index);

	if (team == nullptr)
		return nullptr;

	Team** teams = new Team*[2];

	teams[0] = getTeam(index == 0);

	if (index == 0)
		teams[1] = getTeam(2);
	else if (type == TRI)
		teams[1] = getTeam(3 - index);
	else
		teams[1] = nullptr;

	return teams;
}

/**
 * Gets the strings that represent the teams that
 * the given team index will play against in this meet.
 * @param index The index of the team to get the vs strings for.
 * @return A string continaing "vs" and the names of the opposing teams.
 */
std::string Meet::getVsStrs(const int index) const
{
	Team** teams = getVsTeams(index);

	if (teams == nullptr)
		return "";

	std::string str = "";

	if (teams[0] != nullptr)
	{
		str += "vs " + teams[0]->getName();

		if (teams[1] != nullptr)
			str += ", " + teams[1]->getName();
	}

	delete[] teams;

	return str;
}
