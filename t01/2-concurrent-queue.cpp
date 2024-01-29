struct Job {
  int id;
  int count;
} 

class JobQueue {
  std::queue<Job> jobs;

  public:
  void enqueue(Job job) {
    jobs.push(job);
  }

  std::optional<Job> try_deque() {
    if (jobs.empty()) {
      return std::nullopt;
    } else {
      Job job = jobs.front();
      jobs.pop();
      return job;
    }
  }
};


/* Potential Data Races
 * 1. Thread 1 tries to place job in queue while Thread 2 is extracting a job.  
 * 2. Thread 1 tries to place job in queue while Thread 2 modifies the count of a job.
*/


