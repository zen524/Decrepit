#include <iostream>
using namespace std;

struct item
{
	int itemLoc;
	int defaultLoc;
	enum status {FREE, EVENTLOCKED, HELD, DELETED};
	
}