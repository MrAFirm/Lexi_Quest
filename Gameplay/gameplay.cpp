/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:42:56 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/07/22 22:08:17 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LexiQuest.h"

class LexiQuest
{
public:
	void Continue()
	{
		cout << "Do you wish to continue? (Y/N)" << endl;
		cin >> choice_continue;
		if (choice_continue == "N")
		{
				cout << "Have a Great Day!" << endl;
				gameLoop = false;
		}
		else if (choice_continue == "Y")
		{
			gameLoop = true;
		}
		else
		{
		cout << "Invalid Input, please retype." << endl;
		Continue();
		}
	}
	// Constructor that accepts a Dictionary object
	LexiQuest(const Dictionary& dict) : dictionary(dict), wordLength(5), secretWord(dictionary.getRandomWord(wordLength)) {}
	
	LexiQuest() :  dictionary(), wordLength(5), secretWord(dictionary.getRandomWord(wordLength)) {}

	void startGame()
	{
		cout << "Welcome to Lexi Quest!" << endl;
		string menu = "1. Start Guessing!\n2. Exit\n";
		cout << menu;
		cin >> choice;
		while (gameLoop)
		{
			switch (choice)
			{
				case 1:
					cout << "Let's Begin!" << endl;
					for (int i = 0; i < maxAttempts; i++)
					{
						cout << "Attempt " << (i + 1) << " of " << maxAttempts << ": ";
						string guess;
						cin >> guess;

					 	if (guess.length() != wordLength)
					 	{
							cout << "Invalid guess length. Please anter a " << wordLength << "-letter word." << endl;
							--i;
							continue;
						}
					 	if (!dictionary.contains(guess))
					 	{
							cout << "Word not in dictionary. Try Again." << endl;
							--i;
							continue;
					 	}
					 	cout << "Your Guess: " << guess << endl;
					 	if (guess == secretWord)
					 	{
							cout << "Congratulations! You've Guessed the right word: " << secretWord << endl;
							break;
							cout << "Game Over! The correct word was: " << secretWord << endl;
							break;
					 	}
					}
				case 2:
					cout << "Have a Great Day!" << endl;
					gameLoop = false;
					break;
			}
			if (choice == 1)
				Continue();
		}
	}
private:
	Dictionary	dictionary;
	int			wordLength;
	int			choice;
	bool 		gameLoop = true;
	int			maxAttempts = 6;
	string 		secretWord;
	string		choice_continue;
};

int main(void)
{
	LexiQuest game;
	game.startGame();
	game.Continue();
	return (0);
}
