#pragma once
#include <string>
#include <vector>

// Class to split a string based on a given delimiter
class Split
{
	std::vector<std::string> _tokens;
public:
	// Subscript type for use with operator[]
	typedef std::vector<std::string>::size_type size_type;

	// Splits a string based on a given delimiter.
	// If True the noReturn will make sure that the 
	// last line does not have a return.
	Split(const std::string& src, const std::string& delim, bool noReturn = false)
	{
		reset(src, delim, noReturn);
	}

	// Get token at
	std::string& operator[] ( size_type i )
	{
		return _tokens.at ( i );
	}

	// Gets the number of tokens
	size_type size() const
	{
	  return _tokens.size();
	}

	// Resets the Split and clears all previous tokens
	void reset ( const std::string& src, const std::string& delim, bool noReturn = false);
};

