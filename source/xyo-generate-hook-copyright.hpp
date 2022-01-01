//
// XYO Generate Hook
//
// Copyright (c) 2020-2022 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#ifndef XYO_GENERATE_HOOK_COPYRIGHT_HPP
#define XYO_GENERATE_HOOK_COPYRIGHT_HPP

#define XYO_GENERATE_HOOK_COPYRIGHT            "Copyright (c) Grigore Stefan"
#define XYO_GENERATE_HOOK_PUBLISHER            "Grigore Stefan"
#define XYO_GENERATE_HOOK_COMPANY              XYO_GENERATE_HOOK_PUBLISHER
#define XYO_GENERATE_HOOK_CONTACT              "g_stefan@yahoo.com"
#define XYO_GENERATE_HOOK_FULL_COPYRIGHT        XYO_GENERATE_HOOK_COPYRIGHT " <" XYO_GENERATE_HOOK_CONTACT ">"

#ifndef XYO_RC

namespace XYOGenerateHook {
	namespace Copyright {
		const char *copyright();
		const char *publisher();
		const char *company();
		const char *contact();
		const char *fullCopyright();
	};
};

#endif
#endif
