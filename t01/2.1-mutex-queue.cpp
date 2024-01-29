#include <mutex>

struct Job {
  int id;
  int count;
} 

class JobQueue1 {
  std::queue<Job> jobs;
  std::mutex m;

  public:
  JobQueue1() : jobs{}, m{} {}
  void enqueue(Job job) {
    m.lock();
    jobs.push(job);
    m.unlock();
  }

  std::optional<Job> try_deque() {
    m.lock();
    if (jobs.empty()) {
      m.unlock();
      return std::nullopt;
    } else {
      Job job = jobs.front();
      jobs.pop();
      m.unlock();
      return job;
    }
  }
};


/* Why are the data races now impossible?
 * When the mutex is locked, no other thread that reaches "m.lock()" can proceed, until the thread that has locked the mutex releases the lock and another thread can then proceed.
*/


