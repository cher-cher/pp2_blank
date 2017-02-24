#include "stdafx.h"
#include "Bank.h"
#include "BankClient.h"


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

int main()
{
	CBank* bank = new CBank();
	CBankClient* client1 = bank->CreateClient();
	CBankClient* client2 = bank->CreateClient();

	// TODO: WaitForMultipleObjects
	while (true)
	{

	}

    return 0;
}