#include "pch.h"
#include "wordFinder.h"
#include <string>

wordFinder::wordFinder(std::string subSeq)
{
    sortDictionary();

    for(int i = sizeof(dictionary)/sizeof(dictionary[0]) - 1; i >= 0; i--)
    {
        trueSubSeq = runScan(subSeq, i);
        if(trueSubSeq)
        {
            std::cout << "The word " << dictionary[i] << " is longest word that matches the subsequence." << std::endl;
            break;
        }
    }
}

bool wordFinder::runScan(std::string subSeq, int i)
{
    int lastIndexSub = -1, lastIndexDic = -1;
    int found = 0;
    for(int j = 0; j < dictionary[i].length(); j++)
    {
        for(int k = lastIndexSub+1; k < subSeq.length(); k++)
        {
			if ((subSeq[k] != dictionary[i][j]) && k == 0 && j == 0)
				return false;
			else if (subSeq[k] == dictionary[i][j] && j > lastIndexDic)
			{
				lastIndexSub = k;
				lastIndexDic = j;
				found++;
				break;
			}
			else
				continue;
        }
		
    }
	if (found == dictionary[i].length())
		return true;
	else
		return false;
}

void wordFinder::sortDictionary()
{
    std::string temp;
    bool bblSwap;
    do{
        bblSwap = false;
        
        for(int i = 0; i < 4; i++)
        {
            if(dictionary[i].length() > dictionary[i+1].length())
            {
                bblSwap = true;
                temp = dictionary[i];
                dictionary[i] = dictionary[i+1];
                dictionary[i+1] = temp;
            }
        }
    }while(bblSwap);
}

wordFinder::~wordFinder()
{
}
