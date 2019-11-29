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
		<< (now->tm_mon + 1) << '-'
		<< now->tm_wday << " "  
		<< now->tm_hour << ":"
		<< now->tm_min << "  |  "
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
			size_t comaPlace = line.find('|');
			ScoreRecord* scoreLine = new ScoreRecord(line.substr(0, comaPlace),
				line.substr(comaPlace + 1, line.size() - (comaPlace + 1)));

			/*if (scores.size() == 0)*/
				scores.push_back(scoreLine);
			/*else
			{*/
				/*for (int index = 0; index < scores.size(); index++)
				{
					if (scoreLine->Score > scores[index]->Score)
					{
						scores.insert(scores.begin(), scores[index]);
						goto endwhile;
					}
				}
				scores.push_back(scoreLine)*/;
			//}
		/*endwhile:;*/
		}
		streamReader.close();
				scores = sortScores(scores);
	} 
	return scores;
}

std::string ScoreRecorder::GetSavedRecordsAsText()
{
	
	std::string scoreList = "";
	for (auto score : GetSavedRecords())
	{
		scoreList += score->Date + " | " + std::to_string(score->Score) + '\n';
	}
	return scoreList;
}

std::vector<ScoreRecord*> ScoreRecorder::sortScores(std::vector<ScoreRecord*> scoreList)
{
	ScoreRecord* temp;
	for (int i = 0; i < scoreList.size() -1 ; i++)
	{
		for  (int j = 0; j < scoreList.size();  j++)
		{
			if (scoreList[i]->Score < scoreList[j]->Score)
			{
				temp = scoreList[i];
				scoreList[i] = scoreList[j];
				scoreList[j] = temp;
			}
		}
	}
	return scoreList;
}

