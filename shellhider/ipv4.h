#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include "utiles.h"

char* GenerateIpv4(int a, int b, int c, int d) {
	unsigned char output[32];
	sprintf_s(output, sizeof(output), "%d.%d.%d.%d", a, b, c, d);
	return (char*)output;
}


void GenerateIpv4Output(unsigned char* pShellcode, SIZE_T ShellcodeSize) {


	// If the shellcode buffer is not a multiple of 4
	if (ShellcodeSize % 4 != 0) {

		printf("The Shellcode size is not Multiple by 4\n");
		AppendShellcode(4, ShellcodeSize, pShellcode);
	}

	printf("char* Ipv4Array[%d] = { \n\t", (int)(ShellcodeSize / 4));

	int c = 4, counter = 0;
	char* IP = NULL;

	for (int i = 0; i < ShellcodeSize; i++) {

		// Track the number of bytes read and when they reach 4 we enter this if statement to begin generating the IPv4 address
		if (c == 4) {
			counter++;

			// Generating the IPv4 address from 4 bytes which begin at i until [i + 3]
			IP = GenerateIpv4(pShellcode[i], pShellcode[i + 1], pShellcode[i + 2], pShellcode[i + 3]);

			// Printing the last IPv4 address
			if (i == ShellcodeSize - 4) {
				printf("\"%s\"", IP);
				break;
			}
			else {
				printf("\"%s\", ", IP);
			}

			c = 1;
		}
		else {
			c++;
		}
	}
	printf("\n};\n\n");


}

