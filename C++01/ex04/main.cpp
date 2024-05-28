/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:30:03 by atok              #+#    #+#             */
/*   Updated: 2023/08/18 18:36:27 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string> // std::string
#include <fstream> // input/output file stream
#include <iostream> // for cout cin

void find_replace_tonewfile(std::string filename, std::string s1, std::string s2)
{
	std::ifstream file(filename.c_str());
	if(file.is_open() == false)
	{
		std::cout << "cannot open file try chmod 777 \n";
		return;
	} 

	std::string tmp;
	std::string line;

	while(std::getline(file, line))
	{
		size_t pointer_to_s1_1st_char;
		while ((pointer_to_s1_1st_char = line.find(s1)) != std::string::npos) // similar while is not NULL but for string
		{																	// no position aka max size_t value
			// std::string erase(pointer_to_s1_1st_char,s1.length()); //mistake
			line.erase(pointer_to_s1_1st_char,s1.length());
			line.insert(pointer_to_s1_1st_char,s2);
		}
		tmp += line + "\n";
	}

	// std::cout << tmp << "\n";
	// return;
	file.close();
	
	std::ofstream newfile((filename + ".newfile").c_str());
	if(!newfile.is_open())
	{
		std::cout << "cannot open file try chmod 777 \n";
		return;
	}
	newfile << tmp;
	newfile.close();
}

int main ()
{
	std::string filename, s1, s2;

	std::cout << "File name \n";
	std::getline(std::cin, filename);

	std::cout << "Word to find \n";
	std::getline(std::cin, s1);

	std::cout << "Word to replce \n";
	std::getline(std::cin, s2);

	find_replace_tonewfile(filename,s1,s2);
	std::cout << "Jobs Done! \n";
}

//file name >> file
//a new file will pop up appending filename + ".newfile"
// if the file is already there it might not be able to access
// so do chmod 777 file.newfile