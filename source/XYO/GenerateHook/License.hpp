// Generate Hook
// Copyright (c) 2022 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2022 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#ifndef XYO_GENERATEHOOK_LICENSE_HPP
#define XYO_GENERATEHOOK_LICENSE_HPP

#ifndef XYO_GENERATEHOOK_DEPENDENCY_HPP
#	include <XYO/GenerateHook/Dependency.hpp>
#endif

namespace XYO::GenerateHook::License {

	const char *licenseHeader();
	const char *licenseBody();
	const char *shortLicense();

};

#endif
