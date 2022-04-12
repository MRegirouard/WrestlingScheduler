#ifndef _TEAM_H_
#define _TEAM_H_

#include <string>

/**
 * A wrestling team. Holds a rank and name.
 */
class Team
{
public:
	Team(const int rank, const std::string name);
	Team(const int rank, const char* name);
	~Team();

	void setRank(const int rank);
	int getRank() const;

	void setName(const std::string name);
	void setName(const char* name);
	std::string getName() const;
private:
	/**
	 * The rank of this team.
	 */
	int rank;

	/**
	 * The name of this team.
	 */
	std::string name;
};

#endif // _TEAM_H_
