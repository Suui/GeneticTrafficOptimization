#include "Road.h"
#include "TrafficLight.h"
#include "../Exceptions/NotImplementedException.h"


Road::Road()
{

}


Road Road::build()
{
	return *this;
}


Road Road::From(int x, int y)
{
	throw NotImplementedException();
}


Road Road::To(int x, int y)
{
	throw NotImplementedException();
}


Road Road::WithFirstTrafficLightIn(int x, int y)
{
	throw NotImplementedException();
}


Road Road::WithSecondTrafficLight(int x, int y)
{
	throw NotImplementedException();
}


int Road::Length()
{
	throw NotImplementedException();
}


TrafficLight Road::GetFirstTrafficLight()
{
	throw NotImplementedException();
}