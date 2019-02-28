/*
Decrepit
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

string arg1, arg2, arg3, arg4;
string arg1transl;
int decrepit=1;
int location=1;

//Global events will simply be boolean variables.
bool pendantbroken=0;
bool pricked=0;
//I'll make global integer inventory variables to determine where each item is.
//Zero Represents "In player's inventory". Any other values will represent where the item is. -1 Represents "Destroyed".

//				ITEMS
int sword = 3;
int pendant = 2;


int main();

void helpscreen()
{
	system("cls");
	cout << endl << "This is where you see what your actions have done.\n";
	cout << endl << "================================================================\n" << endl;
	cout << "This is where you can see where you are and what's happening.\n";
	cout << endl << "This also tells you what items you can see in the area.";
	cout << endl << "_______________________________________________________________________";
	cout << endl<< endl<< "Please only use lower-case commands at the moment.\nDo not use 'a' or 'the'"<< endl<< endl;
	cout << "Available commands are:\nget(grab, take, pick up)\ngo(walk, run, venture, travel)\nAttack(hurt, hit, harm, BREAK)\nDrop(discard, leave)\nExamine(Look at)\nItems(bag, inv, inventory, pack)";
	cout << endl << endl << "It pays to examine your items.\n";
	cout << endl << "You can view this screen at any time by saying 'help'.";
	cout << endl << "Press Enter to return...";
	cin.ignore();
}
void items()
{													//Make an array of pointers to loop through the inventory??
	//Make a switch feed inside of a for loop that prints out if the user has each item.
	system("cls");
	
	cout << "\nYour current inventory:\n\n";
	if (sword==0)
	cout << "Sword\n";
	if (pendant==0)
	{
		if (pendantbroken==0)
		cout << "Curious Pendant\n\n";
		else if (pendantbroken==1)
		cout << "Broken Pendant\n\n";
	}
	
	cout << "\nPress Enter to return...";
	cin.ignore();
	cin.ignore();
	system("cls");
}

void transition (int whereto)
{
	system("cls");
	int line, position;
	for (line = 1; line < 50; line++) 
	{
		//This loop prints the numbers leading up to the line number in a single line.
		for (position = 1; position <= line; position++) 
		{
			cout << '*';
		}
		cout << endl;
		//And this indicates the end of the line.
	}
	
	for (line = line; line > 0; line--) 
	{
		//This loop prints the numbers leading up to the line number in a single line.
		for (position = 1; position <= line; position++) 
		{
			cout << '*';
		}
		cout << endl;
		//And this indicates the end of the line.
	}
	location=whereto;
	system("cls");
}

void examine()												//ARG1==EXAMINE
{
	if (arg2=="sword" && (sword==0||sword==location))
	cout << "It's a sword. Frankly, the only peculiar thing about it is the anachronisy.\n";
	
	else if ((arg2=="pendant"||arg2=="dickbutt"||arg2=="insignia") && (pendant==0||pendant==location))
	{
		if (pendantbroken==0)
		cout << "You look closer at the pendant.\nYou could swear that you see an occasional flicker of light struggling \nfrom inside, but it disappears before you can be sure.\n";
		else if (pendantbroken==1)
		switch (location)
		{
		case 1:
			cout << "The symbol is glowing white-hot now. You drop it and jump away. \nAs it clatters to the ground, it emits a blinding light.\nWhen you can see again, the city is more vibrant." << endl;
			cout << "The alley is no longer in ruins, \nthe buildings are whole, and the alley is clean.\n";
			decrepit=0;
			break;
		case 2:
			cout << "The insignia is shining now with a dim, white glow.\n";
			cout << "You feel like it's trying to lead you.\n";
			break;
		default:
			cout << "The pendant now lies broken in your hand. \nThe... 'insignia' seems to flicker with light.\n";
			cout << "It seems strangely lost here.\n";
			break;
		}
	}
	else
	{
		cout << "You don't see any " << arg2 << " here.\n";
	}
}
/*
void use()													//ARG1==USE
{
	cin>>arg2;
	cin>>arg3;
	if(arg3=="with"||arg3=="on"||arg3=="in"||arg3=="into"||arg3=="and")
	{
		cin>>arg4;
		arg3=arg4;
	}
	if ((arg2=="pendant" && arg3=="sword")||(arg2=="sword" && arg3=="pendant"))
	{
		arg1transl="attack";
		arg2=="pendant";
	}
}
*/
void drop()													//ARG1==DROP
{
	if (arg2=="sword" && sword==0)//Drop sword
	{	
		sword=location;
		cout << "You drop your sword.\n";
	}
	else if (arg2=="pendant" && pendant==0)//Drop pendant
	{	
		pendant=location;
		if (pendantbroken==0)
		{
			cout << "You drop the pendant.\nYou feel like you just lost a friend.\n";
		}
		else if (pendantbroken==1)
		{
			cout << "You drop the broken pendant.\n";
		}
	}
	else //Missing Item
	cout << "You don't have any " << arg2 << endl;
}

void processing()//=====================================================================================================================================================
{				//																PROCESSING
	if (arg1transl=="get")									//ARG1==GET
	{
		if(arg2=="sword" && sword==location)	//sword
		{
			cout << "You pick up the sword.\n";
			sword=0;
		}
		else if(arg2=="pendant" && pendant==location)//pendant
		{
			pendant=0;
			if (pendantbroken==0)
			cout << "You take the pendant from the ground. Its strange and intricate designs seem to seize your entire being, like it's calling you to look deeper.\n";
			if (pendantbroken==1)
			cout << "You pick up the broken pendant.\n";
		}
		else
		{
			cout << "You don't see any " << arg2 << " here." << endl;
		}
	}
	
	if(arg1transl=="attack")								//ARG1==ATTACK
	{
		if (arg2=="pendant")//pendant
		{
			if (pendant == 0 || pendant==location)
			{	
				if(sword==pendant || (pendant==location && sword==0) )
				{
					if (pendantbroken==0)
					{
						cout << "You break open the pendant with the sword. Inside is a small depic-\nGod fucking damn it, it's dickbutt." << endl;
						pendantbroken=1;
						if (pendant!=0)
						{
							cout << "You pick up the now-broken pendant.\n";
							pendant=0;
						}
					}
					else if (pendantbroken==1)
					cout << "The pendant is already broken.\n";
				}
				else
				{
					cout << "You try, but you can't break the pendant open with your bare hands.\n";
				}	
			}
			else
			cout << "You don't have any " << arg2 << endl;
		}
		else if (arg2=="sword")//sword
		cout << "Yeah, that's not gonna work.";
	}
	
	if(arg1=="switch")
	{
		if (decrepit==0)
		decrepit=1;
		else if (decrepit==1)
		decrepit=0;
	}
	
	if(arg1transl=="drop")
	drop();

	if(arg1transl=="examine")
	examine();

	if (arg1transl=="items")
	{
		items();
	}
	
	if (arg1=="fuck")
	{
		cin >> arg2;
		if(arg2=="bitches")
		cout << "Like you could even get bitches in the first place.\n";
	}
	
	if (arg1=="cheat")
	{
		sword=0;
		pendant=0;
		pendantbroken=1;
		cout << "Items acquired. Pendant broken.\n";
	}
}

void whatshere()
{
	cout << endl;
	
	if(sword==location)
	cout << "There is a sword lying on the ground here.\n";
	
	if(pendant==location)
	{
		if (pendantbroken==0)
		cout << "A strange-looking pendant catches your eye." << endl;
		else if (pendantbroken==1)
		cout << "The broken pendant lies here.\n";
	}
}

void decipher()//=======================================================================================================================================================
{//																				DECIPHER
	void decision();
	arg1transl.clear();
	
	arg3.clear();
	//cout << "arg1 is currently " << arg1 << endl;

	if (arg1=="north"||arg1=="east"||arg1=="south"||arg1=="west")//Cardinal Clause
	{
		arg1transl="go";
		arg2=arg1;
	}
	
	if (arg1=="put")
	{
		cin >> arg2;
		if(arg2=="down")
		{
			cin >> arg3;
			arg1 = "drop";
			arg2 = arg3;
		}
	}
	
	if (arg1=="kill"||arg1=="attack"||arg1=="hurt"||arg1=="hit"||arg1=="break")
	{
		arg1transl="attack";
		cin >> arg2;
		//cout << "Attacking ";
	}
	
	if (arg1=="go"||arg1=="walk"||arg1=="run"||arg1=="travel"||arg1=="venture"||arg1=="head")
	{
		arg1transl="go";
		cin >> arg2;
		//cout << "Moving ";
	}
	
	if (arg1=="inventory"||arg1=="inv"||arg1=="bag"||arg1=="pack"||arg1=="items")
	{
		arg1transl="items";
	}
	
	if (arg1=="get"||arg1=="grab"||arg1=="pickup"||arg1=="take")
	{
		arg1transl="get";
		cin >> arg2;
		//cout << "Getting ";
	}
	
	if (arg1=="pick")												//"PICK UP" Clause.
	{
		cin >> arg2;
		if(arg2=="up")
		{
			cin >> arg3;
			arg1transl = "get";
			arg2 = arg3;
		}
	}
	
	if (arg1=="drop"||arg1=="leave"||arg1=="discard")
	{
		arg1transl="drop";
		cin >> arg2;
		//cout << "Dropping ";
	}
	
	if (arg1=="examine")
	{	
		arg1transl="examine";
		cin >> arg2;
	}
	if (arg1=="look")												//"LOOK AT" Clause.
	{
		cin >> arg2;
		if(arg2=="at")
		{
			cin >> arg3;
			arg1transl = "examine";
			arg2 = arg3;
		}
	}
	/*
	if(arg1=="use"||arg1=="combine")
	{
		arg1transl="use";
		use();
	}
	*/
	if (arg1 == "help")
	{
		helpscreen();
		cin.ignore();
		//cout << "Break the freaking pendant." << endl;
	}
	//cout << endl << "arg1transl is currently " << arg1transl << endl;
	if (arg2=="reset"||arg1=="reset"||arg3=="reset")
	decision();
	
	system("cls");
	cout << "\n";
	
	processing();
}

void decision()
{
	for (int i=0; i<1; i++)
	{
		arg1.clear();
		arg2.clear();
		cout << endl << "What do you want to do?\n";
		cin >> arg1;
		if(arg1=="with")
		{
			cin>>arg1;
			cin>>arg1;
		}
		//if (arg1.length()!=0 && arg2.length()==0)
		//	continue;
		if(arg1=="reset"||arg2=="reset")
		continue;
	}
	decipher();
}
//=========================================================================================================================================================
//																			LOCATIONS

void startingarea()
{										//This is location 1
	cout << endl;
	
	switch(decrepit)
	{
	case 1:
		cout << "You're in a crumbling alley. You can tell it's in ruin because \nthe bricks from the buildings on either side have started falling to the ground." << endl;
		cout << "You can see pieces of something marked on some of the bricks, \nbut it's impossible to tell what.\n";
		cout << "Dim twilight to the East marks the only way out of the alley.\n";
		break;
	case 0:
		cout << "You're standing in an alley. Besides the trash cans, \nyou can see a fire escape climbing the building to the south." << endl;
		cout << "There is not even any graffiti on the immaculate brick walls.\n";
		cout << "The alley lets out into the street to the east.";
	}
	whatshere();
	decision();
	
	if (arg1transl=="go")
	{
		if (arg2=="east")
		transition(2);
		//if(arg2=="east" && sword==0)
		//cout << "It's dangerous to go alone. Why not take something?" << endl;
	}
}

void citystreet()
{										//This is location 2
	cout << endl;
	switch(decrepit)
	{
	case 1:
		cout << "You're standing in the middle of a city street. What was once a bustling \ncity block now lies quiet and still. " << endl;
		cout << "Looking around, you see the crumbling remains of a once great city. \nFew buildings remain upright, and none remain intact.\n";
		cout << "You can see an alley to the west, and the street leads north out of the city \nand continues south towards the square." << endl;
		break;
	case 0:
		cout <<"You're in the middle of a city street. Enormous structures rise around you, \neach with its own colors and designs.\n";
		cout <<"Strangely, you don't see a single person around.\n";
		cout <<"The street continues south towards the square.\n";
	}
	
	whatshere();
	decision();
	
	if (arg1transl=="go")
	{
		if (arg2=="west")
		transition(1);
		else if (arg2=="south")
		transition(3);
		else if (arg2=="north")
		transition(4);
	}
	
}

void citysquare()
{										//This is location 3
	cout << endl;
	switch (decrepit)
	{
	case 1:
		cout << "The broken road led you to an enormous city square. \nThe pavement here is twisted and bent. You can tell that this was a colorful\nplace, but the only color now is the dusky purple of the twilight.\n";
		cout << "You're surrounded on all sides by the twisted wreckage of the city.\n";
		break;
	case 0:
		cout << "The road led to the city square. You can see the same giant buildings and \nstructures, but they're all perfectly intact. Signs and street lights \ncast a colorful glow against the fresh ";
		cout << "blacktop. \nNo wreckage blocks your way anymore, and you see two more streets branching off; one to the east, and one to the west.\n";
		break;
	}
	whatshere();
	decision();
	
	if (arg1transl=="go")
	{
		if (arg2=="north")
		transition(2);
	}
}

void coastline()
{										//This is location 4
	cout << endl;
	switch (decrepit)
	{
	case 1:
		cout << "You're standing just north of the city. Looking back, you can see \njust what level of disrepair the city has fallen into." << endl;
		cout << "You can only compare it to a fallen titan. This city truly must \nhave been beautiful before it fell.\n";
		if(pricked==0)
		{
			cout << endl << "You prick your finger on a rusted bench sitting here. \nA drop of blood lands on the bench.\n";
			pricked=1;
			cout << endl << "You can see the drop of blood on the bench.\n";
		}
		break;
	case 0:
		cout << "Looking north back at the city, you're struck by awe. In this state, the city truly IS beautiful.";
		cout << "The sunset casts an orange hue over the numerous colors of the city";
		cout << " and the coast reflects the combined colors in the waves.\n";
		if (pricked==1)
		cout << endl << "Strangely.. You can still see the drop of blood on the bench.\n";
		break;
	}
	whatshere();
	decision();
	
	if (arg1transl=="go")
	{
		if (arg2=="south")
		transition(2);
	}
}

int main()
{
	//helpscreen();
	system("cls");
	do
	{	
		if(decrepit==1)
		system("Color 07");
		if(decrepit==0)
		system("Color F0");
		cout << "\n======================================================================\n";
		
		switch (location)
		{
		case 1:
			startingarea();
			break;
		case 2:
			citystreet();
			break;
		case 3:
			citysquare();
			break;
		case 4:
			coastline();
			break;
		}
	}
	while(true);
}