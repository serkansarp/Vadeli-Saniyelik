#include <stdio.h>
#include <stdlib.h> 
#include <time.h>        

/*
VADELİ SANİYELİK

- Serkan Sarp tarafından C ile kodlanmıştır.
- Vadeli TL mevduatı olanlar için günlük mevduatlarının saniye saniye ne kadar çoğaldığını gösterir
- Bu tür kodları Excel üzerinde yazarken online Ide'lere C ile geçirme fikrini 2019'da almıştım, Gwbasic ile 20-30 sene öncesine dayanan bir geçmişim de mevcuttur.
- Kodlamaya tekrar başlamamın nedeni olan koddur.
- Amaç, bunu bana bir köşede gün boyu gösterebilen bir kod yazabilecek olup olmadığımı görmemdir.
- Excel fonksiyonu sürekli yenileme istiyordu, kendi kendine ekran yenileme yapabilecek bir kod gerekiyordu ve ben C ile başından tekrar öğrenmeliydim.
- Zaman zaman aklıma bunun gibi şeyler yapıp yapamayacağım sürekli geliyordu. Artık yapmam gerekiyordu diye düşündüm.
*/


int main() {
	
	time_t currentTime;
	    
    int suAndakiSaniye;
    float bakiyedenGunlukKalan=4000/30; // toplamGetiri / gün şeklinde yazılabileceği gibi günlükGetiri şeklinde de yazılabilir
    
    for(;;) // Sonsuz döngü
		{
	time(&currentTime);
	struct tm *myTime = localtime(&currentTime);
	suAndakiSaniye=myTime->tm_hour*60*60 + myTime->tm_min*60 + myTime->tm_sec;
		printf("%.4f\r",suAndakiSaniye * bakiyedenGunlukKalan / 86400); // 86400 = Bir Gündeki Saniye Sayısıdır
		}
return 0;
}