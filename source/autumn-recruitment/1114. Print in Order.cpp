class Foo {
public:
    Foo() {
        counter = 1;
    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> locker(m_mutex);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ++counter;
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> locker(m_mutex);
        cv1.wait(locker, [this](){return counter == 2;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ++counter;
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> locker(m_mutex);
        cv2.wait(locker, [this](){return counter == 3;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
private:
    std::mutex m_mutex;
    std::condition_variable cv1;
    std::condition_variable cv2;
    
    int counter;
};