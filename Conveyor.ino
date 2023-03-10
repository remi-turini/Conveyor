// Inclure vos librairies les bibliothèques dans la section correspondante
    // Général : 
    
    // ServoMoteur :
  
    // Moteur pas à pas :
  
    // Serveur et communication :


// Initaliser et déclarer vos composants dans cette section

    
// Déclarer ici les variables générales 
  String NFCTag;      
  char Address;
// Sauf exception, toutes les constantes sont censées être déclarées dans vos bibliothèques
#define STEP 5      // Nombre de pas que fera le moteur par boucle. A modifier selon le besoin

  
void setup() {
  // Il faudra initialiser les bibliothèques ici
      // boucle wifi connection
}

void loop() {
  // Ne rien modifier ici, commentez seulement les fonctions qui sont inutiles pour vos tests
  while(NFCtag==null){
    Motor.Forward(STEP);
    NFCtag = NFCReader.ReadNFCTag();
  }
  Adress = DolibarServer.AskDestination(NFCtag); // boucle tant que pas de rep ou mauvaise rep
  delay(200);
  Switcher.SetConveyor(Adress);
  delay(200);
  
  NFCtag = null;
}
