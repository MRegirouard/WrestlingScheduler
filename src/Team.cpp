#include "Team.h"

/**
 * Create a new team, with the given rank and name.
 * @param rank The rank of the team.
 * @param name The name of the team.
 */
Team::Team(const int rank, const std::string name)
{
	this->rank = rank;
	this->name = name.c_str();
}

/**
 * Create a new team, with the given rank and name.
 * @param rank The rank of the team.
 * @param name The name of the team.
 */
Team::Team(const int rank, const char* name)
{
	this->rank = rank;
	this->name = name;
}

/**
 * Destroy this team. Deletes the name.
 */
Team::~Team()
{
	delete this->name;
}

/**
 * Set the rank of this team.
 * @param rank The new rank of this team.
 */
void Team::setRank(const int rank)
{
	this->rank = rank;
}

/**
 * Get the rank of this team.
 * @return The rank of this team.
 */
int Team::getRank() const
{
	return this->rank;
}

/**
 * Set the name of this team.
 * @param name The new name of this team.
 */
void Team::setName(const std::string name)
{
	this->name = name.c_str();
}

/**
 * Set the name of this team.
 * @param name The new name of this team.
 */
void Team::setName(const char* name)
{
	this->name = name;
}

/**
 * Get the name of this team.
 * @return The name of this team.
 */
const char* Team::getName() const
{
	return this->name;
}
