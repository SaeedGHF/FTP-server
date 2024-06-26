#include "Util.h"

string Util::getCurrentDateTime(string s) {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    if (s == "now")
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    else if (s == "date")
        strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    return string(buf);
}

void Util::log(string logMsg) {
    string filePath = "log";
    string now = Util::getCurrentDateTime("now");
    ofstream ofs(filePath.c_str(), ios_base::out | ios_base::app);
    ofs << now << '\t' << logMsg << '\n';
    ofs.close();
}
