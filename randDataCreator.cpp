#include <windows.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

const long COUNT = 30000;
const long ARRAY_LEN = 33;
const long DATEMAX = 31;
const long TIMEMAX = 86400;
const long IPMAX = 500000000;

const long DATENOW = 20141001;

char DATASET[] ={'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'S', 
				 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V',
				 'B', 'N', 'M', '1', '2', '3', '4', '5', '6', '7', '8',
				 '9', '0', 'q', 'w', 'e', 't', 'y', 'u', 'i', 'o', 'p',
				 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x',
				 'c', 'v', 'b', 'n', 'm', 'A',};

long IPDATE[8] = {2500000000, 250000000, 25000000, 2500000, 250000,
					25000, 2500, 250};

int main()
{

	FILE *file = fopen("E://data201410.sql","a");
	char sql[300] = "INSERT INTO wps_log_usage_201410 VALUES ('%ld', '%ld', '%ld', '%s', '%s', '%s', '%s', '%s', '%s');\n";
	char target[500];
	memset(target, 0, sizeof(target));
	//cout << sql << endl;
	//随机数据生成器
	long num = COUNT;

	long date_n = 0;
	long time_n = 0;
	long ip = 111111;
	char guid[ARRAY_LEN];
	char sn[ARRAY_LEN];
	char hid[ARRAY_LEN];
	char vertype[ARRAY_LEN];
	char distnum[ARRAY_LEN];
	char version[ARRAY_LEN];

	memset(guid, 0, sizeof(guid));
	memset(sn, 0, sizeof(sn));
	memset(hid, 0, sizeof(hid));
	memset(vertype, 0, sizeof(vertype));
	memset(distnum, 0, sizeof(distnum));
	memset(version, 0, sizeof(version));
	
	int dataLen = strlen(DATASET);
	srand((unsigned)(time(NULL)));
	while(num --)
	{
		date_n = rand() % DATEMAX + DATENOW;
		time_n = rand() % TIMEMAX;
		ip = rand() % IPMAX + IPDATE[rand() % 8];

		for(int i = 0; i < ARRAY_LEN - 1; ++i)
		{
			guid[i] = DATASET[rand() % dataLen];
			sn[i] = DATASET[rand() % dataLen];
			hid[i] = DATASET[rand() % dataLen];
			vertype[i] = DATASET[rand() % dataLen];
			distnum[i] = DATASET[rand() % dataLen];
			version[i] = DATASET[rand() % dataLen];
		}
		guid[ARRAY_LEN - 1] = '\0';
		sn[ARRAY_LEN - 1] = '\0';
		hid[ARRAY_LEN - 1] = '\0';
		vertype[ARRAY_LEN - 1] = '\0';
		distnum[ARRAY_LEN - 1] = '\0';
		version[ARRAY_LEN - 1] = '\0';
		if(ip < 0)	
			ip = ip * (-1);
		sprintf(target, sql, date_n, time_n, ip, guid, sn, hid, vertype, distnum, version);
		fputs(target, file);
	}
	fclose(file);
	printf("file write end\n");
	return 0;
}