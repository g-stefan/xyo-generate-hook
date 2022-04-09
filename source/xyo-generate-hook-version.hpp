//
// XYO Generate Hook
//
// Copyright (c) 2020-2022 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#ifndef XYO_GENERATE_HOOK_VERSION_HPP
#define XYO_GENERATE_HOOK_VERSION_HPP

#define XYO_GENERATE_HOOK_VERSION_ABCD 1,12,0,25
#define XYO_GENERATE_HOOK_VERSION_STR "1.12.0"
#define XYO_GENERATE_HOOK_VERSION_STR_BUILD "25"
#define XYO_GENERATE_HOOK_VERSION_STR_DATETIME "2022-04-04 01:45:00"

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
