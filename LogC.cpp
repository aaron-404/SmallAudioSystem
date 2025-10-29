#include "LogC.h"
#include "ConstantDefs.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <chrono>
#include <ctime>
#include <format>
#include <cstdlib>
#include <iomanip>

std::once_flag LogC::sm_logOpened;
std::ofstream LogC::sm_filestream;
std::mutex LogC::sm_logMutex;

// Constructor
LogC::LogC(void) {
}

// Destructor
LogC::~LogC() {
}

void LogC::CloseLog(){
    std::lock_guard<std::mutex> lock(sm_logMutex);
    if(sm_filestream.is_open()){
        sm_filestream << "Log file closing...\n\n";
        sm_filestream << std::flush;
        sm_filestream.close();
    }
}


void LogC::MakeLogEntry(const std::string& entryText, LogType type){

    // Skip writing debug logs if debug is not enabled
    if(type == LT_DEBUG && !DEBUG_ENABLED){
        return;
    }

    // Initialize log file on first call to MakeLogEntry
    if(!sm_filestream.is_open()){
        std::call_once(sm_logOpened, OpenLog);  // NOTE: call_once is thread safe (does not need to be in mutex)
    }

    // Write timestamp, log type, and log message to log file
    std::lock_guard<std::mutex> lock(sm_logMutex);
    if(sm_filestream.is_open()){
        // Get current system time
        auto now = std::chrono::system_clock::now();
        sm_filestream << std::format("{:%Y-%m-%d %H:%M:%S} | ", now) ;
        switch(type){
            case LT_INFO:
                sm_filestream << "[INFO] | ";
                break;
            case LT_ERROR:
                sm_filestream << "[ERROR] | ";
                break;
            case LT_DEBUG:
                sm_filestream << "[DEBUG] | ";
                break;
        }
        sm_filestream << entryText << "\n";
        sm_filestream << std::flush;
    }
}


void LogC::OpenLog(void){
    if(!sm_filestream.is_open()){
        sm_filestream.open(LOG_FILENAME, std::ios::app);
        if(!sm_filestream.is_open()){
            std::cerr << "\nSmallAudioSystem - Error creating/opening log file!\n";
        }
        else{
            sm_filestream << "Log file initialized...\n";
            std::atexit(CloseLog);
        }
    }
}