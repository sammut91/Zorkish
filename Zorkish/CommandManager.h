#pragma once
#include "Command.h"
#include "Player.h"
#include <vector>
#include "QuitCommand.h"
#include "LookCommand.h"
#include "AliasCommand.h"
#include "MoveCommand.h"
#include "TakeCommand.h"
#include "PutCommand.h"
#include <algorithm>
#include <typeinfo>

class CommandManager
{
public:
	CommandManager();
	~CommandManager();
	void Initialise();
	void AddCommand(Command* cmd);
	void AddIdInit(std::string name, std::string newId);
	void AddNewId(std::string name, std::string newId);
	void InitialiseCmdIds();
	std::string Execute(Player &p, std::vector<std::string> input);

private:
	std::vector<Command*> m_commands;
};

