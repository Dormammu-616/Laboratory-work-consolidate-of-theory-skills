#pragma once
#include "Entry.h"

Entry::Entry() : user_data{}, user_state(EMPTY) {};

Entry::Entry(const UserSession data, State state) : user_data(data), user_state(state) {};