#include "cthreadtest.h"
#include "CThreadWorker.h"
#include <assert.h>
#include <mutex>
#include <thread>

CThreadTest::CThreadTest()
{
}

void CThreadTest::RunThreadCounters(bool bUseMutex)
{
    std::mutex myMutex;
    std::mutex* pUseMutex = nullptr;

    if (bUseMutex)
    {
        pUseMutex = &myMutex;
    }

    CThreadWorker worker(10, mCountItems, kMaxCounters, pUseMutex, 1);
    CThreadWorker workerTwo(10, mCountItems, kMaxCounters, pUseMutex, 2);

    std::thread myThread(worker);
    std::thread mySecondThread(workerTwo);
    myThread.join();
    mySecondThread.join();


}

int CThreadTest::GetNumbersCounted() const
{
    return kMaxCounters;
}

int CThreadTest::GetNumber(int index) const
{
    int rtnCounter = 0;

    assert (index < kMaxCounters);
    if (index < kMaxCounters)
    {
        rtnCounter = mCountItems[index].count;
    }

    return rtnCounter;
}

int CThreadTest::GetThreadNumber(int index) const
{
    int rtnThreadNum = 0;

    assert(index < kMaxCounters);
    if (index < kMaxCounters)
    {
        rtnThreadNum = mCountItems[index].threadNumber;
    }

    return rtnThreadNum;
}
