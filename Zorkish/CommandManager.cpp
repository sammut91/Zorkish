#include "CommandManager.h"

CommandManager::CommandManager()
{
	Initialise();
}


CommandManager::~CommandManager()
{
}

void CommandManager::Initialise()
{
	AddCommand(QuitCommand::Instance());
	AddCommand(LookCommand::Instance());
	AddCommand(MoveCommand::Instance());
	AddCommand(AliasCommand::Instance());
	AddCommand(TakeCommand::Instance());
	AddCommand(PutCommand::Instance()); 
	AddCommand(TalkCommand::Instance());
	InitialiseCmdIds();

}

void CommandManager::AddCommand(Command* cmd)
{
	if (!(std::find(m_commands.begin(), m_commands.end(), cmd) != m_commands.end()))
	{
		m_commands.push_back(cmd);
	}
}

std::string CommandManager::Execute(Player &p, std::vector<std::string> input)
{
	std::vector<Command*>::iterator iter, end;
	if (!m_commands.empty())
	{
		for (auto &element : m_commands)
		{
			std::transform(input.front().begin(), input.front().end(), input.front().begin(), ::tolower);
			if (element->AreYou(input.front()))
			{
				if (element->GetId() == "alias")
				{
					AliasCommand* obj = dynamic_cast<AliasCommand*>(element);
					return obj->Execute(this, input);
				}
				return element->Execute(p, input);
			}
		}
		return "Please enter a valid command";
	}
}

void CommandManager::AddIdInit(std::string name, std::string newId)
{
	if (!m_commands.empty())
	{
		for (auto &element : m_commands)
		{
			if (element->GetId() == name)
				element->AddIdentifier(newId);
		}
	}
}

void CommandManager::AddNewId(std::string id, std::string newId)
{
	if (!m_commands.empty())
	{
		for (auto &element : m_commands)
		{
			if (element->AreYou(id))
				element->AddIdentifier(newId);
		}
	}
}

void CommandManager::InitialiseCmdIds()
{
	AddIdInit("look", "peek");
	AddIdInit("look", "look");
	AddIdInit("move", "go");
	AddIdInit("move", "move");
	AddIdInit("move", "head");
	AddIdInit("quit", "exit");
	AddIdInit("quit", "quit");
	AddIdInit("alias", "alias");
	AddIdInit("take", "take");
	AddIdInit("put", "put");
	AddIdInit("put", "drop");
	AddIdInit("talk", "talk");
	AddIdInit("talk", "say");
	AddIdInit("talk", "are");
	AddIdInit("talk", "what");
}