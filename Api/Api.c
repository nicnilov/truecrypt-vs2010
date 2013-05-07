// Api.c : Defines the exported functions for the DLL application.
//

#include "Tcdefs.h"

#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <errno.h>
#include <io.h>
#include <sys/stat.h>
#include <shlobj.h>

//#include <math.h>
//#include <dbt.h>
//#include <fcntl.h>

#include "Crypto.h"
#include "Apidrvr.h"
#include "Dlgcode.h"
#include "Language.h"
#include "Combo.h"
#include "Registry.h"
#include "Boot/Windows/BootDefs.h"
#include "Common/Common.h"
#include "Common/BootEncryption.h"
#include "Common/Dictionary.h"
#include "Common/Endian.h"
#include "Common/Resource.h"
#include "Platform/Finally.h"
#include "Platform/ForEach.h"
#include "Random.h"
#include "resource.h"
#include "Api.h"
#include "Password.h"
#include "Tests.h"
#include "Cmdline.h"
#include "Volumes.h"
#include "Wipe.h"
#include "Xml.h"

using namespace TrueCrypt;

DLLEXPORT int APIENTRY LoadTrueCryptDriver()
{
	int status = DriverAttach();
	return status;
}
