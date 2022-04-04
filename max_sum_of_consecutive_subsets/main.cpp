#include <iostream>
#include <vector>

using namespace std;

static inline void listUpMaxSummaries(const vector<int>& inputVector, vector<int>* pOutMaxSumList)
{
    pOutMaxSumList->push_back(inputVector[0]);
    for (register int i = 1; i < inputVector.size(); i++) {
        const int sumToHere = (*pOutMaxSumList)[i - 1] + inputVector[i];
        if (sumToHere > inputVector[i]) { 
            pOutMaxSumList->push_back(sumToHere); 
        } else { 
            pOutMaxSumList->push_back(inputVector[i]); 
        }
    }
}

static inline int getMaxSumOfConsecutiveSubsets(const vector<int>& inputVector)
{
    vector<int> maxSumList;
    listUpMaxSummaries(inputVector, &maxSumList);
    int max = maxSumList[0];
    for (vector<int>::const_iterator citr = maxSumList.cbegin() + 1; citr != maxSumList.cend(); ++citr) {
        if (*citr > max) { max = *citr; }
    }
    return max;
}

static inline void initInputVector(vector<int>* pOutInputVector)
{
    pOutInputVector->push_back(33);
    pOutInputVector->push_back(31);
    pOutInputVector->push_back(92);
    pOutInputVector->push_back(-38);
    pOutInputVector->push_back(11);
    pOutInputVector->push_back(12);
    pOutInputVector->push_back(4);
    pOutInputVector->push_back(-17);
    pOutInputVector->push_back(-1);
    pOutInputVector->push_back(21);
}

int main()
{
    vector<int> vec;
    initInputVector(&vec);
    const int maxSum = getMaxSumOfConsecutiveSubsets(vec);
    cout << "Max sum : " << maxSum << endl;
    return 0;
}