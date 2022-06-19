// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
int main(int argc, char* argv[])
{      
	// The executable name and at least one argument?
	if (argc < 2)
	{
		std::cout << "Error with input agrs.." << std::endl;
		return 1;
	}

	// For debugging purposes only
	for (int i = 0; i < argc; i++)
	{
		std::cout << i << ":" << argv[i] << std::endl;
	}

	std::ifstream inFile;
	inFile.open(argv[1]);
	if (!inFile)
	{
		std::cout << "Error with file name.." << std::endl;
		return 1;
	}
    
	///////////////////////
	// Work here with open file.....
	///////////////////////
    
    //intro statement
    std::cout << std::setfill('*') << std::setw(60) << '*'<< std::endl;
    std::cout << std::setw(12) << '*' << " Welcome to my Letter Count Program " << std::setw(12) << '*' << std::endl;
    std::cout << std::setw(60) << '*' << std::endl << std::endl;
    std::cout << "Analyzing file 'Constitution_of_the_United_States.html'..." << std::endl << std::endl;

    //initializing neccessary variables
    //char vowel will be used to search through txt file and if its vowel increment
    char vowel;
    //will be incremented as vowel is == to these letters
    int a = 0, 
        e = 0,  
        i = 0,
        o = 0,
        u = 0;
    //if the file is open
    if (inFile.is_open())
    {
        //while the file is open this command will retrieve a letter and store it in vowel
        while(inFile.get(vowel)){
        //need decision structure to determine which vowel the variable holds and incrementing that
        //realized before that, have to lowercase the character in vowel or it will not count capitalized characters
            vowel = tolower(vowel);
        
            if(vowel == 'a')
                a++; //increment
            else if(vowel=='e')
                e++;
            else if (vowel == 'i')
                i++;
            else if (vowel == 'o')
                o++;
            else if(vowel == 'u')
                u++;
        }
    }
    //creating string to make outputs of each vowel bit easier
    std::string s1 = "The Number of ";
    //amount of A's
    std::cout << s1 << "A's: " << std::setfill('.') << std::setw(42) << '.' << a << std::endl;
    //Amount of e's
    std::cout << s1 << "E's: " << std::setw(42) << '.' << e << std::endl;
    //Amount of i's
    std::cout << s1 << "I's: " << std::setw(42) << '.' << i << std::endl;
    //Amt of o's
    std::cout << s1 << "O's: " << std::setw(42) << '.' << o << std::endl;
    //Amt of u's
    std::cout << s1 << "U's: " << std::setw(42) << '.' << u << std::endl;
    //Outputting total amount of vowels going to add in cout line
    std::cout << "The vowel count is: " << std::setw(41) << '.' << a + e + i + o + u;
    //system("PAUSE"); I run this in linux and I cannot get this command to work if you could add a comment in the grading I would appreciate that
	inFile.close();

	return 0;
}