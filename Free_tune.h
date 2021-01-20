// this is the fre etune header file
#include "import.h"
#include "Vmain.h"
class Free_tune
{
private:

public:
	// the HZ to check with
	int HZ;
	// the light panel so the class can change it
	Light_screen* Lights;

	// functions
	void AudioCheck();

	static void noteout(float HZ);

};

