#pragma once

class CTracer
{
public:
	static void Trace(LPCTSTR pFormat, ...);
};

#ifdef DEBUG 
#define TRACER CTracer::Trace
#else
#define TRACER 
#endif
