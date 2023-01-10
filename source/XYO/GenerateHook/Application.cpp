// Generate Hook
// Copyright (c) 2014-2023 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2014-2023 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <XYO/GenerateHook/Application.hpp>
#include <XYO/GenerateHook/Copyright.hpp>
#include <XYO/GenerateHook/License.hpp>
#include <XYO/GenerateHook/Version.hpp>

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

namespace XYO::GenerateHook {

	void Application::showUsage() {
		printf("xyo-generate-hook - Generate hook\n");
		printf("version %s build %s [%s]\n", XYO::GenerateHook::Version::version(), XYO::GenerateHook::Version::build(), XYO::GenerateHook::Version::datetime());
		printf("%s\n\n", XYO::GenerateHook::Copyright::copyright());
		printf("\n");
		printf("Usage:\n");
		printf("\txyo-generate-hook --license\n");
		printf("\txyo-generate-hook module callType returnType functionName parameters\n");
	};

	void Application::showLicense() {
		printf("%s", GenerateHook::License::license());
	};

	void Application::showVersion() {
		printf("version %s build %s [%s]\n", GenerateHook::Version::version(), GenerateHook::Version::build(), GenerateHook::Version::datetime());
	};

	void Application::initMemory() {
		String::initMemory();
		TDynamicArray<String>::initMemory();
	};

	int Application::main(int cmdN, char *cmdS[]) {
		int k;

		if (cmdN == 2) {
			if (strcmp(cmdS[1], "--license") == 0) {
				showLicense();
				return 0;
			};
			return 1;
		};

		if (cmdN < 6) {
			showUsage();
			return 1;
		};

		sModule = cmdS[1];
		sCallType = cmdS[2];
		sReturnType = cmdS[3];
		sFunctionName = cmdS[4];
		sFunctionParameters = cmdS[5];

		strcpy(sModuleX, sModule);
		for (k = 0; sModuleX[k] != 0; ++k) {
			if (sModuleX[k] == '-') {
				sModuleX[k] = '_';
			};
		};

		sprintf(sModuleC, "new_%s.cpp", sModule);
		fModuleC = fopen(sModuleC, "at");
		if (fModuleC != NULL) {
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
			        sModuleX, sFunctionName);
			fclose(fModuleC);
		};

		sprintf(sFunctionC, "new_%s__%s.cpp",
		        sModule, sFunctionName);
		fModuleC = fopen(sFunctionC, "rt");
		if (fModuleC != NULL) {
			fclose(fModuleC);
		} else {
			fModuleC = fopen(sFunctionC, "wt");
			if (fModuleC != NULL) {
				fprintf(fModuleC, "static %s %s _new_%s__%s(%s){\n",
				        sReturnType, sCallType, sModuleX, sFunctionName, sFunctionParameters);
				if ((strcmp(sReturnType, "VOID") != 0) &&
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
		if (fModuleC != NULL) {

			fprintf(fModuleC, "XYO::Win::Inject::Hook::setOriginalFunction(_hook_%s__%s,\"%s\",\"%s\",(FARPROC)_new_%s__%s);\n",
			        sModuleX, sFunctionName,
			        sModule, sFunctionName,
			        sModuleX, sFunctionName);

			fclose(fModuleC);
		};

		sprintf(sFunctionC, "new_%s___hookProc.cpp", sModule);
		fModuleC = fopen(sFunctionC, "at");
		if (fModuleC != NULL) {

			fprintf(fModuleC, "&_hook_%s__%s,\n",
			        sModuleX, sFunctionName);

			fclose(fModuleC);
		};

		sprintf(sFunctionC, "new_%s___proc.cpp", sModule);
		fModuleC = fopen(sFunctionC, "at");
		if (fModuleC != NULL) {

			fprintf(fModuleC, "#include \"new_%s__%s.cpp\"\n",
			        sModule, sFunctionName);

			fclose(fModuleC);
		};

		return 0;
	};
};

#ifndef XYO_GENERATEHOOK_LIBRARY
XYO_APPLICATION_MAIN(XYO::GenerateHook::Application);
#endif
