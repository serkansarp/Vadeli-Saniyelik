#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>


/*
 Geliþtirmeye baþladýðým ilk dönemlerde vadeli yatýrýmlarýndan para kazanan biri için
 ay sonunda ne kadar kar edeceðini bakiyedenGunlukKalan deðiþkenine girmesi ile
 (ki bu 30 günlük vade için 4000/30 olarak da girilebilir) her saniye o gün servetine
 eklenecek para miktarýný gösteren programdýr. C ile yazýlýp C++ projesi olarak yeniden
 yazýlmýþtýr.
*/

int main() {
    using namespace std::chrono;

    float bakiyedenGunlukKalan = 4000 / 30;

    while (true) {
        auto currentTime = system_clock::now();
        auto timePoint = system_clock::to_time_t(currentTime);
        std::tm* myTime = new std::tm; // Bellek ayrýtma
        localtime_s(myTime, &timePoint);

        int suAndakiSaniye = myTime->tm_hour * 60 * 60 + myTime->tm_min * 60 + myTime->tm_sec;
        std::cout << suAndakiSaniye * bakiyedenGunlukKalan / 86400 << '\r' << std::flush;

        delete myTime; // Bellek serbest býrakma
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
