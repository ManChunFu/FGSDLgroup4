#include "ScoreRecorder.h"
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include "ScoreRecord.h"
#include <algorithm>

#pragma warning(disable : 4996)
void ScoreRecorder::AddNewScore(int score)
{
	std::fstream streamWriter;
	streamWriter.open("ScoreRecords.txt", std::fstream::in | std::fstream::out | std::fstream::app);

	std::time_t t = std::time(0); // get time now
	std::tm* now = std::localtime(&t); //covert time to local date
	streamWriter << (now->tm_year + 1900) << '-'
		<< (now->tm_mon < 10 ? "0" : "") << (now->tm_mon + 1) << '-'
		<< (now->tm_wday < 10 ? "0" : "") << now->tm_wday << " "
		<< (now->tm_hour < 10 ? "0" : "") << now->tm_hour << ":"
		<< (now->tm_min < 10 ? "0" : "") << now->tm_min << " | "
		<< score << std::endl;
	streamWriter.close();
}

std::vector<ScoreRecord*> ScoreRecorder::GetSavedRecords()
{
	std::vector<ScoreRecord*> scores;
	std::string line;
	std::ifstream streamReader("ScoreRecords.txt", std::fstream::in);

	if (streamReader.is_open())
	{
		while (std::getline(streamReader,line))
		{
			if (line == "")
				continue;

			size_t comaPlace = line.find('|');

			ScoreRecord* scoreLine = new ScoreRecord(line.substr(0, comaPlace), 
				line.substr(comaPlace + 1, line.size() - (comaPlace + 1)));

			if (scores.size() == 0)
				scores.push_back(scoreLine);
			else
			{
				bool inserted = false;
				for (int index = 0; index < scores.size(); index++)
				{
					if (scoreLine->Score > scores[index]->Score)
					{
						scores.push_back(scores[scores.size() - 1]);
						for (int sortIndex = scores.size() - 2; sortIndex > index; sortIndex--)
						{
							int beforeIndex = sortIndex - 1;
							scores[sortIndex] = scores[beforeIndex];
						}
						scores[index] = scoreLine;
						inserted = true;
						break;
					}
				}
				if (!inserted)
					scores.push_back(scoreLine);
			}
		}
		streamReader.close();
	} 
	return scores;
}



