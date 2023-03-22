#include <algorithm>
#include <cassert>
#include <iterator>
#include <utility>
#include <vector>

template <typename T>
class TwoStackQueue {
 public:
  T& front() { return out_.empty() ? in_.front() : out_.back(); }
  const T& front() const { return out_.empty() ? in_.front() : out_.back(); }

  T& back() { return in_.empty() ? out_.front() : in_.back(); }
  const T& back() const { return in_.empty() ? out_.front() : in_.back(); }

  [[nodiscard]] bool empty() const { return size() == 0; }
  std::size_t size() const { return in_.size() + out_.size(); }

  void push(const T& value) { in_.push_back(value); }

  void push(T&& value) { in_.push_back(std::move(value)); }

  template <class... Args>
  decltype(auto) emplace(Args&&... args) {
    return in_.emplace_back(std::forward<Args>(args)...);
  }

  void pop() {
    MaybeMoveElements();
    assert(!out_.empty());
    out_.pop_back();
  }

 private:
  void MaybeMoveElements() {
    if (out_.empty()) {
      std::move(in_.rbegin(), in_.rend(), std::back_inserter(out_));
      in_.clear();
    }
  }

  std::vector<T> in_;
  std::vector<T> out_;
};
