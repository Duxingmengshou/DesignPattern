#include "NullObject.h"
namespace DP {
    void clientCode(std::unique_ptr<Logger> logger) {
        logger->log("This is a log message.");
    }
} // DP