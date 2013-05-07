// ApiTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

typedef int (STDMETHODCALLTYPE *LTCD)();

class ApiTest {
private:
	HMODULE hApiDll;
	LTCD LoadTrueCryptDriver;
protected:
	BOOL LoadTrueCryptApi(LPCTSTR path) {
		wcout << "Loading TrueCrypt API dll from " << path << " \n";
		hApiDll = LoadLibrary(path);
		if (!hApiDll) {
			cout << "Error loading TrueCrypt API dll: " << GetLastError() << "\n";
		} else {
			cout << "Loaded\n";
		}
		return (BOOL) hApiDll;
	}

	BOOL UnloadTrueCryptApi() {
		cout << "Unloading TrueCrypt API dll \n";
		if (!hApiDll) {
			cout << "TrueCryptApi dll has not been initialized\n";
			return FALSE;
		}

		if (FreeLibrary(hApiDll)) {
			hApiDll = NULL;
			cout << "Unloaded\n";
			return TRUE;
		} else {
			cout << "Error unloading TrueCrypt API dll: " << GetLastError() << "\n";
			return FALSE;
		}
	}

	BOOL GetApiAddresses() {
		cout << "Getting API addresses\n";
		if (!hApiDll) {
			cout << "TrueCryptApi dll has not been initialized\n";
			return FALSE;
		}

		LoadTrueCryptDriver = (LTCD) GetProcAddress(hApiDll, "LoadTrueCryptDriver");
		if (!LoadTrueCryptDriver) {
			cout << "Error getting address of LoadTrueCryptDriver: " << GetLastError() << "\n";
			return FALSE;
		} else {
			cout << "LoadTrueCryptDriver is loaded at: " << LoadTrueCryptDriver << "\n";
		}
		return TRUE;
	}

public:
	void run() {
		if (!LoadTrueCryptApi(L"TrueCryptApi.dll")) return;
		if (GetApiAddresses()) {
			cout << "Loading TrueCrypt Driver\n";
			int res = LoadTrueCryptDriver();
			cout << "LoadTrueCryptDriver returned " << res << "\n";
		}
		UnloadTrueCryptApi();
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	ApiTest *apiTest = new ApiTest();
	apiTest->run();
	delete apiTest;
	cin.get();
	return 0;
}

