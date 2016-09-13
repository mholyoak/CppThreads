#ifndef CTHREADTEST_H
#define CTHREADTEST_H

#include "CCountItem.h"

class CThreadTest
{
public:
    CThreadTest();

    void RunThreadCounters(bool bUseMutex);

    int GetNumbersCounted() const;
    int GetNumber(int index) const;
    int GetThreadNumber(int index) const;

private:
    enum {kMaxCounters = 20};
    CCountItem mCountItems[kMaxCounters];
};

#endif // CTHREADTEST_H
