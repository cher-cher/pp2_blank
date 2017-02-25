#include "stdafx.h"
#include "Bank.h"
#include "BankClient.h"


const std::string HELP_FLAG = "/?";

void PrintHelp()
{
	std::cout << "***Help:" << std::endl
		<< "PP2.exe <Amount Clients> <Synchronization Primitive Type>" << std::endl
		<< "PP2.exe /? - to print help" << std::endl
		<< "Synhronization Primitive Type:" << std::endl
		<< "	1 - CriticalSection" << std::endl
		<< "	2 - Mutex" << std::endl
		<< "	3 - Semaphore" << std::endl
		<< "	4 - Event" << std::endl;
	std::cout << "***" << std::endl;
}

bool CorrectArqumentsCount(int argc)
{
	return argc == 2 || argc == 3;
}

bool IsCorrectSynchronizationPrimitives(char * argv[], SynchronizationPrimitives &type)
{
	int value = atoi(argv[2]);
	switch (value)
	{
	case 1:
		type = CriticalSection;
		break;
	case 2:
		type = Mutex;
		break;
	case 3:
		type = Semaphore;
		break;
	case 4:
		type = Event;
		break;
	default:
		return false;
	}
	return true;
}

int main(int argc, char * argv[])
{
	if (!CorrectArqumentsCount(argc))
	{
		std::cout << "Incorrect arguments count. Usage /? flag to get help" << std::endl;
		return 1;
	}
	if (argv[1] == HELP_FLAG)
	{
		PrintHelp();
		return 1;
	}
	size_t clientsCount = size_t(atoi(argv[1]));
	SynchronizationPrimitives type;
	if (!IsCorrectSynchronizationPrimitives(argv, type))
	{
		std::cout << "Incorrect second argument!";
		PrintHelp();
		return 1;
	}
	CBank bank(type);
	for (size_t index = 0; index < clientsCount; ++index)
	{
		bank.CreateClient();
	}
	bank.CreateThreads();
	bank.WaitThreads();
	return 0;
}