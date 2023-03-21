// Generate Hook
// Copyright (c) 2014-2023 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2014-2023 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#include <XYO/GenerateHook/Copyright.hpp>
#include <XYO/GenerateHook/Copyright.rh>

namespace XYO::GenerateHook::Copyright {

	static const char *copyright_ = XYO_GENERATEHOOK_COPYRIGHT;
	static const char *publisher_ = XYO_GENERATEHOOK_PUBLISHER;
	static const char *company_ = XYO_GENERATEHOOK_COMPANY;
	static const char *contact_ = XYO_GENERATEHOOK_CONTACT;

	std::string copyright() {
		return copyright_;
	};

	std::string publisher() {
		return publisher_;
	};

	std::string company() {
		return company_;
	};

	std::string contact() {
		return contact_;
	};

};
