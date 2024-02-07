#include <mutex>

struct Job {
  int id;
  int count;
} 

class JobQueue4 {
  std::queue<Job> jobs;
  std::mutex m;
  std::condition_variable cond;

  public:
  JobQueue4() : jobs{}, m{}, count{0} {}

  void enqueue(Job job) {
    std::unique_lock lock{m};
    jobs.push(job);
    cond.notify_one();
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
    while (jobs.empty()) {
      cond.wait(lock);
    }
    Job j = jobs.front();
    jobs.pop();
    return j;
  }
};

