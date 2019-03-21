#ifndef CTHREADWORKER_H
#define CTHREADWORKER_H

#include "ccountitem.h"
#include <mutex>

class CThreadWorker
{
private:
    int             mCountTimes;
    CCountItem*     mpCountItems;
    int             mCountItemsSize;
    std::mutex*     mpMutex;
    int             mThreadNumber;

public:
    CThreadWorker(int countTimes, CCountItem* pCountItems, int countItemsSize, std::mutex* pMutex, int threadNumber);

    void operator() ();
};

#endif // CTHREADWORKER_H
