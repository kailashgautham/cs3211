#include <mutex>

struct Job {
  int id;
  int count;
} 

class JobQueue2 {
  std::queue<Job> jobs;
  std::mutex m;

  public:
  JobQueue2() : jobs{}, m{} {}
  void enqueue(Job job) {
    std::unique_lock lock{m};
    jobs.push(job);
  }

  std::optional<Job> try_deque() {
    std::unique_lock lock{m};
    if (jobs.empty()) {
      return std::nullopt;
    } else {
      Job job = jobs.front();
      jobs.pop();
      return job;
    }
  }
};


/* What happens if we run out of memory?
 *  jobs.push() throws an exception, and then m.unlock() is never called, and the entire system is blocked.
*/


