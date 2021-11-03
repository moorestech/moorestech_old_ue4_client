#include "endian.h"

bool endian::IS_LITTLE_ENDIAN()
{
	int x=1; // 0x00000001
	if (*(char*)&x) {
		/* little endian. memory image 01 00 00 00 */
		return true;
	}else{
		/* big endian. memory image 00 00 00 01 */
		return false;
	}
}

