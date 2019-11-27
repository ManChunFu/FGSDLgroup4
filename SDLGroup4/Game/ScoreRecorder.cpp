#include "ScoreRecorder.h"
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include "ScoreRecord.h"

#pragma warning(disable : 4996)
void ScoreRecorder::AddNewScore(int score)
{
	std::fstream streamWriter;
	streamWriter.open(scoreFilename, std::fstream::in | std::fstream::out | std::fstream::app);

	std::time_t t = std::time(0); // get time now
	std::tm* now = std::localtime(&t); //covert time to local date
	streamWriter << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_wday << " "
		<< now->tm_hour << ":"
		<< now->tm_min << " | "
		<< score << std::endl;
	streamWriter.close();
}

std::vector<ScoreRecord*> ScoreRecorder::GetSavedRecords()
{
	std::vector<ScoreRecord*> scores;
	std::string line;
	std::ifstream streamReader(scoreFilename);

	if (streamReader.is_open())
	{
		while (std::getline(streamReader,line))
		{
			size_t comaPlace = line.find(',');
			ScoreRecord* scoreLine = new ScoreRecord(line.substr(0, comaPlace),
				line.substr(comaPlace + 1, line.size() - (comaPlace + 1)));

			if (scores.size() == 0)
				scores.push_back(scoreLine);
			else
			{

			}

		}
		streamReader.close();
	} 
	 

	return scores;
}

