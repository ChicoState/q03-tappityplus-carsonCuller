#include <cmath>
#include "tappity.h"
/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(std::string reference)
{
    m_reference = reference;
	m_input = "";
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
    m_input = input;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
    m_diff = m_reference.length() - m_input.length();
    m_diff = abs(m_diff);
    return (m_diff);
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
	std::string shortest;
	std::string longest;
	int correctCount = 0;
	double percentile;
	double percentage;

	m_diff = length_difference();

	if (m_diff == 0){
		//arbitrary variable assigning
		shortest = m_reference;
		longest = m_input;
	}

	else if (m_reference.length() > m_input.length()){
		shortest = m_input;
		longest = m_reference;
	}
	else {
		shortest = m_reference;
		longest = m_input;
	}

	// both strings are empty (the same)
	if (longest.length() == 0){
		return 100;
	}

	for (int i = 0; i < shortest.length(); i++){
		if (shortest[i] == longest[i]){
			correctCount++;
		}
	}
	percentile = (double)correctCount/(double)longest.length();
	percentage = percentile*100.00;
	percentage = round(percentage);
	return percentage;
}
