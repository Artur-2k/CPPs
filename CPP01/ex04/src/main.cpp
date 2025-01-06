#include <iostream>
#include <string>
#include <fstream>


using std::cout;
using std::string;
using std::endl;

int main(int ac, char *av[])
{
    if (ac != 4)
    {
        cout << "./Sed_is_for_losers filename string1 string2" << endl;
        exit(1);
    }

    string filename = av[1], s1 = av[2], s2 = av[3];

    std::ifstream inFile(filename.c_str());
    if (!inFile)
    {
        cout << "Error opening file" << endl;
        exit (1);
    }

    string content;
    {
        string line;
        bool firstLine = true;

        while (true)
        {
            std::getline(inFile, line);
            if (inFile.eof())
                break ;
            if (!firstLine)
                content += "\n";
            firstLine = false;
            content += line;
        }
    }
    inFile.close(); 
    if (content.empty())
        exit(0);

    // std::string::npos is kinda like an error return to some functions
    // look for s1 in content, erase it and insert at that position s2 (same as replace xd) and update the index
    {
        size_t i = 0;
        while((i = content.find(s1, i)) != std::string::npos)
        {
            content.erase(i, s1.length());
            content.insert(i, s2);
            i+= s2.length();
        }
    }

    std::ofstream outFile(filename + ".replace");
    if (!outFile)
    {
        cout << "Error opening the output file" << endl;
        exit (1);
    }

    outFile << content;
    outFile.close();

    cout << "GeT SeDed XDDD" << endl;   
    return 0;
}