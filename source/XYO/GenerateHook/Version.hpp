// Generate Hook
// Copyright (c) 2014-2024 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2014-2024 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#ifndef XYO_GENERATEHOOK_VERSION_HPP
#define XYO_GENERATEHOOK_VERSION_HPP

#ifndef XYO_GENERATEHOOK_DEPENDENCY_HPP
#	include <XYO/GenerateHook/Dependency.hpp>
#endif

namespace XYO::GenerateHook::Version {

	const char *version();
	const char *build();
	const char *versionWithBuild();
	const char *datetime();

};

#endif
