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

#define XYO_GENERATE_HOOK_VERSION_ABCD                1,8,0,19
#define XYO_GENERATE_HOOK_VERSION_STR                 "1.8.0"
#define XYO_GENERATE_HOOK_VERSION_STR_BUILD           "19"
#define XYO_GENERATE_HOOK_VERSION_STR_DATETIME        "2021-11-15 16:51:55"

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

