#pragma once
namespace CMSEC
{
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

		String name = "None";
		String details = "No Details";
	};
}