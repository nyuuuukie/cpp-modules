/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:49:58 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/15 02:41:31 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>

typedef std::string string;

#define RED "\033[31m"
#define DEF "\033[0m"
#define WHITE "\033[37m"

enum code
{
	DEFAULT = -3,
	BAD_ARGUMENTS = -2,
	READ_FILE_ERROR = -1,
	REPLACE_SUCCESS = 0,
	READ_SUCCESS = 1,
	WRITE_SUCCESS = 2,
	STRING_NOT_FOUND = 3
};

class Replacer
{
	public:
		//Construnctor and Destructor
		Replacer(void);
		~Replacer(void);
		Replacer(string filename, string toReplace, string replace);
		
		void	makeReplace(void);
	
		//Getters and setters
		code	getCode(void);
		void	whatReplace(string text);
		void	whatReplaceWith(string text);	
		void 	setExtension(string ext);
		void	setInputFilename(string filename);
		void	setOutputFilename(string filename);
		void	printLine(const string &text);
		void	printColorLine(const string &text, const string color);
	
	private:
		string	toUpperCase(string src);
		void	writeToFile(string text);
		string 	readFromFile(void);
		
		code	_code;
		string	_replacer;
		string	_toReplace;
		string	_extension;
		string	_inputFilename;
		string	_outputFilename;
};
