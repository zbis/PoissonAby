/*
 * PoissonAby a peur du noir. Heureusement, il a une petite lumière au bout de son antenne, ce qui est pratique, tout au fond de la mer.
 * 
 * Créé par Tatiana Grange, pour zBis, sous licence CC-BY-SA 4.0
 */

/********** Constantes **********/
// Les constantes sont comme des bouts de papier sur lesquels on écrit un mot ou un chiffre au feutre pour le retenir
// Le feutre ne peut-être effacé, la constante ne peut être modifiée.

const int led = 3;                // La constante "led" sera utilisée dans le code pour parler du pin où est branchée la led
const int seuil = 500;            // La constante "seuil" sera utilisée dans le code pour définir si le poisson doit ou non allumer sa lanterne
                                  // N'hésite pas à changer cette valeur en fonction de la lumière dans la pièce !
const int pinCapteurLumiere = 0;  // La constante "pinCapteurLumiere" sera utilisée dans le code pour parler du pin où est branché la le capteur lumière
                                  // Attention, on branche la photorésistance sur A0 et non 0 !!


/********** Variables **********/
// Les variables sont comme des bouts de papier sur lesquels on écrit au crayon à papier. 
// On peut remplacer le contenu de la variable en gommant et en écrivant la nouvelle valeur au crayon à papier
int valeurCapteurLumiere = 0;



/********** Fonctions **********/

// La fonction setup est la toute première exécutée par la carte Arduino.
void setup(void) {
  Serial.begin(9600);     // Utile pour trouver les bugs, Serial permet d'écrire dans le moniteur Série. 
                          // Ici, on écrira sur le canal 9600.
  pinMode(led,OUTPUT);    //Avec cette ligne, on précise que la led est branché en sortie (pour envoyer des données)
}

//La fonction loop est appelée en boucle par la carte Arduino
void loop(void) {
  valeurCapteurLumiere = analogRead(pinCapteurLumiere);   // À l'aide du capteur, on mesure la quantité de lumière autour du poisson et on la garde dans la variable "valeurCapteurLumiere"

  //Début du retour sur le moniteur série
  Serial.print("Valeur de la lumière = ");
  Serial.println(valeurCapteurLumiere);
  //Fin du retour sur le moniteur série
  
 
  if (valeurCapteurLumiere < seuil) {         // Est-ce qu'il fait trop sombre pour le poisson ?
    // OUI il n'y a pas assez de lumière !
    Serial.println("Pas assez de lumière");
    
    analogWrite(led,map(valeurCapteurLumiere, 10, seuil, 255, 0));    // Grâce à cette ligne, le poisson fait varier sa lanterne en fonction de la luminosité autour de lui.
    
  } else{
    // NON il y a assez de lumière !
    Serial.println("Assez de lumière");
    analogWrite(led,0);                                                // Le poisson éteind sa lumière
  }
  
  delay(50);
}
