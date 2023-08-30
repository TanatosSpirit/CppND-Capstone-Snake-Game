#include "recordsaver.h"

RecordSaver::RecordSaver(std::string path) :_path(std::move(path)), _max_result(0) {
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
      _max_result = result;
    }
    filestream.close();
  }
  else
  {
    std::ofstream outfile(_path);
    std::cout << "No results yet!" << std::endl;
  }
}

void RecordSaver::Write(int result) {
  if(result < _max_result)
    return;

  std::ofstream file(_path, std::ios::trunc);

  if(file.is_open()){
    file << result << '\r';
    file.close();
  }
}
