
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>
#include <boost/timer/timer.hpp>
#include <iostream>

///
///
struct gen_array
{
    //コンストラクタ
    gen_array() : count_(0), rand_engin_(seed_()) {
        // __PRETTY_FUNCTION__ は事前定義マクロ
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    // fizzbuzz言わす
    void say() {
        ++count_;

        if ((count_ % 3 == 0) && (count_ % 5 == 0)) {
            std::cout << "fizzbuzz" << std::endl;
        }
        else if (count_ % 3 == 0) {
            std::cout << "fizz" << std::endl;
        }
        else if (count_ % 5 == 0) {
            std::cout << "buzz" << std::endl;
        }
        else {
            std::cout << count_ << std::endl;
        }
    }

    std::vector<std::uint16_t> get_int_array(std::uint16_t size) {
        std::vector<std::uint16_t> result;
        result.reserve(size);

        boost::random::uniform_int_distribution<> dist(0, 65535);  // 0から65535のサイズまでの数字

        for (int i = 0; i < size; ++i) {
            auto& n = result.emplace_back(dist(rand_engin_));
            // std::cout << n << " loop: " << i << std::endl;
        }

        return result;
    }

    //デストラクタ
    ~gen_array() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

private:
    uint32_t count_;
    boost::random::random_device seed_;
    boost::random::mt19937 rand_engin_;
};

int main() {
    boost::timer::cpu_timer timer;  // 時間計測を開始
    timer.start();

    gen_array obj;
    uint32_t max(1000000);

    auto arry = obj.get_int_array(max);
    for (auto num : arry) {
        std::cout << num << std::endl;
    }

    timer.stop();
    std::cout << "===============================" << std::endl;
    std::cout << " -- result -- " << timer.format(9, "%w s") << std::endl;
    std::cout << "===============================" << std::endl;
}