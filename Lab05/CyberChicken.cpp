#include "CyberChicken.h"

using namespace std;

CyberChicken:: CyberChicken()
{
	m_name = "CyberChicken";
	m_sound = "Resistance is futile";
	
}

int CyberChicken:: getCyberEggs() const
{
	return m_eggs;
}

void CyberChicken:: setCyberEggs(int eggs)
{
	m_eggs = eggs;
}
