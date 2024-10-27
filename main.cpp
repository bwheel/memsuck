#ifdef __linux__
#include <unistd.h>
#elif _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <memory>

#include <cxxopts.hpp>

int main(int argc, char *argv[]) {

  cxxopts::Options options("memsuck", "Memory suck. This tool will consume the memory on target device.");

  options.add_options()
      // delay
      ("d,delay", "How long the program should delay(milliseconds) before freeing the memory.", cxxopts::value<int>()->default_value("1000"))
      // memory
      ("m,memory", "The amound of memory to be consumed", cxxopts::value<long>()->default_value("1000"))
      // help
      ("h,help", "Prints the help message");
  int delay;
  long memory;
  try {
    auto result = options.parse(argc, argv);
    if (result.count("help")) {
      std::cout << options.help() << std::endl;
      exit(0);
    }
    delay = result["delay"].as<int>();
    memory = result["memory"].as<long>();

  } catch (const std::exception &e) {
    std::cerr << "Error parsing options: " << e.what() << std::endl;
    return 1;
  }
  std::cout << "Starting memsuck\n";
  std::cout << "Settings:\n";
  std::cout << "\tdelay: " << delay << "\n";
  std::cout << "\tmemory: " << memory << "\n";

  int *buffer = new int[memory];
  std::uninitialized_fill_n(buffer, memory, 1);

#ifdef __linux__
  int delayLinux = delay / 1000;
  sleep(delayLinux);
#elif _WIN32
  Sleep(delay);
#endif
  std::cout << "Finished\n";
  delete[] buffer;
  return 0;
}
