#include <mutex>

struct Job {
  int id;
  int count;
} 

class JobQueue3 {
  std::queue<Job> jobs;
  std::mutex m;
  std::counting_semaphore<> count;

  public:
  JobQueue3() : jobs{}, m{}, count{0} {}

  void enqueue(Job job) {
    std::unique_lock lock{m};
    jobs.push(job);
    count.release();
  }

  std::optional<Job> try_deque() {
    if (count.try_acquire()) {
      std::unique_lock lock{m};
      Job j = jobs.front();
      jobs.pop();
      return j;
    }
    return std::nullopt;
  }

  Job deque() {
    std::unique_lock lock{m};
    count.acquire();
    Job j = jobs.front();
    jobs.pop();
    return j;
  }
};

