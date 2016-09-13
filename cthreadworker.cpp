#include "cthreadworker.h"
#include <thread>

CThreadWorker::CThreadWorker(int countTimes, CCountItem* pCountItems, int countItemsSize, std::mutex* pMutex, int threadNumber) :
    mCountTimes(countTimes),
    mpCountItems(pCountItems),
    mCountItemsSize(countItemsSize),
    mpMutex(pMutex),
    mThreadNumber(threadNumber)
{

}

void CThreadWorker::operator() ()
{
    for(int i = 0; i < mCountTimes; i++)
    {
        int lastCount = -1;
        int countValue = 0;

        //std::lock_guard<std::mutex> myLock(*mpMutex);
        if (mpMutex)
        {
            mpMutex->lock();
        }

        // find Last count value
        for(int j = 0; j < mCountItemsSize; j++)
        {
            if (mpCountItems[j].count == 0)
            {
                lastCount = j;
                break;
            }
        }

        if (lastCount > 0)
        {
            countValue = mpCountItems[lastCount - 1].count;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        if (lastCount < mCountItemsSize)
        {
            mpCountItems[lastCount].count = countValue + 1;
            mpCountItems[lastCount].threadNumber = mThreadNumber;
        }

        if (mpMutex)
        {
            mpMutex->unlock();
        }
    }
}
