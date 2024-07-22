/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexiQuest.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:20:45 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/07/22 16:47:10 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXIQUEST_H
# define LEXIQUEST_H

# include <stdio.h>
# include <iostream>
# include <string>
# include <cmath>
# include <cstdlib>
# include <ctime>
# include <fstream>
# include <set>
# include <vector>
using namespace std;

#endif
class	Dictionary
{
public:
	Dictionary()
	{
		ifstream input ("/usr/share/dict/words");
		for (string line; getline(input, line);)
		{
			_words.insert(line);
		}
		srand(static_cast<unsigned>(time(0)));
	}

	bool	contains(string const& word) const
	{
		return (_words.count(word) > 0);
	}

	string getRandomWord(int length) const
	{
		vector<string> validWords;
		for (const auto& word : _words)
		{
			if (word.length() == length)
			{
				validWords.push_back(word);
			}
		}
		if (validWords.empty())
		{
			return "";
		}
		int	index = rand() % validWords.size();
		return validWords[index];
	}

private:
	set<string> _words;
};