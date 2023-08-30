#include "recordsaver.h"

RecordSaver::RecordSaver(std::string path) :_path(std::move(path)){
}

RecordSaver::~RecordSaver() {

}

void RecordSaver::Read(int &result) {
  std::ifstream filestream(_path );

  if (filestream.is_open())
  {
    std::string line;
    while (std::getline(filestream, line))
    {
      std::istringstream linestream(line);
      linestream >> result;
    }
    filestream.close();
  }
  else
  {
    std::ofstream outfile(_path);
    std::cout << "No results yet!" << std::endl;
  }
}
