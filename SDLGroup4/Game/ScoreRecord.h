#pragma once
#include <string>

class ScoreRecord
{
public:
	ScoreRecord(const std::string& date, const std::string& score) {
		Score = std::stoi(score);
		Date = date;
	}
	int Score;
	std::string Date;
};
