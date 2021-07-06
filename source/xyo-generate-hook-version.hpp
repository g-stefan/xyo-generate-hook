//
// XYO Generate Hook
//
// Copyright (c) 2020-2021 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#ifndef XYO_GENERATE_HOOK_VERSION_HPP
#define XYO_GENERATE_HOOK_VERSION_HPP

#define XYO_GENERATE_HOOK_VERSION_ABCD                1,5,0,6
#define XYO_GENERATE_HOOK_VERSION_STR                 "1.5.0"
#define XYO_GENERATE_HOOK_VERSION_STR_BUILD           "6"
#define XYO_GENERATE_HOOK_VERSION_STR_DATETIME        "2021-07-06 15:11:51"

#ifndef XYO_RC

namespace XYOGenerateHook {
	namespace Version {
		const char *version();
		const char *build();
		const char *versionWithBuild();
		const char *datetime();
	};
};

#endif
#endif

