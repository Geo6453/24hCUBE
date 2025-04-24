// bibliothèque pour le json (https://arduinojson.org/)
#include <ArduinoJson.h>

// bibliothèque permettant le wifi et des connexions à des serveurs
#include <WiFi.h>

// réseau Wifi sur lequel se connecter
const char* ssid = "AP-NSI-NG";
const char* password = "mdpwifinsing";
// Adresse IP et port du serveur
const char* ipServeur = "192.168.1.XXX";
const unsigned int portServeur = 1665;

// objet client qui permet de se connecter au serveur Vectorun
NetworkClient client;

void setup(void) {
  Serial.begin(9600);
  delay(10);

  // Tentative de connexion au réseau Wifi (SSID et Pass en haut du fichier l8-9)
  Serial.print("Connexion au wifi : ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // tant que l'on n'est pas connecté, on ne va pas plus loin
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  String Wifi = String("ssid : ") + String(ssid);
  String ip = String ("IP:") + WiFi.localIP().toString();
  Serial.print("Connexion etablie ! Adresse IP : ");
  Serial.println(WiFi.localIP());
  
  // tentative de connexion au serveur Vectorun (@ip et port à modifier en haut du fichier l11-12)
  Serial.print("Connexion au serveur : ");
  Serial.print(ipServeur);
  Serial.print(" : ");
  Serial.print(portServeur);

  if (!client.connect(ipServeur, portServeur))
  {
    Serial.print("La connexion a échouee, vérifiez l'adresse ou le port du serveur ...");
    // pas de connexion, le programme s'arrête ici ...
    while(1);
  }
  
  Serial.println("La NSIN Deck Oled est connectée au serveur Vectorun !");

  Serial.println("Envoi de YOPYOP:0");
  JsonDocument message;

  message["type"] = "YOPYOP";
  message["payload"] = O;

  // construction et envoi du message
  serializeJson(message, client);
}
 
void loop(void)
{
  // envoi de messages vers le serveur :
  if (Serial.available() > 0)
  {
    // on récupère le message tapé (par exemple "PLAY:[1,0]")
    String envoi = Serial.readStringUntil('\n');
    // on le découpe pour récupérer le type et la payload
    int index = envoi.indexOf(':');
    if (index != -1)
    {
      String typ = envoi.substring(0,index);
      String payload = envoi.substring(index+1);
      // On fabrique le message JSON correspondant :
      JsonDocument message;
      message["type"] = typ;
      message["payload"] = payload;
      // construction et envoi du message
      serializeJson(message, client);
    }
    else
      Serial.print("Le message à envoyer devrait ressembler à \"TYPE:payload\"");
    
  }

  // réception de messages provenant du serveur :
  if (client.available() > 0)
  {
    // Lire et ignorer les 4 premiers octets
    for (int i = 0; i < 4; i++) {
      if (client.available()) client.read();
    }
    StaticJsonDocument<200> message;
    DeserializationError error = deserializeJson(message, client);
    if (error) {
      Serial.print("Erreur JSON: ");
      Serial.println(error.c_str());
      return;
    }
    const char* typ = message["type"];
    const char* payload = message["payload"];
    Serial.println("Message reçu !");
    Serial.print("Type: ");
    Serial.println(typ);
    Serial.print("Payload: ");
    Serial.println(payload);
  }
}
