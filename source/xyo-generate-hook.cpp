//
// XYO Generate Hook
//
// Copyright (c) 2020-2022 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#include <stdio.h>
#include <string.h>

#include "xyo-generate-hook-copyright.hpp"
#include "xyo-generate-hook-license.hpp"
#include "xyo-generate-hook-version.hpp"


FILE *fModuleC;
char sModuleC[1024];
char sModuleX[1024];
FILE *fFunctionC;
char sFunctionC[1024];
char *sModule;
char *sCallType;
char *sReturnType;
char *sFunctionName;
char *sFunctionParameters;

int main(int cmd, char *cmds[]) {
	int k;

	if (cmd == 2) {
		if (strcmp(cmds[1], "--license") == 0) {
			printf("%s", XYOGenerateHook::License::content());
			return 0;
		};
		return 1;
	};

	if(cmd < 6) {
		printf("xyo-generate-hook - Generate hook\n");
		printf("version %s build %s [%s]\n", XYOGenerateHook::Version::version(), XYOGenerateHook::Version::build(), XYOGenerateHook::Version::datetime());
		printf("%s\n\n", XYOGenerateHook::Copyright::fullCopyright());
		printf("\n");
		printf("Usage:\n");
		printf("\txyo-generate-hook --license\n");
		printf("\txyo-generate-hook module callType returnType functionName parameters\n");
		return 1;
	};

	sModule = cmds[1];
	sCallType = cmds[2];
	sReturnType = cmds[3];
	sFunctionName = cmds[4];
	sFunctionParameters = cmds[5];

	strcpy(sModuleX, sModule);
	for(k = 0; sModuleX[k] != 0; ++k) {
		if(sModuleX[k] == '-') {
			sModuleX[k] = '_';
		};
	};

	sprintf(sModuleC, "new_%s.cpp", sModule);
	fModuleC = fopen(sModuleC, "at");
	if(fModuleC != NULL) {
		fprintf(fModuleC, "typedef %s (%s *_ptr_%s__%s)(%s);\n",
			sReturnType, sCallType, sModuleX, sFunctionName, sFunctionParameters);
		fprintf(fModuleC, "static %s %s _new_%s__%s(%s);\n",
			sReturnType, sCallType,
			sModuleX, sFunctionName,
			sFunctionParameters);
		fprintf(fModuleC, "static XYO::Win::Inject::Hook::HookProc _hook_%s__%s;\n",
			sModuleX, sFunctionName);
		fprintf(fModuleC, "#define _original_%s__%s ((_ptr_%s__%s)(_hook_%s__%s.originalProc))\n",
			sModuleX, sFunctionName,
			sModuleX, sFunctionName,
			sModuleX, sFunctionName
		);
		fclose(fModuleC);
	};

	sprintf(sFunctionC, "new_%s__%s.cpp",
		sModule, sFunctionName);
	fModuleC = fopen(sFunctionC, "rt");
	if(fModuleC != NULL) {
		fclose(fModuleC);
	} else {
		fModuleC = fopen(sFunctionC, "wt");
		if(fModuleC != NULL) {
			fprintf(fModuleC, "static %s %s _new_%s__%s(%s){\n",
				sReturnType, sCallType, sModuleX, sFunctionName, sFunctionParameters);
			if((strcmp(sReturnType, "VOID") != 0) &&
				(strcmp(sReturnType, "void") != 0)) {
				fprintf(fModuleC, "%s retV;\n", sReturnType);
				fprintf(fModuleC, "\tretV=_original_%s__%s(...);\n", sModuleX, sFunctionName);
				fprintf(fModuleC, "\treturn retV;\n", sReturnType);
			} else {
				fprintf(fModuleC, "\t_original_%s__%s(...);\n", sModuleX, sFunctionName);
			};
			fprintf(fModuleC, "};\n");
			fclose(fModuleC);
		};
	};

	sprintf(sFunctionC, "new_%s___setOriginalFunction.cpp", sModule);
	fModuleC = fopen(sFunctionC, "at");
	if(fModuleC != NULL) {

		fprintf(fModuleC, "XYO::Win::Inject::Hook::setOriginalFunction(_hook_%s__%s,\"%s\",\"%s\",(FARPROC)_new_%s__%s);\n",
			sModuleX, sFunctionName,
			sModule, sFunctionName,
			sModuleX, sFunctionName
		);

		fclose(fModuleC);
	};

	sprintf(sFunctionC, "new_%s___hookProc.cpp", sModule);
	fModuleC = fopen(sFunctionC, "at");
	if(fModuleC != NULL) {

		fprintf(fModuleC, "&_hook_%s__%s,\n",
			sModuleX, sFunctionName
		);

		fclose(fModuleC);
	};

	sprintf(sFunctionC, "new_%s___proc.cpp", sModule);
	fModuleC = fopen(sFunctionC, "at");
	if(fModuleC != NULL) {

		fprintf(fModuleC, "#include \"new_%s__%s.cpp\"\n",
			sModule, sFunctionName
		);

		fclose(fModuleC);
	};

	return 0;
};

