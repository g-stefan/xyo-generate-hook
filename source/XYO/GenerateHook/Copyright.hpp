// Generate Hook
// Copyright (c) 2022 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2022 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#ifndef XYO_GENERATEHOOK_COPYRIGHT_HPP
#define XYO_GENERATEHOOK_COPYRIGHT_HPP

#ifndef XYO_GENERATEHOOK_DEPENDENCY_HPP
#	include <XYO/GenerateHook/Dependency.hpp>
#endif

namespace XYO::GenerateHook::Copyright {
	const char *copyright();
	const char *publisher();
	const char *company();
	const char *contact();
	const char *fullCopyright();
};

#endif
