#ifndef LOGC
#define LOGC

// Include necessary standard or custom headers here
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include "ConstantDefs.h"

class LogC {
public:
    // Constructor and Destructor
    LogC(void);
    ~LogC();

    enum LogType{LT_INFO, LT_ERROR, LT_DEBUG};

    void MakeLogEntry(const std::string& entryText, LogType);

protected:

    static void OpenLog(void);
    static void CloseLog(void);

    static std::ofstream sm_filestream;
    static std::mutex sm_logMutex;
    static std::once_flag sm_logOpened;
};

#endif // LOGC