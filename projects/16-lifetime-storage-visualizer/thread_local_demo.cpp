#include <iostream>
#include <thread>

class Trace {
public:
    explicit Trace(const char* name) : name_{name} {
        std::cout << "construct " << name_ << '\n';
    }

    ~Trace() {
        std::cout << "destroy " << name_ << '\n';
    }

private:
    const char* name_;
};

void observe_thread_local() {
    thread_local Trace worker_trace{"worker thread-local"};
}

int main() {
    std::jthread worker{observe_thread_local};
}
