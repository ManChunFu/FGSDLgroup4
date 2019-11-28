#pragma once
#include <string>
#include <vector>

class ScoreRecord;
class ScoreRecorder
{
public:
	void AddNewScore(int score);
	std::vector<ScoreRecord*> GetSavedRecords();
	std::string GetSavedRecordsAsText();
	
private:
	const std::string scoreFilename = "ScoreRecords.txt";
};

