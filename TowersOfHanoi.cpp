// TowersOfHanoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using std::cout;
using std::endl;
using std::string;

struct rod
{
	std::stack<int> disks;
};

void print_rod(string rodName, rod rod)
{
	cout << rodName << endl;
	while (!rod.disks.empty())
	{
		cout << rod.disks.top() << "|";
		rod.disks.pop();
	}
	cout << endl;
}

void solve_towers_of_hanoi(int numberOfDisks, rod& source, rod& temp, rod& destination)
{
	if (numberOfDisks >= 2)
	{
		solve_towers_of_hanoi(numberOfDisks - 1, source, destination, temp);
		auto lastDisk = source.disks.top(); source.disks.pop();
		destination.disks.push(lastDisk);
		solve_towers_of_hanoi(numberOfDisks - 1, temp, source, destination);
	}
	else
	{
		auto oneDisk = source.disks.top(); source.disks.pop();
		destination.disks.push(oneDisk);
	}
}

void initialize_rod_with_N_disks(rod& theRod, int number_of_disks)
{
	auto i = number_of_disks;
	while (i > 0)
	{
		theRod.disks.push(i--);
	}
}

int _tmain(int argc, _TCHAR* argv [])
{
	rod rod1 = rod();
	rod rod2 = rod();
	rod rod3 = rod();

	initialize_rod_with_N_disks(rod1, 23);

	print_rod("rod1", rod1);
	print_rod("rod2", rod2);
	print_rod("rod3", rod3);

	solve_towers_of_hanoi(rod1.disks.size(), rod1, rod2, rod3);

	print_rod("rod1", rod1);
	print_rod("rod2", rod2);
	print_rod("rod3", rod3);

	getchar();

	return 0;
}

