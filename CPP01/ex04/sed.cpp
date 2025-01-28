/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:01:22 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:01:23 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

static std::string &read_file_to_buffer(std::string &filename, std::string &buffer)
{
	// Opening file
	std::ifstream inFile(filename.c_str());
	if (!inFile)
    {
        std::cerr << "Error opening file" << std::endl;
        exit (1);
    }

	// Sack memory for correct content copy if s1 spans across two lines
    {
        std::string line;
	    while (std::getline(inFile, line))
		{
	        buffer += line;

	        if (!inFile.eof())
	            buffer += "\n";
	    }
    }
    inFile.close();
	// Nothing to sed
    if (buffer.empty()) exit(0);
	else return buffer;
}

// std::string::npos is kinda like an error return to some functions
// look for s1 in content, erase it and insert at that position s2 (same as replace xd) and update the index
static std::string &find_and_replace(std::string &buffer, std::string &find, std::string &replace)
{
    if(find.empty()) return buffer;

    size_t i = 0;
    while((i = buffer.find(find, i)) != std::string::npos)
    {
        buffer.erase(i, find.length());
        buffer.insert(i, replace);
        i+= replace.length();
    }
	return buffer;
}

static void write_to_file(const char *newFilename, std::string &buffer)
{
   std::ofstream outFile(newFilename);
    if (!outFile)
    {
        std::cerr << "Error opening file" << std::endl;
        exit (1);
    }
	// Write to the new file
    outFile << buffer;
    outFile.close();
	return ;
}

void sed(char **av)
{
    std::string filename = av[1], s1 = av[2], s2 = av[3], content;

	read_file_to_buffer(filename, content);
	find_and_replace(content, s1, s2);
	write_to_file((filename + ".replace").c_str(), content);
}
