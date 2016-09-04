#pragma once

class LightInformation
{
public:
	LightInformation() {};
	LightInformation(String _name)
	{
		name = _name;
	};
	LightInformation(String _name, String _details)
	{
		name = _name;
		details = _details;
	};
	~LightInformation() {};

	String name;
	String details;
};