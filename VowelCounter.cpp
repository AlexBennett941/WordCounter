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
    //char letter will be used to search through txt file and if its vowel increment
    //mass changed vowel to letter because we are no longer just looking for vowels
    char letter;
    //will be incremented as letter is == to these letters
    int a = 0, 
        e = 0,  
        i = 0,
        o = 0,
        u = 0,
        v = 0,
        j = 0,
        t = 0,
        others = 0;
    //if the file is open
    if (inFile.is_open())
    {
        //while the file is open this command will retrieve a letter and store it in letter
        while(inFile.get(letter)){
        //need decision structure to determine which letter the variable holds and incrementing that
        //realized before that, have to lowercase the character in letter or it will not count capitalized characters
            letter = tolower(letter);
        
            if(letter == 'a')
                a++; //increment
            else if(letter=='e')
                e++;
            else if (letter == 'i')
                i++;
            else if (letter == 'o')
                o++;
            else if(letter == 'u')
                u++;
            else if(letter == 'v')
                v++;
            else if(letter == 'j')
                j++;
            else if(letter == 't')
                t++;
            else{
                others++;
            }
        }
    }
    //creating string to make outputs of each letter bit easier
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
    //amt of v's
    std::cout << s1 << "V's: " << std::setw(42) << '.' << v << std::endl;
    //amt of j's
    std::cout << s1 << "J's: " << std::setw(42) << '.' << j << std::endl;
    //amt of t's
    std::cout << s1 << "T's: " << std::setw(42) << '.' << t << std::endl;
    //Outputting total amount of vowels going to add in cout line
    std::cout << "The vowel count is: " << std::setw(41) << '.' << a + e + i + o + u << std::endl;
    //amount of new letters to count for 
    std::cout << "The amount of V's, J's, and T's is: " << std::setw(25) << '.' << j + t + v << std::endl;
    //Total of letters that were looked at
    std::cout << "The amount of specified characters is: " << std::setw(22) << '.' << a+e+i+o+u+j+t+v << std::endl;
    //total number of unspecified consonants
    std::cout << "The amount of unspecified cosonants is: " << std::setw(21) << '.' << others << std::endl;
    //system("PAUSE"); I run this in linux and I cannot get this command to work if you could add a comment in the grading I would appreciate that
	inFile.close();

	return 0;
}