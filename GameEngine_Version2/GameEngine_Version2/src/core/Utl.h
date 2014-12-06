#ifndef CORE_UTL_H
#define CORE_UTL_H

#include <string>

static const bool	 WINDOW_RESIZABLE { false };
static const bool	 FULLSCREEN { false };
static const bool	 IGNORE_FRAME_CAP{ true };
static const int	 SAMPLES { 4 };
static const double  FRAME_CAP{ 60 };

class Utl
{
public:
	static auto SendTrace(const std::string& errorType,
						  const std::string& message,
				          const std::string& className,
						  const std::string& methodName) -> void;

	static auto SetDeltaTime(double value)  -> void { m_deltaTime = value; }
	static auto GetDeltaTime()				-> double { return m_deltaTime; }

	static const  std::string TRACE;
	static const  std::string WARNING;
	static double m_deltaTime;
};



#endif