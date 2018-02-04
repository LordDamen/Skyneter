// Skyneter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//needed for random numbers
#include <ctime>
using namespace std;

void main()
{

	while (true)
	{
		// int the 
		srand(time(0));

		//inital varables
		int gridhigh = 64;
		int gridlow = 1;
		bool targetfound = false;
		int EnemyLoc = rand() % gridhigh + gridlow;
		int A1BianaryTries = 0;
		int prediction;
		int AiLinearTries = 0;
		int LinearPre;
		int AiRandomTries = 0;
		int RandomPre;
		int HumanTries = 0;
		int PlayerPre;
		int turns = 0;
		while (!targetfound) {
		

			switch (turns) {
				//The Bianary case
			case 0:
				 prediction = ((gridhigh - gridlow) / 2) + gridlow;

				A1BianaryTries++;

				if (prediction > EnemyLoc)
				{
					// changing upper bounds
					cout << "bianary upper limit" << endl;
					gridhigh = prediction - 1;
					//story for flavor
					/*
					cout << prediciton << " was too high changing upper bounds" << endl;
					cout << "Restarting search program" << endl;
					cout <<".... Please wait...." << endl;
					*/
				}
				else if (prediction < EnemyLoc)
				{
					cout << "bianary lower limit" << endl;
					//changing lower bounds
					gridlow = prediction + 1;

					//story for flavor
					/*
					cout << prediciton << " was too low changing lower bounds" << endl;
					cout << "Restarting search program" << endl;
					cout << ".... Please wait...." << endl;
					*/
				}
				else if (prediction == EnemyLoc)
				{
					//breaking out of the loop
					cout << "bianary Win" << endl;
					targetfound = true;
					//story for flavor
					/*
					cout << prediciton << " was correct eliminating target" << endl;
					cout << ".... ending search....." << endl;
					cout << "Flushing " << tries << " attempts from memory" << endl;
					cout << "...System ending cycle..." << endl;
					cout << "Have a Nice day " << endl;
					*/

				}
				break;
				// The random case
			case 1:
				 RandomPre = rand() % 64 + 1;
				if (RandomPre == EnemyLoc)
				{
					cout << "random found it" << endl;
					targetfound = true;

				}
				else if (RandomPre != EnemyLoc)
				{
					cout << "Random Fails to find it " << endl;
					AiRandomTries++;
				}
				break;
				// The linear case
			case 2:
				 LinearPre = 0;
				LinearPre++;
				AiLinearTries++;
				if (LinearPre == EnemyLoc)
				{
					cout << "Linear Win" << endl;
					targetfound = true;
				}
				else {
					cout << "linear fail" << endl;
				}
				break;
				//the human case
			case 3:
				HumanTries++;
				cout << "It is your turn Make a guess" << endl;
				cin >> PlayerPre;
				if (PlayerPre > EnemyLoc) {
					cout << "Your attempt was too high" << endl;
				}
				else if (PlayerPre < EnemyLoc) {
					cout << "Your attempt was too low" << endl;
				}
				else {
					cout << "You have Won Good Job" << endl;
				}
				break;



			}
			// reseting the turns
			turns++;
			if (turns > 3)
			{
				turns = 0;
			}

		}
		/*
		cout << "The system is starting up..."<< endl;
		cout << "The system is fully active... starting now"<< endl;
		cout << "......................." << endl;
		*/

		//stoping the system to get the console text
		system("pause");
		// ending message
		cout << "it Took Biniary " << A1BianaryTries << " Attempts to find it " << endl;
		cout << "it Took Linear " << AiLinearTries << " Attempts to find it " << endl;
		cout << "it Took Random " << AiRandomTries << " Attempts to find it " << endl;
		cout << "it Took You " << HumanTries << " Attempts to find it " << endl;

	}
}

