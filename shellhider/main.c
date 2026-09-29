#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "utiles.h"
#include "ipv4.h"


int printUsage(char* MeLocation) {
	printf("[!] Usage: %s <payload file path> [Option]\n", MeLocation);
	printf("[i] Option Can Be : \n");
	printf("\n\t[1] \"Ipv4Fuscation\" || \"ipv4\" ");
	printf("\n\t[2] \"Ipv6Fuscation\" || \"ipv6\" ");
	printf("\n\t[3] \"UUIDFuscation\" || \"uuid\" ");
	printf("\n");
	printf("[i] ");
	system("PAUSE");
	return -1;
}


int main(int argc, char* argv[])
{
	// args check:
	if (argc != 3) {
		return printUsage(argv[0]);
	}

    return 0;
}

