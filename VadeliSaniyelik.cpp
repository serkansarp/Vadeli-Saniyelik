#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>


/*
 Geli�tirmeye ba�lad���m ilk d�nemlerde vadeli yat�r�mlar�ndan para kazanan biri i�in
 ay sonunda ne kadar kar edece�ini bakiyedenGunlukKalan de�i�kenine girmesi ile
 (ki bu 30 g�nl�k vade i�in 4000/30 olarak da girilebilir) her saniye o g�n servetine
 eklenecek para miktar�n� g�steren programd�r. C ile yaz�l�p C++ projesi olarak yeniden
 yaz�lm��t�r.
*/

int main() {
    using namespace std::chrono;

    float bakiyedenGunlukKalan = 4000 / 30;

    while (true) {
        auto currentTime = system_clock::now();
        auto timePoint = system_clock::to_time_t(currentTime);
        std::tm* myTime = new std::tm; // Bellek ayr�tma
        localtime_s(myTime, &timePoint);

        int suAndakiSaniye = myTime->tm_hour * 60 * 60 + myTime->tm_min * 60 + myTime->tm_sec;
        std::cout << suAndakiSaniye * bakiyedenGunlukKalan / 86400 << '\r' << std::flush;

        delete myTime; // Bellek serbest b�rakma
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
