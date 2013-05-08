#pragma once
#include <string>
#include <vector>

class Split
{
	std::vector<std::string> _tokens;
public:
	// Subscript type for use with operator[]
	typedef std::vector<std::string>::size_type size_type;

	Split(const std::string& src, const std::string& delim, bool noReturn = false)
	{
		reset(src, delim, noReturn);
	}

	std::string& operator[] ( size_type i )
	{
		return _tokens.at ( i );
	}

	size_type size() const
	{
	  return _tokens.size();
	}

	void reset ( const std::string& src, const std::string& delim, bool noReturn = false);
};

