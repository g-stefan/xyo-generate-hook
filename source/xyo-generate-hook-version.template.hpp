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

#define XYO_GENERATE_HOOK_VERSION_ABCD                $VERSION_ABCD
#define XYO_GENERATE_HOOK_VERSION_STR                 "$VERSION_VERSION"
#define XYO_GENERATE_HOOK_VERSION_STR_BUILD           "$VERSION_BUILD"
#define XYO_GENERATE_HOOK_VERSION_STR_DATETIME        "$VERSION_DATETIME"

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

