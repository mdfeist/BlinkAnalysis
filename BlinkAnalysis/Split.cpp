#include "StdAfx.h"
#include "Split.h"

void Split::reset ( const std::string& src, const std::string& delim, bool noReturn) {
	std::vector<std::string> tokens;
	std::string::size_type start = 0;
	std::string::size_type end;

	for ( ; ; ) {
		end = src.find ( delim, start );
		tokens.push_back ( src.substr ( start, end - start ) );
		// We just copied the last token
		if ( end == std::string::npos )
			break;

		// Exclude the delimiter in the next search
		start = end + delim.size();
	}

	// Remove return at end
	if (noReturn)
	{
		std::string last = tokens.back();
		end = last.find("\n");
		tokens.pop_back();

		tokens.push_back ( last.substr ( 0, end ) );
	}

	_tokens.swap ( tokens );
}
