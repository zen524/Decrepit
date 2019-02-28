#include <iostream>
using namespace std;

void location(int loc, bool isWhite)
{
	switch (location)
	{
	case 1:
		cout << endl;
		
		switch(loc)
		{
		case 0:
			cout << "You're in a crumbling alley. You can tell it's in ruin because \nthe bricks from the buildings on either side have started falling to the ground." << endl;
			cout << "You can see pieces of something marked on some of the bricks, \nbut it's impossible to tell what.\n";
			cout << "Dim twilight to the East marks the only way out of the alley.\n";
			break;
		case 1:
			cout << "You're standing in an alley. Besides the trash cans, \nyou can see a fire escape climbing the building to the south." << endl;
			cout << "There is not even any graffiti on the immaculate brick walls.\n";
			cout << "The alley lets out into the street to the east.";
		}
		
		if (arg1transl=="go")
		{
			if (arg2=="east")
			transition(2);
			//if(arg2=="east" && sword==0)
			//cout << "It's dangerous to go alone. Why not take something?" << endl;
		}
		break;
	case 2:
		{										//This is location 2
			cout << endl;
			switch(isWhite)
			{
			case 0:
				cout << "You're standing in the middle of a city street. What was once a bustling \ncity block now lies quiet and still. " << endl;
				cout << "Looking around, you see the crumbling remains of a once great city. \nFew buildings remain upright, and none remain intact.\n";
				cout << "You can see an alley to the west, and the street leads north out of the city \nand continues south towards the square." << endl;
				break;
			case 1:
				cout <<"You're in the middle of a city street. Enormous structures rise around you, \neach with its own colors and designs.\n";
				cout <<"Strangely, you don't see a single person around.\n";
				cout <<"The street continues south towards the square.\n";
			}
			
			
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
		break;
	case 3:
		{										//This is location 3
			cout << endl;
			switch (isWhite)
			{
			case 0:
				cout << "The broken road led you to an enormous city square. \nThe pavement here is twisted and bent. You can tell that this was a colorful\nplace, but the only color now is the dusky purple of the twilight.\n";
				cout << "You're surrounded on all sides by the twisted wreckage of the city.\n";
				break;
			case 1:
				cout << "The road led to the city square. You can see the same giant buildings and \nstructures, but they're all perfectly intact. Signs and street lights \ncast a colorful glow against the fresh ";
				cout << "blacktop. \nNo wreckage blocks your way anymore, and you see two more streets branching off; one to the east, and one to the west.\n";
				break;
			}
			
			
			if (arg1transl=="go")
			{
				if (arg2=="north")
				transition(2);
			}
		}
	case 4:
		{										//This is location 4
			cout << endl;
			switch (isWhite)
			{
			case 0:
				cout << "You're standing just north of the city. Looking back, you can see \njust what level of disrepair the city has fallen into." << endl;
				cout << "You can only compare it to a fallen titan. This city truly must \nhave been beautiful before it fell.\n";
				if(pricked==0)
				{
					cout << endl << "You prick your finger on a rusted bench sitting here. \nA drop of blood lands on the bench.\n";
					pricked=1;
					cout << endl << "You can see the drop of blood on the bench.\n";
				}
				break;
			case 1:
				cout << "Looking north back at the city, you're struck by awe. In this state, the city truly IS beautiful.";
				cout << "The sunset casts an orange hue over the numerous colors of the city";
				cout << " and the coast reflects the combined colors in the waves.\n";
				if (pricked==1)
				cout << endl << "Strangely.. You can still see the drop of blood on the bench.\n";
				break;
			}
			
			
			if (arg1transl=="go")
			{
				if (arg2=="south")
				transition(2);
			}
		}
	}//End switch case
	
	whatshere();
	decision();
	
}
//=========================================================================================================================================================
//																			LOCATIONS