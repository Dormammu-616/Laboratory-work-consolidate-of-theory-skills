#include "lab 1 - Architectural pattern Taxonomy/Architectural pattern Taxonomy.h"
#include "lab 2 - Safe state injection/Safe state injection.h"
#include "lab 3 - Interface separation principle/SmartCityTelemetry.h"

int main()
{
	// lab #1
	Taxonomy tax{};
	tax.run_lab();
	
	// lab #2
	State_Injection injection{};
	injection.run_lab();

	// lab #3
	Smart_City_Telemetry telemetry{};
	telemetry.run_lab();

	return 0;
}