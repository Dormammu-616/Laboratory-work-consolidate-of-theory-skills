#pragma once
#include "State.h"
#include "UserSession.h"

struct Entry
{
	UserSession user_data{};
	State user_state{};
	uint8_t padding[4]{};
	Entry();
	Entry(const UserSession data, State state);
};