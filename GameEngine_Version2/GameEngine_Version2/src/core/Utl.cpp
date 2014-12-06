#include "Utl.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

const string Utl::TRACE{ "TRACE" };
const string Utl::WARNING{ "WARNING" };
double Utl::m_deltaTime;

auto Utl::SendTrace(const string& errorType,
					const string& message,
				    const string& className,
				    const string& methodName) -> void
{
	cout << errorType << ": " << message
		<< " [" << className << ":"
		<< methodName << "]" << endl;
}