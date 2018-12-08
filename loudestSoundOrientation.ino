
/*
 * Formaal: finne retningen (vinkel) til den høyeste lydkilden
 * 2 keyes mikrofoner og 1 Arduino Uno
 */
//#include <vector>
//Avansert psedokode:
//optimaliserer for 440 Hz: low-pass-filter for å sile ut støy i begge input fra høytalerne
//Bruk FFT + convolution for å finne retning på lyden. 
//Fjerne konstant-leddet i kosinus DFT.

//Første iterasjon:
//Finn høyeste amplitude fra snitt-verdi i de to høytalerne separat
//beregn ca periode rundt 440 Hz, muligens ned i 220 Hz = 2 ganger perioden til 440 Hz
//sammenlign avstand mellom i tid mellom de to maks-utslagene.
//Beregn avstand ved vektor-differanse i tidsdifferansen.

#define sizeCollections 1000
int microphone1Pin = A1;
int mic1;
int collectMic1[sizeCollections];

int microphone2Pin = A2;
int mic2;

int collectMic2[sizeCollections];
int i =0;
int max1Index=0;
int max2Index=0;
int max1=0;
int max2=0;
int sum1=0;
int sum2=0;

//int minstFrekvens = 220; //Hz
//int collectionTime =  1/minstFrekvens*1000; //ms
unsigned long oldTime;

void setup() {
  //pinMode(microphone1Pin, INPUT);
  Serial.begin(9600);
  oldTime = millis();
}

void loop() {
  if(i>=sizeCollections){
    int mean1 = sum1/sizeCollections;
    int mean2 = sum2/sizeCollections;

    //Finn avstand mellom max-indeksene.
    //beregn vinkelen til lydkilden
    
    clear();
    oldTime = millis();
  }
  
  mic1 = analogRead(microphone1Pin);
  Serial.println(mic1,2);
  sum1 +=mic1;
  if(max1>mic1){
    max1Index = i;
  }
  
  mic2 = analogRead(microphone2Pin);
  sum2 += mic2;
  if(max1>mic1){
    max1Index = i;
  }
  Serial.println(mic2,2);

  i++; 
}

void clear(){
  max1Index = 0;
  max2Index = 0;
  max1 = 0;
  max2 = 0;
  sum1 = 0;
  sum2 = 0;
  i = 0;
}
