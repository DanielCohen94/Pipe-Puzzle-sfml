#pragma once
typedef std::pair< size_t, size_t > point;
typedef std::pair< int, point > dirEnd;

bool comp(const dirEnd& left, const dirEnd& right)
{
	if ((left.second.first > right.second.first) || (left.second.first == right.second.first && left.second.second > right.second.second))
		return false;
	return true;
}