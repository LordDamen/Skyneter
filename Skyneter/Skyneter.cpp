// Skyneter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//needed for random numbers
#include <ctime>
using namespace std;

void main()
{
	// int the 
	srand(time(0));
	//inital varables
	int gridhigh = 64;
	int gridlow = 1;
	//the goal that is needed
	int EnemyLoc = rand() % gridhigh + gridlow;
	int tries = 0;
	//the varable that starts and ends the loop
	bool targetfound = false;
	//story for flavor
	cout << "The system is starting up..."<< endl;
	cout << "The system is fully active... starting now"<< endl;
	cout << "......................." << endl;
		while (targetfound == false)
	{
		int prediciton = ((gridhigh - gridlow) / 2) + gridlow;
		tries++;
		
		if (prediciton > EnemyLoc)
		{
			// changing upper bounds
			gridhigh = prediciton - 1;
			//story for flavor
			cout << prediciton << " was too high changing upper bounds" << endl;
			cout << "Restarting search program" << endl; 
			cout <<".... Please wait...." << endl;
		}
		else if (prediciton < EnemyLoc)
		{
			//changing lower bounds
			gridlow = prediciton + 1;
			//story for flavor
			cout << prediciton << " was too low changing lower bounds" << endl;
			cout << "Restarting search program" << endl;
			cout << ".... Please wait...." << endl;
		}
		else if (prediciton == EnemyLoc)
		{
			//breaking out of the loop
			targetfound = true;
			//story for flavor
			cout << prediciton << " was correct eliminating target" << endl;
			cout << ".... ending search....." << endl;
			cout << "Flushing " << tries << " attempts from memory" << endl;
			cout << "...System ending cycle..." << endl;
			cout << "Have a Nice day " << endl;
		}
	}
		//stoping the system to get the console text
	system("pause");
}

