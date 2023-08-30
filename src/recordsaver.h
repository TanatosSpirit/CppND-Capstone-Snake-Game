#ifndef RECORDSAVER_H
#define RECORDSAVER_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class RecordSaver{
public:
    RecordSaver(std::string path);
    ~RecordSaver();
    void Read(int &result);
    bool Write();

private:
    const std::string _path;
};
#endif
