// // Copyright [2023] Hunter M Hasenfus

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <boost/date_time/posix_time/posix_time.hpp>

int main(int argc, char* argv[]) {
  std::ifstream lf(argv[1]);
  if (!lf) {
      std::cerr << "Error with log file: " << argv[1] << std::endl;
      return 1;
  }

  std::ofstream of(std::string(argv[1]) + ".rpt");
  if (!of) {
      std::cerr << "Error with output file: "
        << argv[1] << ".rpt" << std::endl;
      return 1;
  }

  std::string line, rs;
  std::regex timePattern(R"((\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}))");
  std::regex startPattern(R"(\((log\.c\.166)\) server started)");
  std::regex finishPattern(R"(oejs\.AbstractConnector:Started SelectChannelConnector@\d+\.\d+\.\d+\.\d+:\d+)");
  boost::posix_time::ptime start_t, finish_t;
  int n;
  bool start = false;


  while (getline(lf, line)) {
    n++;

    std::smatch match;
    if (std::regex_search(line, match, timePattern)
      && match.size() > 1) {
        std::string timestamp_str = match[1];
        boost::posix_time::ptime current_time =
        boost::posix_time::time_from_string(timestamp_str);

      if (std::regex_search(line, match, startPattern)) {
          if (start) {
            of << "\t\t**** Incomplete boot **** \n\n";
            start = false;
          } else {
            of << "=== Device boot ===\n";
            of << n << " (" << argv[1] << "): " <<
              start_t << " Boot Start" << std::endl;
            start_t = current_time;
            start = true;
          }
      } else if (std::regex_search(line, match, finishPattern)) {
          if (start) {
            finish_t = current_time;
            boost::posix_time::time_duration elapsed =
              finish_t - start_t;
            of << n << " (" << argv[1] << "): " <<
              finish_t << " Boot Completed" << std::endl;
            of << "\t\tBoot Time: " <<
              elapsed.total_milliseconds() << "ms\n" << std::endl;
            start = false;
  }}}}



  if (start) {
    of << "=== Device boot ===\n";
    of << n << " (" << argv[1] << "): " <<
    start_t << " Boot Start" << std::endl;
  }

  lf.close();
  of.close();
  return 0;
}
