// #include "main.h"
// #include "chrono"

// using namespace std::chrono;
// using namespace std;


// class Timer {

//     public:
//         std::chrono::time_point<std::chrono::system_clock> startTime, endTime;
//         std::chrono::duration<double> elapsed_seconds;

//         bool isTiming = false;

//         void start() {
//             startTime = std::chrono::system_clock::now();
//             isTiming = true;
//         }

//         void stop() {
//             endTime = std::chrono::system_clock::now();
//             isTiming = false;
//         }

//         double getElapsedTime() {
//             if (isTiming) {
//                 elapsed_seconds = std::chrono::system_clock::now() - startTime;
//             }
//             else {
//                 elapsed_seconds = endTime - startTime;
//             }
//             return elapsed_seconds.count();
//         }

//         void clear() {
//             isTiming = false;
//             startTime = std::chrono::system_clock::now();
//             endTime = std::chrono::system_clock::now();
//         }
// };
